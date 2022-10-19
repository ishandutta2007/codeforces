#include<bits/stdc++.h>
#define Mx 300000
#define LL long long
#define mod 998244353
using namespace std;
int n,sum=0;
LL ans;
int a[100002];
LL f[300002],fac[300002],inv[300002],g[300002];
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod,inv[i]=(inv[i]*fac[i-1])%mod;
}
int main()
{
	init(),scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
	g[0]=n-1;
	for(int i=1;i<sum;++i)g[i]=(((((((g[i-1]*i)%mod)*inv[sum]+1)%mod)*(n-1))%mod)*((inv[sum-i]*sum)%mod))%mod;
	for(int i=sum-1;~i;--i)f[i]=(f[i+1]+g[i])%mod;
	ans=(f[0]*(1-n))%mod;
	for(int i=1;i<=n;++i)ans=(ans+f[a[i]])%mod;
	return 0&printf("%lld",(((ans*Pow(n,mod-2))%mod)+mod)%mod);
}