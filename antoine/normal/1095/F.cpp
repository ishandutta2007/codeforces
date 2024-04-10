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

const int MaxN = (int) 2e5 + 9;
int parent[MaxN + 9];
ll a[MaxN + 9];
int nxt[MaxN + 9];

struct DSU {
	int numComps;

	DSU(int n) {
		numComps = n;
		for (int i = 1; i <= n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		--numComps;
		parent[v] = u;
		return true;
	}
};

struct Edge {
	int u, v;
	ll w;

	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	vector<Edge> edges;

	while (m--) {
		int x, y;
		ll w;
		cin >> x >> y >> w;
		edges.push_back( { x, y, w });
	}

	{
		const int c = min_element(a + 1, a + 1 + n) - a;
		for (int i = 1; i <= n; ++i)
			edges.push_back( { i, c, a[i] + a[c] });
	}

	sort(edges.begin(), edges.end());

	DSU dsu(n);
	ll ans = 0;

	for(const Edge &e : edges) {
		if(dsu.numComps == 1) break;
		if(dsu.merge(e.u, e.v))
			ans += e.w;
	}

	cout << ans;
	return 0;
}