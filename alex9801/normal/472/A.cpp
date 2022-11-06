#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==0)
		printf("%d %d",4,n-4);
	else if(n%3==0)
		printf("%d %d",6,n-6);
	else if(n%3==1)
		printf("%d %d",4,n-4);
	else
		printf("%d %d",8,n-8);
	return 0;
}