#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=801*1000;
const ll K=32;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);


ll t,num=1;
vector <ll> lft,rght,sz;

void add(ll x)
{
	ll id=1;
	for(ll p=K-1;p>=0;p--)
	{
		sz[id]++;
		if((x&(1LL<<p)))
		{
			if(rght[id]==-1)rght[id]=++num,rght.push_back(-1),lft.push_back(-1),sz.push_back(0);
			id=rght[id];
		}
		else 
		{
			if(lft[id]==-1)lft[id]=++num,rght.push_back(-1),lft.push_back(-1),sz.push_back(0);
			id=lft[id];
		}
	}
	sz[id]++;
}

void remove(ll x)
{
	ll id=1;
	for(ll p=K-1;p>=0;p--)
	{
		sz[id]--;
		if((x&(1LL<<p)))
			id=rght[id];
		else 
			id=lft[id];
	}
	sz[id]--;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	lft.push_back(-1);lft.push_back(-1);
	rght.push_back(-1);rght.push_back(-1);
	sz.push_back(-1);sz.push_back(0);
	add(0);
	while(t--)
	{
		char c;
		ll x;
		cin>>c>>x;
		if(c=='+')
			add(x);
		if(c=='-')
			remove(x);
		if(c=='?')
		{
			ll res=0;
			for(ll id=1,p=K-1;p>=0;p--)
			{
				if((x&(1LL<<p)))
				{
					if(lft[id]!=-1 && sz[lft[id]]>0)
					{
						res+=(1LL<<p);
						id=lft[id];
		//				cout<<"left1"<<"\n";
						continue;
					}
					id=rght[id];
		//		cout<<"right1"<<"\n";
				}
				else 
				{
					if(rght[id]!=-1 && sz[rght[id]]>0)
					{
						res+=(1LL<<p);
						id=rght[id];
		//				cout<<"right"<<"\n";
						continue;
					}
					id=lft[id];
		//			cout<<"left"<<"\n";
				}
			}
		    cout<<res<<"\n";
		}
	}
	return 0;
}