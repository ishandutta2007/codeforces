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

ll x;
int n, d;
int a[ten(5) + 2], b[ten(5) + 2];
ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
void initAB() {
	int i;
	for (i = 0; i < n; i = i + 1) {
		a[i] = i + 1;
	}
	for (i = 0; i < n; i = i + 1) {
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for (i = 0; i < n; i = i + 1) {
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (i = 0; i < n; i = i + 1) {
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}

ll c[ten(5) + 2];

class UnionFind {
	int n;
	vector<int> par;
public:
	UnionFind() {}
	UnionFind(int size) { reset(size); }

	void reset(int size) {
		n = size;
		par.resize(size);
		for (int i = 0; i < size; i++) par[i] = i;
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (x > y) swap(x, y);
		par[x] = y;
		n--;
	}

	bool same(int x, int y) { return find(x) == find(y); }

	int size() { return n; }
};

UnionFind uf;

int main() {
	cin >> n >> d >> x;
	initAB();

	vector<int> nb(n);
	{
		int last = n;
		for (int i = n - 1; i >= 0; i--) {
			if (b[i]) {
				last = i;
			}
			nb[i] = last;
		}
	}

	uf.reset(n + 1);

	vector<Pii> v(n);
	FOR(i, n) {
		v[i].first = a[i];
		v[i].second = i;
	}
	sort(v.rbegin(), v.rend());
	vector<int> c(n);
	FOR(i, n) {
		int a_id = v[i].second;
		int c_id = uf.find(a_id);
		while (c_id < n) {
			int b_id;
			while (c_id < n) {
				b_id = nb[c_id - a_id];
				c_id = a_id + b_id;
				if (c_id >= n) break;
				int tmp = uf.find(c_id);
				if (tmp == c_id) break;
				c_id = tmp;
			}
			if (c_id >= n) break;
			if (b[b_id]) {
				c[c_id] = v[i].first;
				uf.unite(c_id, c_id + 1);
			}
			c_id = uf.find(c_id + 1);
		}
	}

	FOR(i, n) {
		printf("%d\n",c[i]);
	}
}