#include <bits/stdc++.h>

const int N = 55;

int n, m;
char a[N][N];
std::vector<int> E[N << 1];
bool vis[N << 1];
std::vector<int> id;

void dfs(int u) {
	vis[u] = 1;
	id.push_back(u);
	for (int v : E[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> (a[i] + 1);
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#') {
				E[i].push_back(j + n);
				E[j + n].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n + m; ++i) {
		if (!vis[i]) {
			id.clear();
			dfs(i);
			for (int r : id) {
				if (r <= n) {
					for (int c : id) {
						if (c > n) {
							if (a[r][c - n] == '.') {
								std::cout << "No\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	std::cout << "Yes\n";
}