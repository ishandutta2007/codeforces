#include<cstdio>
int n;
int main()
{
	scanf("%d",&n);
	if(n==1)puts("-1");
	else printf("%d %d %d",n,n+1,n*(n+1));
	return 0;
}