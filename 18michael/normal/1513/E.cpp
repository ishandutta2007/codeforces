#include<cstdio>
#include<algorithm>
#define LL long long
#define mod 1000000007
using namespace std;
int n,t,A=0,B=0,C=0,cnta_t=0,cntb_t=0;
LL ans,sum=0,avr;
int a[100002],cnta[100002],tima[100002]={},cntb[100002],timb[100002]={};
LL fac[100002],inv[100002];
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n]=pow(fac[n],mod-2);for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL _C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	scanf("%d",&n),init();
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
	if(sum%n)return 0&puts("0");avr=sum/n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		if(a[i]==avr)++C;
		else if(a[i]<avr)
		{
			++A;
			if(!cnta_t || a[cnta[cnta_t]]!=a[i])cnta[++cnta_t]=i,tima[cnta_t]=1;
			else ++tima[cnta_t];
		}
		else
		{
			++B;
			if(!cntb_t || a[cntb[cntb_t]]!=a[i])cntb[++cntb_t]=i,timb[cntb_t]=1;
			else ++timb[cntb_t];
		}
	}
	if(!A && !B)ans=1;
	else if(A==1 || B==1)
	{
		ans=_C(n,C),n-=C;
		for(int i=1;i<=cnta_t;++i)ans=(ans*_C(n,tima[i]))%mod,n-=tima[i];
		for(int i=1;i<=cntb_t;++i)ans=(ans*_C(n,timb[i]))%mod,n-=timb[i];
	}
	else
	{
		ans=(_C(n,C)<<1)%mod;
		for(int i=1;i<=cnta_t;++i)ans=(ans*_C(A,tima[i]))%mod,A-=tima[i];
		for(int i=1;i<=cntb_t;++i)ans=(ans*_C(B,timb[i]))%mod,B-=timb[i];
	}
	printf("%lld",ans);
	return 0;
}