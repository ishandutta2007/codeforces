#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n;
LL ans=0;
char s[1000002];
int cnt[3],sum[3],to[202];
LL fac[1000002],inv[1000002];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n]=Pow(fac[n],mod-2);for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	if(a<b || b<0)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1),to['(']=0,to[')']=1,to['?']=2,init();
	for(int i=1;i<=n;++i)++sum[to[s[i]]];
	for(int i=1,l,r,x,y;i<=n;++i)++cnt[to[s[i]]],l=cnt[0],x=cnt[2],r=sum[1]-cnt[1],y=sum[2]-cnt[2],(ans+=C(x+y,y+r-l)*l+C(x-1+y,y+r-l-1)*x)%=mod;
	return 0&printf("%lld",ans);
}