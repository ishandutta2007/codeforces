#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int x,y;scanf("%d%d",&x,&y);
		if ((x+y)%2==0)
		{
			LL ans=(LL)(x-1)/2*(n/2+(n+1)/2);
			if (x%2==0) ans+=(LL)(n+1)/2;
			ans+=(LL)(y+1)/2;
			printf("%lld\n",ans);
		}
		else
		{
			LL ans=(LL)((LL)n*n+1)/2+(LL)(x-1)/2*(n/2+(n+1)/2);
			if (x%2==0) ans+=(LL)n/2;
			ans+=(LL)(y+1)/2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}