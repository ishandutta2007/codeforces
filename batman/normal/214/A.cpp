#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,m,ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i*i<=n;i++)
	{
		ll j=n-i*i;
		if(i+j*j==m)ans++;
	}
	cout<<ans;
    return 0;
}