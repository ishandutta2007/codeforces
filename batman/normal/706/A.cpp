#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+9);
const ll HASH=36;

ll a,b,n;
ld ans=1e9;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y,v;
		cin>>x>>y>>v;
		ans=min(ans,(ld)sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
	}
	cout<<fixed<<setprecision(15)<<ans;
	return 0;
}