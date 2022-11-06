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
#include <stack>

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;

	DSU dsu(26);

	set<pair<int, int>> edges;
	for (int i = 0; i < n; ++i) {
		dsu.merge(s1[i] - 'a', s2[i] - 'a');
	}

	map<int, vector<char>> comps;
	for (int i = 0; i < 26; ++i)
		comps[dsu.find(i)].push_back(i + 'a');

	int ans = 0;
	for (auto &&x : comps)
		ans += x.second.size() - 1;
	cout << ans << '\n';
	for (auto &&x : comps)
		for (int i = 0; i + 1 < x.second.size(); ++i) {
			cout << x.second[i] << ' ' << x.second[i + 1] << '\n';
		}
	return 0;
}