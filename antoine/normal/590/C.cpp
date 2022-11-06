#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

int n, m;
char graph[1000][1001];
int dist[3][1000][1000];

void bfs(int S) {
	std::deque<std::pair<int, int>> deque;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (graph[i][j] != '#') {
				if (graph[i][j] == '1' + S) {
					dist[S][i][j] = 0;
					deque.push_back({ i, j });
				}
				else
					dist[S][i][j] = INT_MAX;
			}
	while (!deque.empty()) {
		int x = deque.front().first;
		int y = deque.front().second;
		deque.pop_front();
		for (int i = x - 1; i <= x + 1; ++i)
			for (int j = y - 1; j <= y + 1; ++j)
				if (((i == x) ^ (j == y)) && i >= 0 && i < n && j >= 0 && j < m && graph[i][j] != '#') {
					bool w = graph[i][j] == '.';
					if (dist[S][i][j] > dist[S][x][y] + w) {
						dist[S][i][j] = dist[S][x][y] + w;
						if (w)
							deque.push_back({ i, j });
						else
							deque.push_front({ i, j });

					}
				}
	}
}

bool icp(int x, int y) {
	if (graph[x][y] == '#')
		return false;
	for (int i : {0, 1, 2})
		if (dist[i][x][y] == INT_MAX)
			return false;
	return true;
}

void edgeCase(int k, int &ans) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (graph[i][j] == k + '1') {
				if (icp(i, j))
					ans = std::min(ans, dist[(k + 1) % 3][i][j] + dist[(k + 2) % 3][i][j]);
				return;
			}
		}
}


int answer() {
	int ans = INT_MAX;
	for (int i : {0, 1, 2})
		edgeCase(i, ans);
	if (ans == INT_MAX)
		return -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (icp(i, j)) {
				if (graph[i][j] == '.') {
					ans = std::min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
				}
			}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> graph[i];
	for (int i : {0, 1, 2})
		bfs(i);
	std::cout << answer();
	return 0;
}