#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, ans;
int val[N];
vector<int> g[N];

int dfs(int u, int par)
{
	vector<int> cur;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		cur.push_back(dfs(it, u));
	}
	sort(cur.rbegin(), cur.rend());
	int temp = val[u];
	if(cur.size() > 1)
		ans = max(ans, cur[0] + cur[1] + val[u]);
	if(cur.size())
		temp += cur[0];
	ans = max(ans, temp);
	return temp;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1; i <= n; i++)
			val[i] = (int)g[i].size() - 1;
		dfs(2, 0);
		cout << ans + 2 << endl;
	}
	return 0;
}