#include <stdio.h>

char str[10];

int main()
{
	int n;
	scanf("%d of %s", &n, str);
	if(str[0]=='w')
	{
		if(n==5||n==6)
			printf("53");
		else
			printf("52");
	}
	else
	{
		if(n<=29)
			printf("12");
		else if(n==30)
			printf("11");
		else if(n==31)
			printf("7");
	}
	return 0;
}