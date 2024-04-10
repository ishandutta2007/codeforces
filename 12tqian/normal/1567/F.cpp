#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < m; ++j) {
			if (line[j] == 'X') {
				g[i][j] = 1;
			} 
		}
	}
	vector<vector<int>> gr(n * m);
	const vector<int> di = {0, 1, 0, -1};
	const vector<int> dj = {1, 0, -1, 0};
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			if (!g[i][j]) {
				continue;
			}
			vector<int> nxt;
			for (int d = 0; d < 4; ++d) {
				int ni = i + di[d];
				int nj = j + dj[d];
				if (!g[ni][nj]) {
					nxt.push_back(ni * m + nj);
				}
			}
			int sz = (int)nxt.size();
			if (sz & 1) {
				cout << "NO" << '\n';
				return 0;
			}
			for (int k = 0; k < sz; ++k) {
				auto ae = [&](int u, int v) {
					gr[u].push_back(v);
					gr[v].push_back(u);
				};
				ae(nxt[k], nxt[(k + 1) % sz]);
			}
		}
	}
	vector<int> c(n * m);
	vector<bool> vis(n * m);
	for (int i = 0; i < n * m; ++i) {
		if (!vis[i]) {
			function<void(int)> dfs = [&](int u) {
				vis[u] = true;
				for (int v : gr[u]) {
					if (!vis[v]) {
						c[v] = c[u] ^ 1;
						dfs(v);
					}
				}
			};
			dfs(i);
		}
	}
	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int v = 0;
			if (g[i][j]) {
				for (int d = 0; d < 4; ++d) {
					int ni = i + di[d];
					int nj = j + dj[d];
					if (!g[ni][nj]) {
						v += c[ni * m + nj] * 3 + 1;
					}
				}
			} else {
				v = c[i * m + j] * 3 + 1;
			}
			cout << v << ' ';
		}
		cout << '\n';
	}
	return 0;
}