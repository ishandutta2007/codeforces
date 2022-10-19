#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,k,sum=0;
LL ans=0;
LL fac[200002],inv[200002];
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
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n]=Pow(fac[n],mod-2);for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
int main()
{
	scanf("%d%d",&n,&k),init();
	for(int i=1,x;i<=n;++i)scanf("%d",&x),sum=(sum+x)%mod;
	if(n==1)return 0&printf("%d",sum);
	for(int i=0;i<k;++i)ans=(ans+(((((i&1? -1:1)*Pow(k-i,n-2)*(k-i+n-1))%mod)*inv[i])%mod)*inv[k-i-1])%mod;
	return 0&printf("%lld",(((ans*sum)%mod)+mod)%mod);
}