#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n;
vector<int> pos;
vector<int> g[N];

void dfs(int u, int par)
{
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		pos.push_back(it);
	}
	pos.push_back(u);
	int sz = g[u].size();
	for(int i = sz - 1; i >= 0; i--)
	{
		if(g[u][i] == par)
			continue;
		dfs(g[u][i], u);
	}
}

vector<int> ans[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	pos.push_back(1);
	dfs(1, 1);
	for(int i = 0; i < pos.size(); i++)
		ans[pos[i]].push_back(i + 1);
	for(int i = 1; i <= n; i++)
	{
		for(auto &it:ans[i])
			cout << it << " ";
		cout << endl;
	}
	return 0;
}