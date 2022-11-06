#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>

int n, m;
bool cat[100000];
bool vis[100000];
std::vector<int> adj[100000];

int dfs(int u, int count) {
	vis[u] = true;
	if (!cat[u])
		count = 0;
	else
		if (++count > m)
			return 0;
	int ans = 0;
	bool leaf = true;
	for(int v : adj[u])
		if (!vis[v]) {
			leaf = false;
			ans += dfs(v, count);
		}
	return leaf ? 1 : ans;
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> cat[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::cout << dfs(0, 0);
	return 0;
}