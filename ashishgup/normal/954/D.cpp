#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m, s, t;
queue<int> q;
set<int> g[N];
int vis[N], vis2[N], level[N], level2[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i=1;i<=n;i++)
	{
		level[i]=1e9;
		level2[i]=1e9;
	}
	q.push(s);
	level[s]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		vis[node]=1;
		for(auto it:g[node])
		{
			if(vis[it])
				continue;
			vis[it]=1;
			level[it]=level[node]+1;
			q.push(it);
		}
	}
	int mindist=level[t];
	q.push(t);
	level2[t]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		vis2[node]=1;
		for(auto it:g[node])
		{
			if(vis2[it])
				continue;
			vis2[it]=1;
			level2[it]=level2[node]+1;
			q.push(it);
		}
	}
	int ans=n*(n-1)/2, ct=0;
	ans-=m;
	for(int i=1;i<=n;i++)
	{
		int curlevel=level[i];
		for(int j=1;j<=n;j++)
		{
			if(g[i].find(j)!=g[i].end())
				continue;
			if(level[i] + level2[j] + 1<mindist)
			{
				ans--;
			}
		}
	}
	cout<<ans;
	return 0;
}