#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > g;
string ans = "";
bool used[600];
bool gg[600][600];

void dfs(int v) {
	used[v] = 1;
	ans[v - 1] = 'a';
	for (int i = 0; i < g[v].size(); i++) {
		int t = g[v][i];
		if (!used[t] && ans[t - 1] == '*') {
			dfs(t);
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		gg[u][v] = gg[v][u] = 1;
	}
	for (int i = 0; i < n; i++) {
		ans += '*';
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == n - 1)
			ans[i - 1] = 'b';
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() != n - 1) {
			dfs(i);
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == '*')
			ans[i] = 'c';
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((abs(ans[i] - ans[j]) <= 1) != gg[i + 1][j + 1]) {
				cout << "No"  << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	cout << ans << endl;
}