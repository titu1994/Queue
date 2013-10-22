/*
 ============================================================================
 Name        : Queue.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

/*
 * Implementations of various Queue types
 */

// Type 1 : Ordinary Array Implementation

typedef struct ArrayQueue{
	int a[SIZE];
	int front, rear;
} ArrayQueue;

// Type 2 : Enhanced Circular Array Implementation

typedef struct CircularArrayQueue{
	int a[SIZE];
	int front, rear, count;
} CircularArrayQueue;

// Basic Linked List is required for Linked List representations of Queue

typedef struct Node{
	int data;
	struct Node *next;
} Node;

// Type 3 : Ordinary Linked List Implementation

typedef struct LinkedListQueue{
	Node *front, *rear;
} LinkedListQueue;

// Method Declarations

void insertArrayQueue(ArrayQueue *p, int v);
int deleteArrayQueue(ArrayQueue *p);
void displayArrayQueue(ArrayQueue t);

void insertCircularArrayQueue(ArrayQueue *p, int v);
int deleteCircularArrayQueue(ArrayQueue *p);

void insertEnhancedCircularArrayQueue(CircularArrayQueue *p, int v);
int deleteEnhancedCircularArrayQueue(CircularArrayQueue *p);
void displayEnhancedCircularArrayQueue(CircularArrayQueue t);

void insertLinkedListQueue(LinkedListQueue *p, int v);
int deleteLinledListQueue(LinkedListQueue *p);
void displayLinkedListQueue(LinkedListQueue t);
void insertLinkedListDeQueue(LinkedListQueue *p, int v);
int deleteLinkedListDequeue(LinkedListQueue *p);

int main(void) {
	ArrayQueue aq,caq;
	CircularArrayQueue ecaq;
	LinkedListQueue lq;

	int choice, ele;

	setbuf(stdout, NULL);

	// Initialisation of the respective queues
	aq.front = aq.rear = -1;
	caq.front = caq.rear = -1;

	ecaq.count = 0;
	ecaq.front = ecaq.rear = -1;

	lq.front = lq.rear = NULL;

	printf("Enter choice : \n1 to insert to Array Queue\n2 to delete from Array Queue\n3 to display Array Queue\n4 for insert to Circular Array Queue\n5 for delete from Circular Array Queue\n6 for display Circular Array Queue\n7 for insert to Enhanced Circular Array Queue\n8 for delete from Enhanced Cicrular Array Queue\n9 for display Enhanced Circular Array Queue\n10 for insert to Linked List Queue\n11 to delete from Linked List Queue\n12 for displaying Linked List Queue\n13 for Deque Insert from end\n14 for Deque delete from rear\n");

	do{
		printf("Enter Choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter an element : ");
			scanf("%d", &ele);

			insertArrayQueue(&aq, ele);

			break;
		case 2:

			ele = deleteArrayQueue(&aq);
			printf("%d\n",ele);

			break;
		case 3:

			displayArrayQueue(aq);

			break;
		case 4:
			printf("Enter an element : ");
			scanf("%d", &ele);

			insertCircularArrayQueue(&caq, ele);

			break;
		case 5:

			ele = deleteCircularArrayQueue(&caq);
			printf("%d\n",ele);

			break;

		case 6:

			displayArrayQueue(aq);

			break;
		case 7:
			printf("Enter an element : ");
			scanf("%d", &ele);

			insertEnhancedCircularArrayQueue(&ecaq, ele);

			break;
		case 8:

			ele = deleteEnhancedCircularArrayQueue(&ecaq);
			printf("%d\n",ele);

			break;
		case 9:

			displayEnhancedCircularArrayQueue(ecaq);

			break;
		case 10:
			printf("Enter an element : ");
			scanf("%d", &ele);

			insertLinkedListQueue(&lq, ele);

			break;
		case 11:

			ele = deleteLinledListQueue(&lq);
			printf("%d\n",ele);

			break;
		case 12:

			displayLinkedListQueue(lq);

			break;
		case 13:
			printf("Enter an element : ");
			scanf("%d", &ele);

			insertLinkedListDeQueue(&lq, ele);


			break;
		case 14:

			ele = deleteLinledListDeQueue(&lq);
			printf("%d\n",ele);

		       break;
		default:
			break;
		}

	}while(choice != -1);

	return EXIT_SUCCESS;
}

