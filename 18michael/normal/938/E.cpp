#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const LL mod=1000000007;
int n,t=1,tot=0;LL ans=0;
int a[1000002],num[1000002]={};
LL fac[1000002],inv[1000002];
inline bool cmp(int a,int b)
{
	return a<b? 1:0;
}
inline LL _pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=_pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d",&n),tot=n,fac[0]=num[1]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),fac[i]=(fac[i-1]*i)%mod;
	sort(a+1,a+n+1,cmp),inv[n]=_pow(fac[n],mod-2);
	for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
	for(int i=2;i<=n;++i)
	{
		if(a[i]!=a[t])a[++t]=a[i];
		++num[t];
	}
	for(int i=1,j;i<t;++i)ans=(ans+(((((((fac[n]*inv[tot])%mod)*fac[tot-1])%mod)*num[i])%mod)*a[i]))%mod,tot-=num[i];
	printf("%lld",ans);
	return 0;
}