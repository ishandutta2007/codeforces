#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
typedef long long LL;
const int maxn = 200005;
const LL mod = 1e9+7;
const int N = 2e5;

LL fac[maxn],inc[maxn];
LL fpm(LL p,LL k=mod-2) {
	LL res=1ll;
	while (k) {
		if (k&1) (res*=p)%=mod;
		(p*=p)%=mod;k>>=1;
	}
	return res;
}
LL comb(int n,int m)
{
	return fac[n]*inc[m]%mod*inc[n-m]%mod;
}

int n,a[maxn];LL f[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("test.in","r",stdin);
		//freopen("test.out","w",stdout);
	#endif
	fac[0]=inc[0]=1ll;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mod;
	inc[N]=fpm(fac[N]);
	for (int i=N;i>=2;i--) inc[i-1]=inc[i]*i%mod;
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1) {printf("%d",a[1]);return 0;}
	int sig=1;
	while (n%4!=2) {
		n--;
		for (int i=1;i<=n;i++)
			a[i]=(a[i]+sig*a[i+1])%mod,sig*=-1;
	}
	int m=n/2-1;
	for (int i=0;i<=m;i++) {
		LL w=comb(m,i);f[2*i+1]=w;f[2*i+2]=sig*w;
	}
	LL ans=0;
	for (int i=1;i<=n;i++)
		(ans+=f[i]*a[i])%=mod;
	printf("%lld",ans<0?ans+mod:ans);
	return 0;
}