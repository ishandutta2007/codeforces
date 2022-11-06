#include <stdio.h>

bool chk[101];

int main()
{
	int a,t,n,i;
	scanf("%d",&n);
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&t);
		chk[t]=1;
	}
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&t);
		chk[t]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!chk[i])
		{
			printf("Oh, my keyboard!");
			return 0;
		}
	}
	printf("I become the guy.");
	return 0;
}