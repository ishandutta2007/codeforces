//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 4e5 + 5;

int n, m;
int ans[N];
vector<int> g[N], og[N];

int get(int u, int type)
{
	if(type == 0)
		return u;
	return n + u;
}

int vis[N], dist[N];

void bfs(int k)
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	q.push(k);
	vis[k] = 1;
	dist[k] = 0;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(auto &it:og[node])
		{
			if(!vis[it])
			{
				dist[it] = dist[node] + 1;
				vis[it] = 1;
				q.push(it);
			}
		}
	}
}

int dfs(int u)
{
	int &val = ans[u];
	if(val != -1)
		return val;
	if(u <= n)
		val = dist[u];
	else
		val = dist[u - n];
	for(auto &it:g[u])
		val = min(val, dfs(it));
	return val;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= 2 * n; i++)
		{
			ans[i] = -1;
			g[i].clear(), og[i].clear();
		}
		vector<pair<int, int> > edges;
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v});
			og[u].push_back(v);
		}
		bfs(1);
		for(auto &it:edges)
		{
			int u = it.first, v = it.second;
			int du = dist[u], dv = dist[v];
			if(du < dv)
			{
				g[get(u, 0)].push_back(get(v, 0));
				g[get(u, 1)].push_back(get(v, 1));
			}
			else
				g[get(u, 0)].push_back(get(v, 1));
		}
		for(int i = 1; i <= 2 * n; i++)
			dfs(i);
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}