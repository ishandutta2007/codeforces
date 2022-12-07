#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		LL n,m,ans=0;
		scanf("%lld%lld",&n,&m);
		for (LL x=1;x*x<=n;x++)
		{
			LL l=x+1,r=min(m,n/x-1);
			ans=ans+max(0LL,r-l+1);
		}
		printf("%lld\n",ans);
		/*for (LL u=1;u<=n;u++)
		for (LL i=1;i<=m;i++)
		if (u/i==(u%i)) 
		{
		printf("%lld %lld %lld\n",u,i,u/i);
			ans++;
		}
		printf("%lld\n",ans);*/
	}
	return 0;
}