/*
 * Ordinary Array implementation of Queue
 */

void insertArrayQueue(ArrayQueue *p, int v){

	if(p->rear == SIZE-1){
		printf("No more space in Queue\n");
	}
	else{
		p->rear++;
		p->a[p->rear] = v;
	}

}

int deleteArrayQueue(ArrayQueue *p){

	if(p->rear == p->front){
		printf("Queue is empty\n");
		return -1;
	}
	else{
		p->front++;
		return p->a[p->front];
	}

}

void displayArrayQueue(ArrayQueue t){

	while(t.rear != t.front){
		printf("%d\t",deleteArrayQueue(&t));

	}

	printf("\n");
}

/*
 * Circular Array Implementation of Queue which loses one available space
 *
 * Uses same ArrayQueue type, hence considered as just more advanced
 */

void insertCircularArrayQueue(ArrayQueue *p, int v){

	if((p->rear + 1) % SIZE == p->front){
		printf("Queue is full\n");
	}
	else{
		p->rear = (p->rear + 1) % SIZE;
		p->a[p->rear] = v;
	}
}

int deleteCircularArrayQueue(ArrayQueue *p){

	if(p->rear == p->front){
		printf("Stack is empty\n");
		return -1;
	}
	else{
		p->front = (p->front + 1) % SIZE;
		return p->a[p->front];
	}
}

/*
 * The display function remains the same for both
 */

/*
 * Enhanced Circular Array Implementation of Queue without loosing one space in list
 *
 * NOTE : This is using [Type 2 Array Implementation of Queue]
 */

void insertEnhancedCircularArrayQueue(CircularArrayQueue *p, int v){

	if(p->count == SIZE){
		printf("Queue is full\n");
	}
	else{
		p->count++;
		p->rear = (p->rear + 1) % SIZE;
		p->a[p->rear] = v;
	}

}

int deleteEnhancedCircularArrayQueue(CircularArrayQueue *p){

	if(p->count == 0){
		printf("Stack is empty\n");
		return -1;
	}
	else{
		p->count--;
		p->front = (p->front + 1) % SIZE;
		return p->a[p->front];
	}
}

void displayEnhancedCircularArrayQueue(CircularArrayQueue t){

	while(t.count != 0){
		printf("%d\t", deleteEnhancedCircularArrayQueue(&t));
	}

	printf("\n");
}

/*
 * Ordinary Linked List Implementation of Queue
 */

void insertLinkedListQueue(LinkedListQueue *p, int v){

	Node *newNode = NULL;
	newNode = (Node*) calloc(1, sizeof(Node));

	newNode->data = v;

	if(p->rear == NULL){
		p->rear = newNode;
		p->front = newNode;
	}
	else{
		p->rear->next = newNode;
		p->rear = newNode;
	}

}

void insertLinkedListDeQueue(LinkedListQueue *p, int v){

	Node *newNode = NULL;
	newNode = (Node*) calloc(1, sizeof(Node));

	newNode->data = v;

	if(p->rear == NULL){
		p->rear = newNode;
		p->front = newNode;
	}
	else{
		newNode->next = p->front;
		p->front = newNode;

	}

}

int deleteLinkedListQueue(LinkedListQueue *p){

	if(p->front == NULL){
		return -1;
	}
	else{
		int v = p->front->data;

		Node *temp = p->front;
		p->front = p->front->next;

		if(p->front == NULL){
			p->rear = NULL;
		}

		free(temp);

		return v;
	}
}

int deleteLinkedListDeQueue(LinkedListQueue *p){

	if(p->front == NULL){
		return -1;
	}
	else{
		int v = p->rear->data;
		
		Node *t = p->rear;
		Node temp = p->rear,previous;
		
		while(temp.front != NULL){
			previous = temp;
			
			t.front = t.front->next;
		}
		
		p->rear = previous;

		free(t);

		return v;
	}
}



void displayLinkedListQueue(LinkedListQueue t){

	while(t.front != NULL){

		printf("%d\t", deleteLinledListQueue(&t));

	}

}



