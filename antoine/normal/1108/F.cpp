#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank;
	vector<int> parent;
	vector<int> changes;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		changes.push_back(u);
		changes.push_back(v);
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}

	void rollback() {
		for (const int &u : changes) {
			rank[u] = 1;
			parent[u] = u;
		}
		changes.clear();
	}
};

struct Edge {
	int u, v;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	map<int, vector<Edge>> mp;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		mp[w].push_back( { u, v });
	}

	DSU dsu(n + 1);
	DSU dsu2(n + 1);
	int ans = 0;

	for (auto &&entry : mp) {
		for (auto &&e : entry.second) {
			e.u = dsu.find(e.u);
			e.v = dsu.find(e.v);
			if (e.u == e.v)
				continue;
			ans += !dsu2.merge(e.u, e.v);
		}
		for (auto &&e : entry.second)
			dsu.merge(e.u, e.v);
		dsu2.rollback();
	}
	cout << ans;
	return 0;
}