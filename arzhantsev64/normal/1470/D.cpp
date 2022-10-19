#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int cnt;
vector<bool> was;
vector<bool> taken;
vector<vector<int>> G;

void dfs1(int v) {
	was[v] = 1;
	cnt++;
	for (int to : G[v])
		if (!was[to])
			dfs1(to);
}

void solve() {
	int n, m;
	cin >> n >> m;
	G = vector<vector<int>> (n);
	was = vector<bool> (n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cnt = 0;
	dfs1(0);
	if (cnt != n) {
		cout << "NO\n";
		return;
	}
	was   = vector<bool> (n, false);
	taken = vector<bool> (n, false);
	queue<int> q;
	q.push(0);
	was[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		bool to_take = true;
		for (int to : G[v]) {
			if (taken[to])
				to_take = false;
			if (!was[to]) {
				was[to] = true;
				q.push(to);
			}
		}
		taken[v] = to_take;
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (taken[i])
			ans.push_back(i + 1);
	cout << "YES\n";
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}