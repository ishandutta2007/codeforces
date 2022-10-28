#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, node, dist=0;
int a[N], taken[N], vis[N], lvl[N], vis2[N], ans[N], sieve[N];
vector<int> g[N];
vector<pair<int, int> > edges[N];
vector<int> cur;

int dfs(int x, int par, int curd)
{
	if(curd>dist)
	{
		dist=curd;
		node=x;
	}
	vis2[x]=1;
	for(auto &it:g[x])
	{
		if(it==par)
			continue;
		dfs(it, x, curd+1);
	}
}

int diam(int x)
{
	lvl[x]=0;
	node=x;
	dist=0;
	dfs(node, node, 1);
	dfs(node, node, 1);
	return dist;
}

int work()
{
	fill(sieve+2, sieve+N, 1);
	int answer=0;
	for(int i=2;i<N;i++)
	{
		if(!sieve[i])
			continue;
		for(int j=i;j<N;j+=i)
		{
			sieve[j]=0;
			for(auto &it:edges[j])
			{
				int u=it.first, v=it.second;
				if(!taken[u])
					cur.push_back(u);
				if(!taken[v])
					cur.push_back(v);
				vis[u]=0, vis[v]=0;
				taken[u]=1, taken[v]=1;
				lvl[u]=0, lvl[v]=1;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		for(auto &it:cur)
		{
			if(!vis2[it])
				ans[i]=max(ans[i], diam(it));
		}
		for(auto &it:cur)
		{
			vis[it]=vis2[it]=0;
			g[it].clear();
			taken[it]=0;
		}
		cur.clear();
		answer=max(answer, ans[i]);
	}
	return answer;
}

int32_t main()
{
	IOS;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
			ans=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		int w=__gcd(a[u], a[v]);
		edges[w].push_back({u, v});
	}
	cout<<max(ans, work());
	return 0;
}