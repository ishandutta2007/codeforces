#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,a[N],nex[N];
set <pair <ll,ll> > s;

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1){s.insert({a[1],1});continue;}
		set <pair<ll,ll> >::iterator it=s.lower_bound({a[i],0});
		if(it==s.begin()){cout<<it->first<<" ";s.insert({a[i],i});continue;}
		it--;
		if(nex[it->second]==0){cout<<it->first<<" ";nex[it->second]=i;s.insert({a[i],i});continue;}
		cout<<a[nex[it->second]]<<" ";nex[it->second]=i;s.insert({a[i],i});
	}
	return 0;
}