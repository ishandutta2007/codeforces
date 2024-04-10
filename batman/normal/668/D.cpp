#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld double
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n;
map <ll,map<ll,ll> > mp;

void update(ll x,ll y,ll num){for(;x<(ll)1e9;x+=x&-x)mp[y][x]+=num;}
ll query(ll x,ll y){ll res=0;for(;x>0;x-=x&-x)res+=mp[y][x];return res;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--)
	{
		ll t,x,y;
		cin>>t>>x>>y;
		if(t==1)update(x,y,1);
		if(t==2)update(x,y,-1);
		if(t==3)cout<<query(x,y)<<"\n";
	}
  	return 0;
}