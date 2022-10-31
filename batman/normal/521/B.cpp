#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+9);
const ll INF=((ll)2e9);
 
ll n,ans;
pair <ll,ll> a[N];
map <pair<ll,ll>,ll> mp;
set <ll> s;

bool check(ll p)
{
	ll x=a[p].first,y=a[p].second;
	if(mp[{x-1,y+1}]>0)
	{
		if(mp[{x-1,y}]==0 && mp[{x-2,y}]==0)return 0;
	}
	if(mp[{x,y+1}]>0)
	{
		if(mp[{x-1,y}]==0 && mp[{x+1,y}]==0)return 0;
	}
	if(mp[{x+1,y+1}]>0)
	{
		if(mp[{x+1,y}]==0 && mp[{x+2,y}]==0)return 0;
	}
	return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i].first>>a[i].second;
    	mp[{a[i].first,a[i].second}]=i;
	}
	for(int i=1;i<=n;i++)if(check(i))s.insert(i);
	//cout<<s.size()<<"\n";
	for(int i=n-1;i>=0;i--)
	{
		set <ll>::iterator it=s.end();it--;
		ll x=*it;s.erase(it);
		//cout<<"hir";
		ans+=tavan(n,i,MOD)*(x-1);ans%=MOD;
		//cout<<x<<" "<<i<<"\n";
		mp[{a[x].first,a[x].second}]=0;
		if(mp[{a[x].first-1,a[x].second-1}]>0 && check(mp[{a[x].first-1,a[x].second-1}]))s.insert(mp[{a[x].first-1,a[x].second-1}]);
		if(mp[{a[x].first,a[x].second-1}]>0 && check(mp[{a[x].first,a[x].second-1}]))s.insert(mp[{a[x].first,a[x].second-1}]);
		if(mp[{a[x].first+1,a[x].second-1}]>0 && check(mp[{a[x].first+1,a[x].second-1}]))s.insert(mp[{a[x].first+1,a[x].second-1}]);
		for(int j=a[x].first-2;j<=a[x].first+2;j++)
			if(mp[{j,a[x].second}]>0 && !check(mp[{j,a[x].second}]))
				s.erase(mp[{j,a[x].second}]);
		i--;
		if(i<0)break;
		x=*s.begin();s.erase(s.begin());
		ans+=tavan(n,i,MOD)*(x-1);ans%=MOD;
		//cout<<x<<" "<<i<<"\n";
		mp[{a[x].first,a[x].second}]=0;
		if(mp[{a[x].first-1,a[x].second-1}]>0 && check(mp[{a[x].first-1,a[x].second-1}]))s.insert(mp[{a[x].first-1,a[x].second-1}]);
		if(mp[{a[x].first,a[x].second-1}]>0 && check(mp[{a[x].first,a[x].second-1}]))s.insert(mp[{a[x].first,a[x].second-1}]);
		if(mp[{a[x].first+1,a[x].second-1}]>0 && check(mp[{a[x].first+1,a[x].second-1}]))s.insert(mp[{a[x].first+1,a[x].second-1}]);
		for(int j=a[x].first-2;j<=a[x].first+2;j++)
			if(mp[{j,a[x].second}]>0 && !check(mp[{j,a[x].second}]))
				s.erase(mp[{j,a[x].second}]);
		//cout<<"hir";
	}
	cout<<ans;
    return 0;
}