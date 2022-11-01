#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

int main()
{
	int n;
	scanf("%d",&n);
	LL a=0,b=0;
	for (int i=1;i<=n;i++)
	{
		LL x,y;scanf("%lld%lld",&x,&y);
		a+=x;b+=y;
	}
	for (int i=1;i<=n;i++)
	{
		LL x,y;scanf("%lld%lld",&x,&y);
		a+=x;b+=y;
	}
	printf("%lld %lld\n",a/n,b/n);
	return 0;
}