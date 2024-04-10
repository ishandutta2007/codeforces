#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e15)

ll n,a;
map <ll,ll> mp;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a,mp[a]++;
	for(map <ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(mp[it->first]>0 && mp[it->first+1]>0 && mp[it->first+2]>0)return cout<<"YES",0;
	}
	cout<<"NO";
	return 0;
}