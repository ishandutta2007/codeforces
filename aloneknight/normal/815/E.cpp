#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
ll gt(ll x,ll v)
{
	if(x<=v*2)return 0;
	ll s1=1,s2=0,p1=x,p2=x-1,ans=0;
	while(p2>=v*2)
	{
		if(p2==v*2)return s1+ans;else ans+=s1+s2;
		if(p1&1)s1=s1*2+s2;else s2=s2*2+s1;p1/=2;p2=p1-1;
	}
	return ans;
}
ll sol(ll l,ll r,ll p,ll k)
{
	ll m=l+r>>1;if(k==1)return m;ll t1=gt(m-l,p),t2=gt(r-m,p+1);
	return k>t1+t2+1?sol(m+1,r,p,k-t1-1):sol(l,m-1,p,k-t2-1);
}
int main()
{
	ll n,k;n=rd();k=rd();
	if(k<=2){printf("%lld\n",k==1?1:n);return 0;}
	n-=2;k-=2;ll l=0,r=n/2+1,m;
	while(l+1<r)if(gt(n,m=l+r>>1)<k)r=m;else l=m;
	printf("%lld\n",sol(1,n,l,k)+1);return 0;
}