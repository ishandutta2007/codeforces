#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL n,k;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&k);
		LL ans=0;
		while (n)
			if (n%k==0) n/=k,ans++;
			else ans+=n%k,n-=n%k;
		printf("%lld\n",ans);
	}
	return 0;
}