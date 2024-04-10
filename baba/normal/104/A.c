#include<stdio.h>


int main()
{
	int n;
	scanf("%d",&n);

	if(0<=n && n<=10)
		printf("0\n");
	else if(11<=n && n<=19 || n==21)
		printf("4\n");
	else if(n==20)
		printf("15\n");
	else printf("0\n");

	return 0;
}