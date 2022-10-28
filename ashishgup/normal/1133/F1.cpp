#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n, m;
int dist[N], deg[N], parent[N];
bool vis[N];
vector<pair<int, int> > g[N], tree[N];
vector<pair<int, int> > answer;

int primsMST(int source) //Finds the cost and makes the MST
{
	for(int i=1;i<=n;i++)
		dist[i]=1e9;
	set<pair<int, int> > s;
	s.insert({0, source});
	int cost=0;
	dist[source]=0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		cost+=x.first;
		int u=x.second;
		int v=parent[x.second];
		int w=x.first;
		if(v > 0)
			answer.push_back({u, v});
		for(auto it:g[x.second])
		{
			if(vis[it.first])
				continue;
			if(dist[it.first] > it.second)
			{
				s.erase({dist[it.first], it.first});
				dist[it.first]=it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	return cost;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, 1});
		g[v].push_back({u, 1});
		deg[u]++;
		deg[v]++;
	}
	int best = 1, mx = 0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i] > mx)
		{
			mx = deg[i];
			best = i;
		}
	}
	primsMST(best);
	for(auto &it:answer)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}