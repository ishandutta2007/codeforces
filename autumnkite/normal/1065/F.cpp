#include <bits/stdc++.h>

const int N = 1000005, LG = 20;

int n, k;
std::vector<int> E[N];
int fa[N];

int dis[N], g[N], f[N];

void dfs1(int u) {
	if (E[u].empty()) {
		g[u] = 1;
		dis[u] = 0;
		return;
	}
	g[u] = 0;
	dis[u] = N;
	for (int v : E[u]) {
		dfs1(v);
		dis[u] = std::min(dis[u], dis[v] + 1);
		if (dis[v] < k) {
			g[u] += g[v];
		}
	}
}

void dfs2(int u) {
	f[u] = g[u];
	for (int v : E[u]) {
		dfs2(v);
		int t = dis[v] < k ? g[v] : 0;
		f[u] = std::max(f[u], g[u] - t + f[v]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		std::cin >> fa[i];
		E[fa[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	std::cout << f[1] << std::endl;
}