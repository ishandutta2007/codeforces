#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =200;

ll n,m,a[N],ans;
map <string,ll> mp;
vector <ll> v;

int main() 
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)
	{
		string ex;
		cin>>ex;
		mp[ex]++;
	}
	for(map <string,ll>::iterator it=mp.begin();it!=mp.end();it++)
	{
		v.push_back(it->second);
	}
	sort(v.begin(),v.end());
	sort(a,a+n);
	for(int i=(ll)v.size()-1,j=0;i>=0;i--,j++)
	{
		ans+=v[i]*a[j];
	}
	cout<<ans<<" ";
	ans=0;
	for(int i=(ll)v.size()-1,j=n-1;i>=0;i--,j--)
	{
		ans+=v[i]*a[j];
	}
	cout<<ans;
	return 0;
}