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
	multiset<int> compSizes;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		if (rank[u] != 1)
			compSizes.erase(compSizes.find(rank[u]));
		if (rank[v] != 1)
			compSizes.erase(compSizes.find(rank[v]));
		compSizes.insert(rank[u] += rank[v]);
		parent[v] = u;
		return true;
	}

	bool sameCompSizes() {
		return !compSizes.empty() && *compSizes.begin() == *compSizes.rbegin();
	}

	int size(int u) {
		return rank[find(u)];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	map<int, vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}

	int ans = -1;
	int bestCC = -1;
	DSU dsu(n + 1);
	for (auto &&x : mp) {
		for (auto &&y : x.second)
			dsu.merge(y, y + 1);
		if (dsu.sameCompSizes() && (int)dsu.compSizes.size() > bestCC) {
			bestCC = dsu.compSizes.size();
			ans = x.first + 1;
		}
	}
	assert(ans != -1);
	cout << ans;
	return 0;
}