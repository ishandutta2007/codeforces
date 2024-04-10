#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)22)

ll n,a[N],dp[N][K],dp_up[N][K],sz[N],ans;
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	sz[x]=1;
	for(auto u:e[x])
	{
		if(u==par)continue;
		dfs(u,x);
		sz[x]+=sz[u];
		for(int i=0;i<K;i++)
		{
			if((a[x]&(1<<i)))dp[x][i]+=sz[u]-dp[u][i];
			else dp[x][i]+=dp[u][i];
		}
	}
	for(int i=0;i<K;i++)dp[x][i]+=((a[x]&(1<<i))!=0),ans+=dp[x][i]*(1<<i);
//	cout<<x<<"|||| \n";
//	for(int i=0;i<K;i++)cout<<dp[x][i]<<"\n";
}

void dfs_up(ll x,ll par=0)
{
	ll ex[K];
	ans+=a[x];
	for(int i=0;i<K;i++)ex[i]=dp_up[x][i]+dp[x][i],ans+=dp_up[x][i]*(1<<i);
	for(auto u:e[x])
	{
		if(u==par)continue;
	//	cout<<u<<"|||||| \n";
		for(int i=0;i<K;i++)
		{
		//	cout<<dp[2][1]<<"\n";
			if((a[x]&(1<<i)))ex[i]-=sz[u]-dp[u][i];
			else ex[i]-=dp[u][i];
			
			if((a[u]&(1<<i)))dp_up[u][i]=(n-sz[u])-ex[i];
			else dp_up[u][i]=ex[i];
	//		cout<<dp_up[u][i]<<"\n";
			
			if((a[x]&(1<<i)))ex[i]+=sz[u]-dp[u][i];
			else ex[i]+=dp[u][i];
		}
		dfs_up(u,x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	dfs_up(1);
	cout<<ans/2;
	return 0;
}