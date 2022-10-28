#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int vis[N], col[N];
int uu[N], vv[N];
vector<pair<int, int> > g[N];

void dfs(int u, int c)
{
	if(vis[u])
	{
		if(col[u] != c)
		{
			cout << "NO";
			exit(0);
		}
		return;
	}
	vis[u] = 1;
	col[u] = c;
	for(auto &it:g[u])
		dfs(it.first, c ^ 1);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		uu[i] = u;
		vv[i] = v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	dfs(1, 0);
	cout << "YES" << endl;
	for(int i = 1; i <= m; i++)
	{
		if(col[uu[i]])
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}