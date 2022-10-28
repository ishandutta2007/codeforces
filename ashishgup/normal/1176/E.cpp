#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int tc = 0;
int vis[N], col[N];
vector<int> g[N];
vector<int> ans[2];

void dfs(int u, int c)
{
	if(vis[u] == tc)
		return;
	vis[u] = tc;
	col[u] = c;
	ans[c].push_back(u);
	for(auto &it:g[u])
		dfs(it, c ^ 1);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		tc++;
		ans[0].clear();
		ans[1].clear();
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		if(ans[1].size() < ans[0].size())
			swap(ans[0], ans[1]);
		cout << ans[0].size() << endl;
		for(auto &it:ans[0])
			cout << it << " ";
		cout << endl;
	}
	return 0;
}