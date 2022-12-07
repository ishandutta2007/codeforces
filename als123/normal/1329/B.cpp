#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=50;
LL f[N];
LL bin[N];
int main()
{
	bin[0]=1;for (LL u=1;u<=30;u++) bin[u]=bin[u-1]<<1;
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		LL d,m,ans=0;
		scanf("%lld%lld",&d,&m);
		for (LL u=1;bin[u-1]<=d;u++)
		{
			//printf("%lld %lld %lld %lld\n",u,bin[u],bin[u+1],bin[u-1]);
			int t=1;
			if (bin[u]>d)	f[u]=(d-bin[u-1]+1)%m;
			else f[u]=bin[u-1]%m;
			for (LL i=1;i<u;i++) t=(t+f[i])%m;
			f[u]=f[u]*t%m;
			//printf("%lld\n",f[u]);
			ans=(ans+f[u])%m;
		}
		printf("%lld\n",ans);
	}
	return 0;
}