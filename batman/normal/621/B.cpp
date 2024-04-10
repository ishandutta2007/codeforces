#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,ans;
map <ll,ll> mp[2];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--)
	{
		ll x,y;
		cin>>x>>y;
		mp[0][x+y]++;
		mp[1][y-x]++;
	}
	for(map <ll,ll>::iterator it=mp[0].begin();it!=mp[0].end();it++)
		ans+=(it->second-1)*(it->second)/2;
	for(map <ll,ll>::iterator it=mp[1].begin();it!=mp[1].end();it++)
		ans+=(it->second-1)*(it->second)/2;	
	cout<<ans;	
    return 0;
}