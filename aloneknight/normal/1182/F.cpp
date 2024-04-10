#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000ll;
ll a,b,p,q;
ll sol(ll n,ll a,ll b,ll c)
{
	if(n<0)return 0;if(!n)return b/c;
	if(a>=c||b>=c)return sol(n,a%c,b%c,c)+n*(n+1)/2*(a/c)+(n+1)*(b/c);
	ll m=(a*n+b)/c;return m*n-sol(m-1,c,c-b-1,a);
}
void exgcd(ll a,ll b,ll&x,ll&y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=a/b*x;}
ll gt(ll p,ll q,ll t)
{
	ll g=__gcd(p,q),x,y;if(t%g)return inf;
	p/=g;q/=g;t/=g;exgcd(p,q,x,y);x*=t;x+=(a-x)/q*q;
	while(x>=a)x-=q;while(x<a)x+=q;return x;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&p,&q);p*=2;q*=2;
		ll l=0,w=q/2,r=w;
		while(l<r)
		{
			ll mid=l+r>>1,L=w-mid,R=w+mid;
			if(sol(b,p,q-L,q)-sol(a-1,p,q-L,q)-sol(b,p,q-R-1,q)+sol(a-1,p,q-R-1,q))r=mid;else l=mid+1;
		}
		printf("%d\n",min(gt(p,q,w-l),gt(p,q,w+l)));
	}
	return 0;
}