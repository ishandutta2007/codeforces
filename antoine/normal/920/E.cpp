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
#include <array>

using namespace std;

struct DSU {
	vector<int> rank;
	vector<int> parent;

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
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};


int n, m;
set<int> adj[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		adj[x].insert(y);
		adj[y].insert(x);
	}

	struct Cmp {
		bool operator()(const int u, const int v) const {
			if (adj[u].size() != adj[v].size())
				return adj[u].size() < adj[v].size();
			return u < v;
		}
	};

	set<int> s;
	for (int i = 0; i < n; ++i)
		s.insert(i);

	DSU dsu(n);
	vector<int> ans;

	while (!s.empty()) {
		const int u = *s.begin();
		s.erase(s.begin());

		if (adj[u].size() == s.size()) {
			ans.push_back(dsu.size(u));
			for (const int v : adj[u]) {
				s.erase(v);
				adj[v].erase(u);
				s.insert(v);
			}
		}
		else
			for (const int v : s)
				if (!adj[u].count(v)) {
					s.erase(v);
					for (auto it = adj[u].begin(); it != adj[u].end();)
						if (!adj[v].count(*it)) {
							s.erase(*it);
							adj[*it].erase(u);
							s.insert(*it);
							it = adj[u].erase(it);
						}
						else
							++it;

					for (const int x : adj[v]) {
						s.erase(x);
						adj[x].erase(v);
						s.insert(x);
					}
					dsu.merge(u, v);
					s.insert(u);
					break;
				}

	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto &&x : ans)
		cout << x << ' ';
	return 0;
}