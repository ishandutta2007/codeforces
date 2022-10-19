#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> deg(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		deg[a]++;
		g[b].push_back(a);
	}
	int s, t;
	cin >> s >> t;
	vector<int> dp(n + 1, 1e9);
	vector<int> cnt(n + 1);
	dp[t] = 0;
	deque<int> d;
	d.push_back(t);
	vector<int> used(n + 1);
	while (!d.empty()) {
		int v = d.front();
		d.pop_front();
		if (used[v]) {
			continue;
		}
		used[v] = 1;
		for (int u : g[v]) {
			int w = 1;
			cnt[u]++;
			if (cnt[u] == deg[u]) {
				w = 0;
			}
			if (dp[v] + w < dp[u]) {
				dp[u] = dp[v] + w;
				if (w == 1) {
					d.push_back(u);
				} else {
					d.push_front(u);
				}
			}
		}
	}
	if (dp[s] == 1e9) {
		cout << "-1\n";
	} else {
		cout << dp[s] << endl;
	}
	return 0;
}