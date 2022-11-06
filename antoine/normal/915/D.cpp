#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Graph {
	int n;
	vector<vector<bool>> adjM;

	Graph(istream &in) {
		int m;
		in >> n >> m;
		adjM = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adjM[u][v] = true;
		}
	}

	bool findCycle(const int u, vector<char> &color, vector<int> &nodes) const {
		color[u] = 1;
		nodes.push_back(u);
		for (int v = 1; v <= n; ++v)
			if (adjM[u][v]) {
				if (!color[v] && findCycle(v, color, nodes))
					return true;
				if (color[v] == 1) {
					nodes = vector<int>(find(nodes.begin(), nodes.end(), v), nodes.end());
					return true;
				}
			}
		nodes.pop_back();
		color[u] = 2;
		return false;
	}

	vector<int> findCycle() const {
		vector<char> color(n + 1, 0);
		vector<int> nodes;
		for (int i = 1; i <= n; ++i)
			if (color[i] == 0) {
				if (findCycle(i, color, nodes))
					break;
				nodes.clear();
			}
		return nodes;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Graph G(cin);
	auto nodes = G.findCycle();
	if (nodes.empty()) {
		cout << "YES";
		return 0;
	}
	for (int i = 0, j = 1; i < nodes.size(); ++i, j = (j + 1) % nodes.size()) {
		G.adjM[nodes[i]][nodes[j]] = false;
		if (G.findCycle().empty()) {
			cout << "YES";
			return 0;
		}
		G.adjM[nodes[i]][nodes[j]] = true;
	}
	cout << "NO";
	return 0;
}