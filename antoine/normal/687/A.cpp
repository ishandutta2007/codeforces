#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <string>

int n, m;
std::vector<int> adj[100000];
bool visited[100000];
bool color[100000];
int count = 0;

bool dfs(int u) {
	visited[u] = true;
	for(int v : adj[u])
		if (visited[v]) {
			if (color[v] == color[u])
				return false;
		} else {
			color[v] = !color[u];
			if (!dfs(v))
				return false;
			if (color[v])
				count++;
		}
	return true;
}

bool dfs() {
	for (int u = 0; u < n; ++u)
		if (!visited[u]) {
			color[u] = false;
			if (!dfs(u))
				return false;
		}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	if (!dfs())
		std::cout << -1;
	else {
		std::cout << count << "\n";
		for (int i = 0; i < n; ++i)
			if (color[i])
				std::cout << (i + 1) << " ";
		std::cout << "\n" << (n - count) << "\n";
		for (int i = 0; i < n; ++i)
			if (!color[i])
				std::cout << (i + 1) << " ";
	}
	return 0;
}