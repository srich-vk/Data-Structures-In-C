/**
 * @file priority_queue.c
 * @author Sricharan
 * @brief Implementation of Priority Queue data structure using Linked lists in C
 * Priority Queue: The elements of the array are ordered always, with the greatest element at the top.
 * Functions associated with a priority queue are
 * 1.Push: Insert a new element into the queue at the appropriate place
 * 2.Pop: Remove the topmost element of the stack. Also return it.
 * 3.Top: Displays the topmost element of the stack
 * @version 1
 * @date 2024-12-12
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct pq_node{
    int value;
    struct pq_node* next;
} pq_node;

typedef pq_node* priority_queue;

void printQueue(priority_queue pq){
    while(pq != NULL){
        printf("%d ",pq->value);
        pq = pq->next;
    }
    printf("\n");
}

void push(priority_queue* pq, int val){
    priority_queue new_node = (priority_queue)malloc(sizeof(pq_node));
    new_node->value = val;
    
    if ((*pq) == NULL || (*pq)->value < val){
        new_node->next = (*pq);
        *pq = new_node;
    } else {
        priority_queue curr = (*pq);
        while(curr->next != NULL && curr->next->value > val){
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

int pop(priority_queue* pq){
    int n = (*pq)->value;
    (*pq) = (*pq)->next;
    return n;
}

int top(priority_queue pq){
    return pq->value;
}

int main(){
    priority_queue pq = NULL;
    int k, n;
    scanf("%d\n",&k);
    for(int i = 0; i < k; i++){
        scanf("%d", &n);
        push(&pq, n);
    }
    printQueue(pq);

    printf("Popped: %d\n",pop(&pq));
    printQueue(pq);
}

