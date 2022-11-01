#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

class UnionFind {
	int n;
	vector<int> par;
	vector<int> rank;
public:
	UnionFind() {}
	UnionFind(int size) { reset(size); }

	void reset(int size) {
		n = size;
		par.resize(size);
		rank.resize(size);
		for (int i = 0; i < size; i++) par[i] = i, rank[i] = 0;
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
		n--;
	}

	bool same(int x, int y) { return find(x) == find(y); }

	int size() { return n; }
};

int n;
int c[2000][2000];

bool fcheck() {
	FOR(i, n) FOR(j, n) {
		if (c[i][j] != c[j][i]) return false;
		if (i == j) {
			if (c[i][i] != 0) return false;
		} else {
			if (c[i][j] == 0) return false;
		}
	}
	return true;
}

vector<Pii> e[2000];

ll tbl[2000];
void dfs(int p, int v, ll cos) {
	tbl[v] = cos;
	for (auto to : e[v]) {
		if (to.first == p) continue;
		dfs(v, to.first, cos + to.second);
	}
}

int main() {
	scanf("%d",&n);
	FOR(i, n) FOR(j, n) {
		scanf("%d", c[i] + j);
	}

	if (!fcheck()) {
		puts("NO");
		return 0;
	}

	vector<Pii> vp;
	FOR(i, n) for (int j = i + 1; j < n; j++) {
		int id = i * n + j;
		vp.emplace_back(c[i][j], id);
	}

	sort(vp.begin(), vp.end());

	UnionFind uf(n);
	for (auto x : vp) {
		int a = x.second % n;
		int b = x.second / n;
		int cost = x.first;
		if (uf.same(a, b)) continue;
		uf.unite(a, b);
		e[a].emplace_back(b, cost);
		e[b].emplace_back(a, cost);
	}

	bool ok = true;
	FOR(i, n) {
		dfs(-1, i, 0);
		FOR(j, n) if (tbl[j] != c[i][j]) {
			ok = false;
		}
		if (!ok) break;
	}

	puts(ok ? "YES" : "NO");

	return 0;
}