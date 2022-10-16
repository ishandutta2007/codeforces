#include<cstdio>
typedef long long ll;
int a[111111],n;
const ll mod=1e9+7;
ll u[111111],t[111111];
int fg[111111];
inline ll qpow(ll x,ll k)
{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",a+i),t[a[i]]++;
	for(i=1;i<=1e5;i++)
		for(ii=i*2;ii<=1e5;ii+=i)
			t[i]+=t[ii];
	u[1]=1;
	for(i=2;i<=1e5;i++)
	{
		if(!fg[i])
		{
			u[i]=mod-1;
			for(ii=i;ii<=1e5/i;ii++)
				if(!fg[i*ii])fg[i*ii]=ii;
		}else u[i]=(u[i/fg[i]]*u[fg[i]])%mod;
	}
	for(i=2;i<=1e3;i++)
		for(ii=1;ii*i*i<=1e5;ii++)
			u[i*i*ii]=0;
	ll ans=0;
	for(i=1;i<=1e5;i++)
		(ans+=u[i]*(qpow(2,t[i])+mod-1))%=mod;
	printf("%lld\n",ans);
}