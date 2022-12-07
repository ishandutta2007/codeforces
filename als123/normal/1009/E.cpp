#include<cstdio>
#include<cstring>
#include<iostream>
typedef long long LL;
const LL MOD=998244353;
const LL N=1000005;
LL a[N],f[N];
LL sum=0,lalal=0;
int main()
{
	LL n;
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)
	{
		scanf("%lld",&a[u]);
		a[u]=(a[u]+a[u-1])%MOD;
	}
	for (LL u=n-1;u>=0;u--)
	{
		f[u]=sum;
		LL k=n-u;
		lalal=lalal-a[k-1];lalal=lalal*2%MOD;
		lalal=lalal+a[k-1]+a[k];
		(lalal=lalal%MOD+MOD)%MOD;
		f[u]=(f[u]+lalal)%MOD;
		sum=(sum+f[u])%MOD;
	}
	printf("%lld",f[0]);
	return 0;
}