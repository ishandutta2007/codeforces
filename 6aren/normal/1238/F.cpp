#include<bits/stdc++.h>
using namespace std;

int ans = 0, dp[300005][3];
vector<int> g[300005];

void dfs(int u, int ban) {
	int m1 = 0, m2 = 0;
	int cnt = 0;
	for (auto v : g[u]) {
		if (v == ban) continue;
		cnt++;
		dfs(v, u);
		if (dp[v][1] > m1) {
			m2 = m1; m1 = dp[v][1];
		} else if (dp[v][1] > m2) {
			m2 = dp[v][1];
		}
	}
	if (cnt == 0) {
		dp[u][1] = 1;
	} else if (cnt == 1) {
		dp[u][1] = m1 + 1;
	} else {
		dp[u][1] = m1 + cnt;
		dp[u][2] = m1 + m2 + cnt - 1;
	}
	int res1, res2;
	if (u != 1) res1 = dp[u][1] + 1, res2 = dp[u][2] + 1;
	else res1 = dp[u][1], res2 = dp[u][2];
	ans = max(ans, max(res1, res2));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			dp[i][1] = 0;
			dp[i][2] = 0;
			ans = 0;
		}
	}
	return 0;
}