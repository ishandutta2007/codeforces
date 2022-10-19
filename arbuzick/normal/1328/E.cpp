#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int dfs(int t, int v, vector<vector<int>>& a, vector<int>& t1, vector<int>& t2, vector<int>& par, vector<int>&d, int dep, int p) {
	par[v] = p;
	d[v] = dep;
	t1[v] = t;
	for (int i = 0; i < a[v].size(); ++i) 
		if (a[v][i] != par[v]) 
			t = dfs(t + 1, a[v][i], a, t1, t2, par, d, dep+1, v);
	t2[v] = t;
	return t;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		a[v - 1].push_back(u - 1);
		a[u - 1].push_back(v - 1);
	}
	vector<int> t1(n), t2(n), par(n), d(n);;
	dfs(0, 0, a, t1, t2, par, d, 0, 0);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> v1(k);
		for (int j = 0; j < k; ++j) {
			cin >> v1[j];
			v1[j] -= 1;
		}
		int u = v1[0];
		for (int j = 1; j < k; ++j)
			if (d[v1[j]] > d[u])
				u = v1[j];
		for (int j = 0; j < k; ++j)
			if (v1[j] != u) 
				v1[j] = par[v1[j]];
		bool ans = true;
		for (int j = 0; j < k; ++j) {
			if (!(t1[u] >= t1[v1[j]] && t2[u] <= t2[v1[j]]))
				ans = false;
		}
		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}