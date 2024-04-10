#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int in[200005],out[200005],dp[200005],d[200005];
vector <int> e[200005];
queue <int> q;
int p[200005],cnt; 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		++out[u],++in[v],++d[v];
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!d[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		p[++cnt]=x;
		for(auto v:e[x])
			if(!--d[v]) q.push(v);
	}
	int ans=1;
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int I=n;I>=1;I--)
	{
		int i=p[I],u=p[I];
		if(out[i]<=1) continue;
		for(auto v:e[u])
		{
			if(in[v]<=1) continue;
			dp[u]=max(dp[u],dp[v]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}