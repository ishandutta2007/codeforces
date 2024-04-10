#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


// long long !!!
int n;
std::vector<int> adj[100001];
int parent[100001];

int count[2] = { 0, 0 };

void dfs(int u, int p, int depth) {
	++count[depth&1];

	for (int v : adj[u])
		if (v != p)
			dfs(v, u, depth + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n;
	std::memset(parent, -1, sizeof parent);

	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i)
		if (parent[i] == -1) {
			dfs(i, -1, 0);
			break;
		}

	std::cout << ((long long)count[0] * count[1] - (n - 1));
	return 0;
}