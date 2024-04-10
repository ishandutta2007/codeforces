#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

typedef struct data
{
	int x, y;
	int idx; 
}info;

int n, m, src, dest;
int sx, sy, fx,fy;
info a[N];
int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];

int dijkstra(int source, int destination)
{
	for(int i = 1; i <= m + 2; i++)
	{
		arrival[i] = 2e9;
		departure[i] = 2e9;
		vis[i] = 0;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		departure[x.second]=arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	return arrival[dest];
}

int get(info &d1, info &d2, bool flag)
{
	int cost = abs(d1.x - d2.x) + abs(d1.y - d2.y);
	if(flag)
		cost = min(abs(d1.x - d2.x), abs(d1.y - d2.y));
	return cost;
}

bool comp1(info &d1, info &d2)
{
	return d1.x < d2.x;
}

bool comp2(info &d1, info &d2)
{
	return d1.y < d2.y;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;
	src = m + 1;
	dest = m + 2;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].idx = i;
	}
	sort(a + 1, a + m + 1, comp1);
	for(int i = 1; i + 1 <= m; i++)
	{
		int u = a[i].idx;
		int v = a[i + 1].idx;
		int dist = get(a[i], a[i + 1], 1);
		g[u].push_back({v, dist});
		g[v].push_back({u, dist});
	}
	sort(a + 1, a + m + 1, comp2);
	for(int i = 1; i + 1 <= m; i++)
	{
		int u = a[i].idx;
		int v = a[i + 1].idx;
		int dist = get(a[i], a[i + 1], 1);
		g[u].push_back({v, dist});
		g[v].push_back({u, dist});
	}
	info source, destination;
	source.x = sx, source.y = sy, source.idx = src;
	destination.x = fx, destination.y = fy, destination.idx = dest;
	for(int i = 1; i <= m; i++)
	{
		int u = source.idx;
		int v = a[i].idx;
		int dist = get(source, a[i], 1);
		g[u].push_back({v, dist});
		g[v].push_back({u, dist});
	}
	for(int i = 1; i <= m; i++)
	{
		int u = destination.idx;
		int v = a[i].idx;
		int dist = get(destination, a[i], 0);
		g[u].push_back({v, dist});
		g[v].push_back({u, dist});
	}
	int u = source.idx;
	int v = destination.idx;
	int dist = get(source, destination, 0);
	g[u].push_back({v, dist});
	g[v].push_back({u, dist});
	int ans = dijkstra(src, dest);
	cout << ans;
	return 0;
}