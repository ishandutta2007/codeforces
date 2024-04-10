#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)301*1000);
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);

ll n,dp[N][3];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;
		dp[i][0]=dp[i][1]=dp[i][2]=INF;
		cin>>x;
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		if(x==1 || x==3)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		if(x==2 || x==3)dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
	}
	
	cout<<min(dp[n][0],min(dp[n][1],dp[n][2]));
	
	return 0;
}