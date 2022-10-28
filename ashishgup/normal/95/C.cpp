#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;
const int inf=1e15;

int n, m, x, y;
int arrival[N][N], departure[N][N];
vector<pair<int, int> > g[N];

void dijkstra(int source, int destination, int arrival[], int departure[])
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=inf;
		departure[i]=inf;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i=1;i<=n;i++)
		dijkstra(i, i, arrival[i], departure[i]);
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=n;i++)
	{
		int t, c;
		cin>>t>>c;
		for(int j=1;j<=n;j++)
		{
			if(departure[i][j]<=t)
				g[i].push_back({j, c});
		}
	}
	dijkstra(x, x, arrival[0], departure[0]);
	if(arrival[0][y]>=inf)
		cout<<"-1";
	else
		cout<<arrival[0][y];
	return 0;
}