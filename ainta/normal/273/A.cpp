#include<stdio.h>
int w[100010],i,n,a,b,m;
__int64 H;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(H<(__int64)w[a])H=(__int64)w[a];
		printf("%I64d\n",H);
		H+=(__int64)b;
	}
}