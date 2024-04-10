#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
bool flag = 1;
int p[N], h[N], sum[N], happy[N], sad[N];
vector<int> g[N];

void dfs(int u, int par)
{
	sum[u] = p[u];
	int sadChildren = 0;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u);
		sum[u] += sum[it];
		sadChildren += sad[it];
	}
	if((h[u] + sum[u]) % 2)
	{
		flag = 0;
		return;
	}
	if(h[u] + sum[u] < 0)
		flag = 0;
	happy[u] = (h[u] + sum[u]) / 2;
	sad[u] = sum[u] - happy[u];
	if(sad[u] < 0 || happy[u] < 0)
	{
		flag = 0;
		return;
	}
	if(sadChildren < sad[u] - p[u])
	{
		flag = 0;
		return;
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		flag = 1;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> p[i];
		for(int i = 1; i <= n; i++)
			cin >> h[i];
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 1);
		if(!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}