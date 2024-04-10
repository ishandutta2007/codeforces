#include <stdio.h>

int main()
{
	int n,k,t;
	scanf("%d%d%d",&n,&k,&t);
	if(t<=k) printf("%d\n",t);
	else if(t<=n) printf("%d\n",k);
	else printf("%d\n",k-t+n);
}