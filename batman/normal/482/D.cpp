#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=((ll)101*1000);
const ll MOD=((ll)1e9+7);

ll n,dp[2][N];
vector <ll> e[N];

void dfs(ll x)
{
	dp[0][x]=1;
	ll all0=1,all1[2]={1,0};
	for(auto u:e[x])
	{
		dfs(u);
		all0*=dp[0][u];all0%=MOD;
		ll new0=all1[0]+all1[1]*dp[1][u];new0%=MOD;
		all1[1]=all1[1]+all1[0]*dp[1][u];all1[1]%=MOD;
		all1[0]=new0;
		new0=dp[0][x]*dp[0][u]+dp[1][x]*dp[1][u];new0%=MOD;
		dp[1][x]=dp[0][x]*dp[1][u]+dp[1][x]*dp[0][u];dp[1][x]%=MOD;
		dp[0][x]=new0;
	}
	dp[0][x]*=2;dp[1][x]*=2;dp[0][x]%=MOD;dp[1][x]%=MOD;
	dp[0][x]-=all0;dp[0][x]%=MOD;dp[0][x]+=MOD;dp[0][x]%=MOD;
	dp[1][x]-=all1[1];dp[1][x]%=MOD;dp[1][x]+=MOD;dp[1][x]%=MOD;
	swap(dp[0][x],dp[1][x]);
	dp[0][x]++;dp[0][x]%=MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		ll x;
		cin>>x;
		e[x].push_back(i);
	}
	dfs(1);
	cout<<(dp[0][1]+dp[1][1]-1+MOD)%MOD<<"\n";
	return 0;
}