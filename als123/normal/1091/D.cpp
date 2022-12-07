#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const LL N=1000005;
LL f[N];
LL g[N];
LL n;
int main()
{
	scanf("%I64d",&n);
	f[0]=1;for (LL u=1;u<=n;u++) f[u]=f[u-1]*u%MOD;
	g[n]=1;for (LL u=n-1;u>=0;u--) g[u]=g[u+1]*(u+1)%MOD;
	LL ans=n*f[n]%MOD;
	for (LL u=1;u<n;u++) ans=(ans-g[u]+MOD)%MOD;
	printf("%I64d\n",ans);
	return 0;
}