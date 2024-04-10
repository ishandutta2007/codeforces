#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (301*1000)

ll n,b,p,ans;

ll maxi(ll x)
{
	ll ans=1;
	while(x)
	{
		ans*=2;
		x/=2;
	}
	return ans/2;
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>b>>p;
	ll n2=n;
	while(n2>1)
	{
		ll k=maxi(n2);
		ans+=(2*b+1)*k/2;
		n2-=k/2;
	}
	cout<<ans<<" "<<n*p;
	
	
	return 0;
}