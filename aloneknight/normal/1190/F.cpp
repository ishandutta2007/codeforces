#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
const int Pr[]={2,3,5,7,11,13,31};
int cc;ll n,m,b,p,e,pr[63];
map<ll,ll>mp;vector<ll>ans;
inline ll mul(ll a,ll b,ll m){ll t=a*b-(ll)((ld)a*(ld)b/(ld)m+0.5)*m;if(t>=m)t-=m;if(t<0)t+=m;return t;}
inline ll pw(ll a,ll b,ll m){ll r=1;for(;b;b>>=1,a=mul(a,a,m))if(b&1)r=mul(r,a,m);return r;}
inline bool MR(ll n)//miller_rabin
{
	for(int i=0;i<7;i++)if(n==Pr[i])return 1;
	if(!(n&1))return 0;
	ll r=n-1;int k=0;
	while(!(r&1))r>>=1,k++;
	for(int i=0;i<7;i++)
	{
		ll x=pw(Pr[i],r,n),y;
		for(int i=0;i<k;i++,x=y)
		{
			y=mul(x,x,n);
			if(y==1&&x!=1&&x!=n-1)return 0;
		}
		if(y!=1)return 0;
	}
	return 1;
}
#define F(x) mul(x,x,n)+1
inline ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
inline ll div(ll n)
{
	ll x=rand()%n+1,y=F(x);ll k=1;int tst=0;
	while(x!=y)
	{
		ll t=k;k=mul(k,abs(y-x),n);
		if(!k){t=gcd(t,n);return t;}
		if(tst==50){tst=0;t=gcd(k,n);if(t>1)return t;}
		x=F(x);y=F(F(y));tst++;
	}
	ll t=gcd(k,n);if(t>1)return t;
	return -1;
}
void PR(ll n)//pollard_rho
{
	if(n==1)return;
	if(MR(n)){pr[++cc]=n;return;}
	ll x;do x=div(n);while(x==-1);
	PR(x);PR(n/x);
}
vector<ll>fac(ll n)
{
	vector<ll>V;V.clear();if(n==1)return V;
	while(!(n&1))pr[++cc]=2,n>>=1;
	PR(n);for(int i=1;i<=cc;i++)V.pb(pr[i]);return V;
}
inline void facm()
{
	for(ll t=2;t*t*t<=m;t++)if(!(m%t)){p=t;e=0;ll v=m;while(v>1)v/=p,e++;return;}
	ll t=sqrt(m);for(ll i=max(0ll,t-10);i<=t+10;i++)if(i*i==m){p=i;e=2;return;}p=m;e=1;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&b);facm();
	vector<ll>F=fac(p-1);for(auto t:F)mp[t]++;if(e>1)mp[p]+=e-1;
	if(b%p==0)b=1;ll phi=m/p*(p-1),ord=phi;
	for(auto t:mp)while(!(ord%t.X)&&pw(b,ord/t.X,m)==1)ord/=t.X;
	if(phi-ord>=n)
	{
		ll cnt=0;
		while(ans.size()<n)
		{
			ll v=cnt++;if(!(v%p))continue;
			if(pw(v,ord,m)!=1)ans.pb(v);
			else if(p==2&&e>=3){if(ord>=2&&pw(v,ord/2,m)==1){if(v%8!=1)ans.pb(v);}else{if(v%8!=b%8)ans.pb(v);}}
		}
		for(auto t:ans)printf("%lld ",t);
	}
	else puts("-1");
	return 0;
}