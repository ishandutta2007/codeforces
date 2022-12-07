#include<cstdio>

int main()
{
	int x;
	scanf("%d",&x);
	int t=x%10;
	if (t<=5) printf("%d ",x-t);
	else printf("%d ",x-t+10);
	return 0;
}