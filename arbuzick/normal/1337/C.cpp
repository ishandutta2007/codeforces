#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> a;
vector<pair<int, int>> d;
vector<int> used;
vector<int> c;
set<int> ind;
int dfs(int v, int b) {
	d[v] = { b, v };
	used[v] = 1;
	c[v] = 0;
	for (int u : a[v])
		if (used[u] == 0)
			c[v] += dfs(u, b + 1)+1;
	return c[v];
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	a = vector<vector<int>>(n);
	used = vector<int>(n);
	c = vector<int>(n);
	used[0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		a[v1 - 1].push_back(v2 - 1);
		a[v2 - 1].push_back(v1 - 1);
		used[i + 1] = 0;
	}
	d = vector<pair<int, int>>(n);
	dfs(0, 0);
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());
	vector<int> p(n);
	for (int i = 0; i < n; ++i) 
		p[d[i].second] = d[i].first - c[d[i].second];
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	int ans = 0;
	for (int i = 0; i < k; ++i) 
		ans += p[i];
	cout << ans;
	return 0;
}