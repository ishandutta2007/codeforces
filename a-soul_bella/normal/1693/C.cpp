#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[200005],vis[200005],mx[200005],cnt[200005];
vector <int> e[200005],E[200005];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
const int inf=1e18;
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
		e[u].push_back(v);
		E[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cnt[i]=e[i].size();
	for(int i=1;i<n;i++) dis[i]=inf;
	q.push({0,n});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto v:E[x])
		{
			mx[v]=max(mx[v],dis[x]);
			--cnt[v];
			if(dis[v]>cnt[v]+mx[v]+1)
			{
				dis[v]=cnt[v]+mx[v]+1;
				q.push({dis[v],v});
			}
		}
	}
	cout << dis[1];
	return 0;
}