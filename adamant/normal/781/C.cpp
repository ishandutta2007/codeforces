#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 42;
vector<int> g[maxn];
int used[maxn];

void dfs(int v, vector<int> &st)
{
	used[v] = 1;
	st.push_back(v);
	for(auto u: g[v])
		if(!used[u])
		{
			dfs(u, st);
			st.push_back(v);
		}
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> ans;
	dfs(0, ans);
	int step = ans.size() / k + bool(ans.size() % k);
	int t = 0;
	for(int i = 0; i < ans.size() || t < k; i += step, t++)
	{
		vector<int> tmp;
		for(int j = 0; i + j < ans.size() && j < step; j++)
			tmp.push_back(ans[i + j]);
		if(tmp.empty())
			tmp = {1};
		cout <<tmp.size() << ' ';
		for(auto it: tmp)
			cout << it + 1 << ' ';
		cout << endl;
	}
		
}