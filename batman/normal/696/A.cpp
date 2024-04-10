#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)301*1000);
const ll INF=((ll)2e18);
const ll MOD=((ll)109+7);

ll q;
map <ll,ll> c;

ll lca(ll x,ll y)
{
	deque <ll> x1,y1;
	while(x)
	{
		x1.push_front(x%2);
		x/=2;
	}
	while(y)
	{
		y1.push_front(y%2);
		y/=2;
	}
	ll i=0,num=0;
	for(;i<min((ll)x1.size(),(ll)y1.size());i++)
	{
		if(x1[i]!=y1[i])
			return num;
		num*=2;num+=x1[i];
	}
	return num;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>q;
	while(q--)
	{
		ll t,x,y,w;
		cin>>t>>x>>y;
		if(t==1)
		{
			cin>>w;
			ll p=lca(x,y);
			//cout<<p<<"\n";
			while(x!=p)
			{
				//cout<<x<<" "<<w<<"\n";
				c[x]+=w;
				x/=2;
			}
			while(y!=p)
			{
				//cout<<y<<" "<<w<<"\n";
				c[y]+=w;
				y/=2;
			}
		}
		if(t==2)
		{
			ll p=lca(x,y),ans=0;
			while(x!=p)
			{
				ans+=c[x];
				x/=2;
			}
			while(y!=p)
			{
				ans+=c[y];
				y/=2;
			}
			cout<<ans<<"\n";
		}
	}
	
	
    return 0;
}