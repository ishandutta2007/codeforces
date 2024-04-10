#include<bits/stdc++.h>
typedef long long ll;
ll C3(ll n){return(n*1ll*(n-1)*(n-2))/6;}
ll gcd(ll x,ll y){for(ll r=y;r;r=x%y,x=y,y=r);return x;}
int n;
ll a[111111],b[111111],c[111111];
ll _abs(ll x){return x<0?-x:x;}
struct Func
{
	ll a,b,c;
	void divs()
	{
		if(a<0)a=-a,b=-b,c=-c;
		ll T=_abs(gcd(a,gcd(b,c)));
		if(T)a/=T,b/=T,c/=T;
		if(!a){if(b<0)b=-b,c=-c;}
	}
};
std::map<Func,int>cnt;
bool operator<(const Func&x,const Func&y)
{if(x.a^y.a)return x.a<y.a;if(x.b^y.b)return x.b<y.b;return x.c<y.c;}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)
		scanf("%lld%lld%lld",a+i,b+i,c+i);
	ll ans=0;
	for(i=2;i<=n;i++)
		for(ii=1;ii<i;ii++)
		{
			Func T=(Func)
			{b[i]*c[i]*(a[ii]*a[ii]+b[ii]*b[ii])-b[ii]*c[ii]*(a[i]*a[i]+b[i]*b[i]),
			a[ii]*c[ii]*(a[i]*a[i]+b[i]*b[i])-a[i]*c[i]*(a[ii]*a[ii]+b[ii]*b[ii]),
			(a[ii]*b[i]-a[i]*b[ii])*c[i]*c[ii]};
			T.divs(),cnt[T]++;
		}
	for(auto&g:cnt)ans+=C3(sqrt(g.second*2)+1);
	printf("%lld\n",ans);
}