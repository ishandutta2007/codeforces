#include <iostream>

#include <vector>

#include <set>

using namespace std;

pair<int, int> pii;
long long N = 1000 * 1000 * 1000 + 7;
vector< pair<int, int> > adj[1005];
pair<int, int> taxi[1005];
vector< pair<int, int> > adj2[1005];
set< pair < int, int> > s;
long long dis[1005];
int main()
{
	N *= 100000;
	int n, m, st, ed;
	cin >> n;
	cin >> m;
	cin >> st;
	cin >> ed;
	for(int i = 0; i < m; i ++)
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		taxi[i] = {x, y};
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			dis[j] = N;
		}
		dis[i] = 0;
		s.insert({0, i});
		while(s.size())
		{
			pii = *s.begin();
			int v = pii.second;
			s.erase(s.begin());
			for(int j = 0; j < adj[v].size(); j ++)
			{
				int u = adj[v][j].first, w = adj[v][j].second;
				if(dis[v] + w < dis[u])
				{
					s.erase({dis[u], u});
					dis[u] = dis[v] + w;
					s.insert({dis[u], u});
				}
			}
		}
		for(int j = 1; j <= n; j ++)
		{
			if(dis[j] <= taxi[i].first && i != j)
			{
				adj2[i].push_back({j, taxi[i].second});
				//cout << i << " " << j << " " << endl;
			}
		}
	}
	for(int j = 1; j <= n; j ++)
	{
		dis[j] = N;
	}
	dis[st] = 0;
	s.insert({0, st});
	while(s.size())
	{
		pii = *s.begin();
		int v = pii.second;
		s.erase(s.begin());
		for(int j = 0; j < adj2[v].size(); j ++)
		{
			int u = adj2[v][j].first, w = adj2[v][j].second;
			if(dis[v] + w < dis[u])
			{
				s.erase({dis[u], u});
				dis[u] = dis[v] + w;
				s.insert({dis[u], u});
			}
		}
	}
	if(dis[ed] >= N)
	{
		cout << -1;
	}
	else
	{
		cout << dis[ed];
	}
	return 0;
}