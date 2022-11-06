#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <string>
#include <climits>

int n;
std::vector<std::pair<int, int>> adj[100000];
bool visited[100000];
int a[100000];

int bfs() {
	std::queue<std::pair<int, int>> queue;
	std::queue<int> remove;
	queue.push({ 0, 0 });
	visited[0] = true;
	while (!queue.empty()) {
		int u = queue.front().first;
		int d = queue.front().second;
		queue.pop();
		for (auto p : adj[u]) {
			int v = p.first;
			if (!visited[v]) {
				visited[v] = true;
				int w = p.second;
				int f = w + d;
				if(f > a[v])
					remove.push(v);
				else
					queue.push({ v, std::max(f, 0) });
			}
		}
	}
	int count = 0;
	while (!remove.empty()) {
		int u = remove.front();
		remove.pop();
		++count;
		for (auto p : adj[u]) {
			int v = p.first;
			if (!visited[v]) {
				visited[v] = true;
				remove.push(v);
			}
		}
	}
	return count;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int p, c;
		std::cin >> p >> c;
		adj[i].push_back({ --p, c });
		adj[p].push_back({ i, c });
	}
	std::cout << bfs();
	return 0;
}