#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll int
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=505;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)2e9);

ll n,k;
bool dp[N][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		for(int j=k;j>=x;j--)
			for(int q=0;q<=k;q++)
			{
				if(q-x>=0)dp[j][q]|=dp[j-x][q-x];
				dp[j][q]|=dp[j-x][q];
			}	
	}
	ll ans=0;
	for(int i=0;i<=k;i++)
		if(dp[k][i])
			ans++;
	cout<<ans<<"\n";
	for(int i=0;i<=k;i++)
		if(dp[k][i])
			cout<<i<<" ";
	return 0;
}