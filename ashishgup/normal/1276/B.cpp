#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;
const int M = 5e5 + 5;
 
int n, m, src, dest;
int u[N], v[N], cnt = 0, vis[N];
vector<int> g[N];

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u] = 1;
	cnt++;
	for(auto &it:g[u])
	{
		if(vis[it])
			continue;
		dfs(it);
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		cin >> src >> dest;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= m; i++)
		{
			cin >> u[i] >> v[i];
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		for(int i = 1; i <= n; i++)
			vis[i] = 0;
		vis[dest] = 1;
		cnt = 0;
		dfs(src);
		int x = (n - 1 - cnt);
		swap(src, dest);
		for(int i = 1; i <= n; i++)
			vis[i] = 0;
		vis[dest] = 1;
		cnt = 0;
		dfs(src);
		int y = (n - 1 - cnt);
		cout << x * y << endl;
	}
	return 0;
}