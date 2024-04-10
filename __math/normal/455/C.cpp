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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
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

struct P{
	int center;
	P() {}
};

vector<int> e[ten(5) * 3 + 10];

Pii dfs(int p, int v) {
	Pii ret(0, v);
	for (auto to : e[v]) if (to != p) {
		Pii tmp = dfs(v, to);
		tmp.first++;
		if (ret.first < tmp.first) ret = tmp;
	}
	return ret;
}

int diameter(int v) {
	Pii x = dfs(-1, v);
	Pii y = dfs(-1, x.second);
	return y.first;
}

int main() {
	int n, m, q;
	scanf("%d%d%d",&n,&m,&q);
	
	UnionFind uf(n);
	FOR(i, m) {
		int a, b; scanf("%d%d",&a,&b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
		uf.unite(a, b);
	}

	map<int,int> tree2diamenter;

	FOR(i, n) {
		if (uf.find(i) != i) continue;
		tree2diamenter[i] = diameter(i);
	}
	FOR(i, q) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int x; scanf("%d",&x);
			x--;
			x = uf.find(x);

			printf("%d\n", tree2diamenter[uf.find(x)]);
		} else {
			int x,y; scanf("%d%d", &x, &y);
			x--; y--;
			if (uf.same(x, y)) continue;
			x = uf.find(x);
			y = uf.find(y);

			int l = tree2diamenter[x];
			int r = tree2diamenter[y];
			tree2diamenter.erase(x);
			tree2diamenter.erase(y);

			uf.unite(x, y);
			int nw = uf.find(x);
			tree2diamenter[nw] = max((l + 1) / 2 + (r + 1) / 2 + 1,max(l,r));
		}
	}
}