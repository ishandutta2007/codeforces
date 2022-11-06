#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

struct Res {
	bool success = true;
	vector<int> nodes;

	bool operator<(const Res &other) const {
		if (!success || !other.success)
			return success < other.success;
		return nodes.size() > other.nodes.size();
	}

	void print() const {
		if (!success)
			cout << -1;
		else {
			cout << nodes.size() << '\n';
			for (int i = 0; i < nodes.size(); ++i) {
				if (i) cout << ' ';
				cout << nodes[i];
			}
		}
	}
};

struct Graph {
	int n, m;
	vector<vector<pair<int, bool>>> adj;
	vector<bool> visited;
	vector<bool> color;

	Graph() {
		cin >> n >> m;

		adj.resize(n + 1);
		visited.resize(n + 1, 0);
		color.resize(n + 1, 0);

		for (int i = 0; i < m; ++i) {
			int u, v;
			char c;
			cin >> u >> v >> c;
			adj[u].push_back({ v, c == 'R' });
			adj[v].push_back({ u, c == 'R' });
		}
	}

	bool dfs(const int u, vector<int> &white, vector<int> &black) {
		visited[u] = true;
		if (color[u])
			white.push_back(u);
		else
			black.push_back(u);

		for (auto &&x : adj[u]) {
			const int v = x.first;
			if (visited[v]) {
				if (color[u] ^ color[v] ^ x.second)
					return false;
			}
			else {
				color[v] = color[u] ^ x.second;
				if (!dfs(v, white, black))
					return false;
			}
		}
		return true;
	}

	Res dfs() {
		Res res;
		for (int i = 1; i <= n; ++i)
			if (!visited[i]) {
				vector<int> white, black;
				color[i] = 0;
				if (!dfs(i, white, black)) {
					res.success = false;
					break;
				}
				if (white.size() < black.size())
					res.nodes.insert(res.nodes.end(), white.begin(), white.end());
				else
					res.nodes.insert(res.nodes.end(), black.begin(), black.end());
			}
		return res;
	}

	void flip() {
		for (int i = 0; i <= n; ++i)
			for (auto &&x : adj[i])
				x.second ^= 1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Graph g;
	Graph gTmp = g;

	auto res = gTmp.dfs();

	g.flip();
	max(res, g.dfs()).print();
	return 0;
}