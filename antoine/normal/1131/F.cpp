#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/contest/1131/problem/F
struct DSU {
	vector<int> rank;
	vector<int> parent;
	vector<vector<int>> nodes;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		nodes.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			nodes[i] = {i};
		}
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
		return false;
		if (rank[u] <= rank[v])
		swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		nodes[u].insert(nodes[u].end(), nodes[v].begin(), nodes[v].end());
		nodes[v].clear();
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	DSU dsu(n + 1);

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;

		assert(dsu.merge(u, v));
	}

	for (int x : dsu.nodes[dsu.find(1)]) {
		cout << x << ' ';
	}
	return 0;
}