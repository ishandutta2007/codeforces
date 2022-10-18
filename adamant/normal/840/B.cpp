#include <bits/extc++.h>

using namespace std;

#define free aafa

const int maxn = 3e5 + 42;
int d[maxn];
vector<pair<int, int>> g[maxn];
bool ok[maxn][2];
int used[maxn], need[maxn][2], free[maxn];

void dfs(int v = 1)
{
	used[v] = 1;
	for(auto it: g[v])
	{
		int u = it.first;
		if(used[u])
			continue;
		dfs(u);
		if(d[u] == -1 || ok[u][0] && ok[u][1])
			free[v] = u;
		else
			need[v][!ok[u][0]]++;
	}
	if(free[v] != 0 || d[v] == -1)
		ok[v][0] = ok[v][1] = 1;
	else
		ok[v][(need[v][1] % 2) ^ d[v]] = 1;
}

vector<int> ans;
void dfs_ans(int v = 1, int f = 0)
{
	used[v] = 1;
	for(auto it: g[v])
	{
		int u = it.first;
		if(used[u])
			continue;
		if(!ok[u][0] || need[v][1] % 2 != (d[v] ^ f) && u == free[v])
		{
			ans.push_back(it.second);
			dfs_ans(u, 1);
		}
		else
		{
			dfs_ans(u, 0);
		}
	}
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
		cin >> d[i];
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	dfs();
	if(!ok[1][0])
	{
		cout << -1 << endl;
		return 0;
	}
	memset(used, 0, sizeof(used));
	dfs_ans();
	cout << ans.size() << endl;
	for(auto it: ans)
		cout << it << "\n";
}