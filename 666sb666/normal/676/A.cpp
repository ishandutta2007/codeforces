#include<cstdio>
int max(int a,int b)
{
	return a>b?a:b;
}
int n,p,q,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1)p=i;
		if(x==n)q=i;
	}
	printf("%d\n",max(max(max(p-1,q-1),n-p),n-q));
	return 0;
}