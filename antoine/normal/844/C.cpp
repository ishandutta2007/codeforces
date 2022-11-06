#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <string>

int n;
int a[100000];
std::pair<int, int> b[100000];

std::vector<int> adj[100000];

std::vector<std::vector<int>> comps;
int visited[100000] = { false };

void dfs(int u) {
	visited[u] = true;
	comps.back().push_back(u);
	for (int v : adj[u])
		if (!visited[v])
			dfs(v);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		b[i] = { a[i], i };
	}

	std::sort(b, b + n);

	for (int i = 0; i < n; ++i) {
		int u = b[i].second;
		int v = i;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; ++i)
		if (!visited[i]) {
			comps.push_back({});
			dfs(i);
		}

	std::cout << comps.size() << '\n';
	for (auto &&x : comps) {
		std::sort(x.begin(), x.end());
		std::cout << x.size();
		for (int y : x)
			std::cout << ' ' << (y + 1);
		std::cout << '\n';
	}
	return 0;
}