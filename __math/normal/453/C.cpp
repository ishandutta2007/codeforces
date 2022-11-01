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

int n, m;

UnionFind uf;
vector<int> e1[ten(5)];
int x[ten(5)];

int check() {
	int par_id = -1;
	FOR(i, n) {
		if (x[i]) {
			int se = uf.find(i);
			if (par_id != -1 && par_id != se) return -2;
			par_id = se;
		}
	}
	return par_id;
}

vector<int> e2[ten(5)];
bool used1[ten(5)];
bool child_colored[ten(5)];

bool dfs1(int par,int v) {
	used1[v] = true;
	if (par != -1) e2[par].push_back(v);
	bool ret = (x[v] == 1);
	for (auto p : e1[v]) {
		if (used1[p]) continue;
		ret |= dfs1(v, p);
	}
	return child_colored[v] = ret;
}
vector<int> ans;

bool dfs2(int par, int v) {
	int cnt = 0;
	ans.push_back(v);
	cnt++;
	for (auto p : e2[v]) {
		if (!child_colored[p]) continue;
		bool val = dfs2(v, p);
		ans.push_back(v);
		cnt++;
		if (val) {
			ans.push_back(p);
			ans.push_back(v);
			cnt++;
		}
	}
	if ((cnt&1) ^ x[v]) return true;
	else return false;
}

void solve(int root) {
	dfs1(-1, root);
	bool root_b = dfs2(-1, root);
	if (root_b) ans.pop_back();
}

int main() {
	scanf("%d%d", &n, &m);
	uf.reset(n);
	FOR(i, m) {
		int u, v; scanf("%d%d",&u,&v);
		u--; v--;
		uf.unite(u, v);
		e1[u].push_back(v);
		e1[v].push_back(u);
	}
	FOR(i, n) {
		scanf("%d", x + i);
	}

	int root = check();
	if (root == -2) {
		puts("-1");
	} else if (root == -1) {
		puts("0");
	} else {
		solve(root);
		printf("%d\n",sz(ans));
		FOR(i, sz(ans)) {
			printf("%d%c",ans[i] + 1,sz(ans) == i+1?'\n':' ');
		}
	}
}