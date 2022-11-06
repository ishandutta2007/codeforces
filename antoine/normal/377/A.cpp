#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <queue>
#include <string>
#include <stack>

int n, m, k;
std::string str[500];
bool visited[500][500];

auto bfs(int i, int j) {
	std::stack<std::pair<int, int>> result;
	std::queue<std::pair<int, int>> nodes;
	nodes.push({ i, j });
	while (!nodes.empty()) {
		i = nodes.front().first;
		j = nodes.front().second;
		nodes.pop();
		if (visited[i][j] || str[i][j] != '.')
			continue;
		visited[i][j] = true;
		result.push({ i, j });
		if (i + 1 < n)
			nodes.push({ i + 1, j });
		if (i > 0)
			nodes.push({ i - 1, j });
		if (j + 1 < m)
			nodes.push({ i, j + 1 });
		if (j > 0)
			nodes.push({ i, j - 1 });
	}
	return result;
}

auto bfs() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if (str[i][j] == '.') {
				return bfs(i, j);
			}
}

int main() {
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		std::cin >> str[i];
	auto nodes = bfs();

	for (; k > 0; --k) {
		auto node = nodes.top();
		int i = node.first;
		int j = node.second;
		nodes.pop();
		str[i][j] = 'X';
	}
	for (int i = 0; i < n; ++i)
		std::cout << str[i] << "\n";
	return 0;
}