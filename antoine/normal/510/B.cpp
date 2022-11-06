#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>

std::string table[50];

int n, m;

auto adj(int x, int y) {
	std::vector<std::pair<int, int>> nodes;
	if (x + 1 < n)
		nodes.push_back({ x + 1, y });
	if (x > 0)
		nodes.push_back({ x - 1, y });
	if (y + 1 < m)
		nodes.push_back({ x, y + 1 });
	if (y > 0)
		nodes.push_back({ x , y - 1 });
	return nodes;
}

bool visited[50][50];

bool dfs(int x, int y, int pX = -1, int pY = -1) {
	visited[x][y] = true;
	for (auto neigh : adj(x, y)) {
		int i = neigh.first;
		int j = neigh.second;
		if (table[x][y] != table[i][j])
			continue;
		if (visited[i][j]) {
			if (i != pX && j != pY)
				return true;
			continue;
		}
		if (dfs(i, j, x, y))
			return true;
	}
	return false;
}

bool dfs() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!visited[i][j] && dfs(i, j))
				return true;
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> table[i];
	std::cout << (dfs() ? "Yes" : "No");
	return 0;
}