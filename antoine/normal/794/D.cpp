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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank;
	vector<int> parent;
	int compCnt;

	DSU(int n) : compCnt(n) {
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
		compCnt--;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(11);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DSU dsu(n);
	map<vector<int>, int> groups;
	for (int i = 0; i < n; ++i) {
		adj[i].push_back(i);
		sort(adj[i].begin(), adj[i].end());
		auto it = groups.find(adj[i]);
		if (it == groups.end())
			groups[adj[i]] = i;
		else
			assert(dsu.merge(i, it->second));
	}

	int start = -1;
	for (int i = 0; i < n; ++i) {
		if (dsu.parent[i] == i) {
			adj[i].erase(remove_if(adj[i].begin(), adj[i].end(), [&](int v) {
				return v == i || dsu.parent[v] != v;
			}), adj[i].end());
			if (adj[i].size() > 2) {
				cout << "NO";
				cerr << "no1";
				return 0;
			}
			if (adj[i].size() <= 1)
				start = i;
		}
	}

	if (start == -1) {
		cout << "NO";
		cerr << "no2";
		return 0;
	}

	vector<int> label(n, -1);
	label[start] = 1;
	for (int i = start;;) {
		bool found = false;
		for (int &v : adj[i]) {
			if (label[v] == -1) {
				assert(!found);
				found = true;
				label[v] = label[i] + 1;
				i = v;
			}
		}
		if (!found)
			break;
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		if (dsu.parent[i] != i)
			label[i] = label[dsu.find(i)];
		assert(label[i] != -1);
		cout << label[i] << ' ';
	}
	return 0;
}