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
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank;
	vector<int> parent;
	int numComps;

	DSU(int n) : numComps(n) {
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
		numComps--;
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	DSU dsu(n + m);
	for (int i = 0; i < q; ++i) {
		int r, c;
		cin >> r >> c;
		--r, --c;
		dsu.merge(r, n + c);
	}
	cout << dsu.numComps - 1;
	return 0;
}