#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> g[n];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool ok = true;
	for(int i = 0; i < n; i++) {
		ok &= g[i].size() == 1 || g[i].size() >= 3;
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}