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

struct State {
	bool ex[4];
	bool deg[4];
	bool adj[4][4];
	
	State() {
		memset(ex, 0, sizeof 0);
		memset(deg, 0, sizeof deg);
		memset(adj, 0, sizeof adj);
	}

	State connect(const int u, const int v) const {
		State other = *this;
		other.ex[u] = other.ex[v] = 1;
		other.deg[u] ^= 1;
		other.deg[v] ^= 1;
		if (u != v)
			other.adj[min(u, v)][max(u, v)] = 1;
		return other;
	}

	bool ok() const {
		if (count(deg, deg + 4, 1) > 2)
			return false;

		DSU dsu(4);
		for (int i = 0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j)
				if (adj[i][j])
					dsu.merge(i, j);


		for (int i = 0; i < 4; ++i)
			for (int j = i + 1; j < 4; ++j)
				if (ex[i] && ex[j] && dsu.find(i) != dsu.find(j))
					return false;

		return true;
	}

	int h() const {
		int res = 0;
		for (auto &&x : ex)
			res = res << 1 | x;
		for (auto &&x : deg)
			res = res << 1 | x;
		for (auto &&x : adj)
			for (auto &&y : x)
				res = res << 1 | y;
		return res;
	}
};

int n;
map<int, ll> dp[101];
int val[100];
int c1[100];
int c2[100];

ll f(const int i, const State state) {
	if (dp[i].count(state.h()))
		return dp[i].at(state.h());

	ll &res = dp[i][state.h()];
	if (i == n)
		return res = state.ok() ? 0 : -(1LL << 60);

	return res = max(f(i + 1, state), val[i] + f(i+1, state.connect(c1[i], c2[i])));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// const int M = 1 << (4 + 4 + 4 * 2 / 2);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c1[i] >> val[i] >> c2[i];
		--c1[i], --c2[i];
	}
	cout << f(0, State());
	return 0;
}