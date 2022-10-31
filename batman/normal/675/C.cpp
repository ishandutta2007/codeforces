#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =301*1000;

ll n,a[N],sum[N],ans,ex;
map <ll,ll> mp;

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];sum[i]=sum[i-1]+a[i];
		mp[sum[i]]++;
	}
	ans=max(ans,mp[0]);ex=sum[n];
	for(int i=1;i<=n;i++)
	{
		mp[sum[i]]--;
		ex+=a[i];
		mp[ex]++;
		ans=max(ans,mp[sum[i]]);
	}
	cout<<n-ans;
	return 0;
}