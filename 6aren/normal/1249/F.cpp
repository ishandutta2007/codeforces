#include<bits/stdc++.h>
using namespace std;

int n, k;
int dp[205][205], a[205];
vector<int> g[205];

void dfs(int u, int ban) {
	for (auto v : g[u]) {
		if (v == ban) continue;
		dfs(v, u);
	} 
	for (int i = 0; i <= k / 2 - 1; i++) {
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j];
			if (v == ban) continue;
			int temp = dp[v][i];
			for (int jj = 0; jj < g[u].size(); jj++) {
				if (jj == j) continue;
				if (g[u][jj] == ban) continue;
				v = g[u][jj];
				temp += dp[v][k - i - 2];
			}
			dp[u][i + 1] = max(dp[u][i + 1], temp);
			//if (u == 2) cout << 1111 << endl;
		}
	}
	for (int i = k / 2; i <= k; i++) {
		for (auto v : g[u]) {
			if (v == ban) continue;
			dp[u][i + 1] += dp[v][i];
		}
	}
	dp[u][0] = a[u];
	for (auto v : g[u]) if (v != ban) dp[u][0] += dp[v][k - 1]; 
	for (int i = k - 1; i >= 0; i--) {
		dp[u][i] = max(dp[u][i], dp[u][i + 1]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	k++;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout << dp[1][0] << endl;
	return 0;
}