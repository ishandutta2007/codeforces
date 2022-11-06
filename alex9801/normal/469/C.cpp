#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	if(n<4)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if(n==4)
	{
		printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24");
		return 0;
	}
	if(n==5)
	{
		printf("1 * 2 = 2\n3 + 5 = 8\n8 - 2 = 6\n4 * 6 = 24");
		return 0;
	}
	printf("2 * 3 = 6\n6 * 4 = 24\n6 - 5 = 1\n1 - 1 = 0\n");
	for(i=7;i<=n;i++)
		printf("0 * %d = 0\n",i);
	printf("24 + 0 = 24");
	return 0;
}