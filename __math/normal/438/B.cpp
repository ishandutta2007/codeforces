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
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

class UnionFind {
	int n;
	vector<int> par;
public:
	vector<int> num;
	UnionFind() {}
	UnionFind(int size) { reset(size); }

	void reset(int size) {
		n = size;
		par.resize(size);
		num.resize(size);
		for (int i = 0; i < size; i++) par[i] = i, num[i] = 1;
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) assert(false);
		if (x < y) swap(x, y);
		par[x] = y;
		num[y] += num[x];
		n--;
	}

	bool same(int x, int y) { return find(x) == find(y); }

	int size() { return n; }
};

vector<int> e[ten(5)];
int a[ten(5)];

double f(double x) {
	return x * (x - 1);
}

int main() {
	int n, m; cin >> n >> m;
	FOR(i, n) cin >> a[i];
	FOR(i, m) {
		int x, y; cin >> x >> y;
		x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	vector<Pii> vp;
	FOR(i, n) vp.emplace_back(a[i], i);
	sort(vp.rbegin(), vp.rend());
	UnionFind uf(n);
	double ans = 0;

	FOR(i, n) {
		int pt = vp[i].second;
		double prev_cnt = f(uf.num[uf.find(pt)]);
		for (auto p : e[pt]) {
			if (vp[i].first > a[p]) continue;
			if (uf.same(pt, p)) continue;
			double prv = f(uf.num[uf.find(p)]);
			prev_cnt += prv;
			uf.unite(pt, p);
		}
		double now = f(uf.num[uf.find(pt)]);
		double cnt = now - prev_cnt;
		double add = cnt * vp[i].first;
		ans += add;
	}

	ans /= f(n);


	printf("%.10lf\n",ans);
}