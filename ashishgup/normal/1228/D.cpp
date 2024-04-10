#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, edges;
vector<int> g[N];
map<vector<int>, vector<int> > m;
int ans[N];
vector<int> store[5];
set<int> adj[N];

int32_t main()
{
	IOS;
	cin >> n >> edges;
	for(int i = 1; i <= edges; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i = 1; i <= n; i++)
	{
		sort(g[i].begin(), g[i].end());
		m[g[i]].push_back(i);
	}
	if(m.size() != 3)
	{
		cout << -1;
		return 0;
	}
	int reqd = 0;
	for(auto &it:m)
		reqd += (1LL * it.second.size() * (n - it.second.size()));
	reqd /= 2;
	if(reqd != edges)
	{
		cout << -1;
		return 0;
	}
	int cnt = 0;
	for(auto &it:m)
	{
		cnt++;
		for(auto &j:it.second)
		{
			ans[j] = cnt;
			store[cnt].push_back(j);
		}
	}
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			if(i == j)
				continue;
			for(auto &x:store[i])
			{
				for(auto &y:store[j])
				{
					if(adj[x].find(y) == adj[x].end())
					{
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}