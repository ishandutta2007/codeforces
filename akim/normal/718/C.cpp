#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

pair<pair<int, int>, pair<int, int> > deo[4 * maxn], add[4 * maxn];

pair<pair<int, int>, pair<int, int> > sum(pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b) {
	return (mp(mp((a.fs.fs + b.fs.fs) % mod, (a.fs.sc + b.fs.sc) % mod), mp((a.sc.fs + b.sc.fs) % mod, (a.sc.sc + b.sc.sc) % mod)));
}
pair<pair<int, int>, pair<int, int> > mul(pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b) {
	return (mp(mp((a.fs.fs * 1ll * b.fs.fs + a.fs.sc * 1ll * b.sc.fs) % mod, (a.fs.fs * 1ll * b.fs.sc + a.fs.sc * 1ll * b.sc.sc) % mod), mp((a.sc.fs * 1ll * b.fs.fs + a.sc.sc * 1ll * b.sc.fs) % mod, (a.sc.fs * 1ll * b.fs.sc + a.sc.sc * 1ll * b.sc.sc) % mod)));
}

pair<pair<int, int>, pair<int, int> > binpow(int b, pair<pair<int, int>, pair<int, int> > a = mp(mp(0, 1), mp(1, 1))) {
	pair<pair<int, int>, pair<int, int> > ret = mp(mp(1, 0), mp(0, 1));
	if (b < 0)
		return (ret);
	while (b) {
		if (b & 1) {
			ret = mul(ret, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return (ret);
}

int a[maxn];

void build(int v = 0, int tl = 0, int tr = maxn - 1) {
	if (tl == tr) {
		deo[v] = binpow(a[tl] - 1);
		add[v] = mp(mp(1, 0), mp(0, 1));
		deo[v] = mul(deo[v], add[v]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	add[v] = mp(mp(1, 0), mp(0, 1));
	deo[v] = sum(deo[v * 2 + 1], deo[v * 2 + 2]);
	deo[v] = mul(deo[v], add[v]);
}

pair<pair<int, int>, pair<int, int> > get(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (rg < tl || tr < lf) {
		return (mp(mp(0, 0), mp(0, 0)));
	}
	if (lf <= tl && tr <= rg) {
		return (deo[v]);
	}
	int tm = (tl + tr) >> 1;
	pair<pair<int, int>, pair<int, int>> p = sum(get(lf, rg, v * 2 + 1, tl, tm), get(lf, rg, v * 2 + 2, tm + 1, tr));
	p = mul(p, add[v]);
	return (p);
}

void upd(int lf, int rg, pair<pair<int, int>, pair<int, int> > x, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (rg < tl || tr < lf) {
		return;
	}
	if (lf <= tl && tr <= rg) {
		add[v] = mul(add[v], x);
		deo[v] = mul(deo[v], x);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(lf, rg, x, v * 2 + 1, tl, tm);
	upd(lf, rg, x, v * 2 + 2, tm + 1, tr);
	deo[v] = sum(deo[v * 2 + 1], deo[v * 2 + 2]);
	deo[v] = mul(deo[v], add[v]);
}

int main() {

	#ifdef SOL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	#else
	srand(time(0));
	const string file = "";
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	build();
	for (; m--;) {
		int ty;
		scanf("%d", &ty);
		if (ty == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			l--, r--;
			pair<pair<int, int>, pair<int, int> > p = get(l, r);
			printf("%d\n", p.sc.sc);
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--, r--;
			pair<pair<int, int>, pair<int, int> > xx = binpow(x);
			upd(l, r, xx);
		}
	}
	return (0);
}

// by Andrey Kim