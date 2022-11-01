#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,c[N],dp[2][N];
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	for(auto v:e[x])
		if(v!=par)
			dfs(v,x),
			dp[0][x]=max(dp[0][x],dp[0][v]),
			dp[1][x]=max(dp[1][x],dp[1][v]);
	ll p=dp[1][x]-dp[0][x]+c[x];
	dp[1][x]+=max(0ll,-p);
	dp[0][x]+=max(0ll,p);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<dp[0][1]+dp[1][1];
	return 0;
}