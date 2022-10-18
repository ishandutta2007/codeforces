#include <bits/stdc++.h>

using namespace std;

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, vector<pair<int, int>>> edges;
	for(int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		edges[c].push_back({u - 1, v - 1});
	}
	vector<vector<int>> sets;
	for(auto it: edges)
	{
		map<int, int> par;
		map<int, vector<int>> st;
		
		for(auto jt: it.second)
		{
			if(par[jt.first] == 0)
				par[jt.first] = jt.first;
			if(par[jt.second] == 0)
				par[jt.second] = jt.second;
			int a = par[jt.first];
			int b = par[jt.second];
			if(a == b)
				continue;
			if(st[a].empty())
				st[a] = {a};
			if(st[b].empty())
				st[b] = {b};
			if(st[a].size() > st[b].size())
				swap(a, b);
			for(auto it: st[a])
			{
				st[b].push_back(it);
				par[it] = b;
			}
			st[a].clear();
		}
		for(auto it: st)
			if(it.second.size() > 1)
				sets.push_back(it.second);
	}
	map<int, map<int, int>> pre;
	int root = 300;
	vector<vector<int>> large;
	for(auto it: sets)
		if(it.size() < root)
		{
			for(int i = 0; i < it.size(); i++)
				for(int j = i + 1; j < it.size(); j++)
				{
					pre[it[i]][it[j]]++;
					pre[it[j]][it[i]]++;
				}
		}
		else
		{
			sort(begin(it), end(it));
			large.push_back(it);
		}
	int q;
	cin >> q;
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		int ans = pre[a][b];
		for(auto it: large)
			ans += binary_search(begin(it), end(it), a) && binary_search(begin(it), end(it), b);
		cout << ans << "\n";
	}
}