#include <stdio.h>
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

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void initialization() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 300100;

int n;
ll a[maxn];

struct deov {
	ll lv, rv, mv;
} deo[4 * maxn];

void recalc(int v, int tl, int tr) {
	int tm = (tl + tr) >> 1;
	deo[v].mv = max(deo[v * 2 + 1].mv, deo[v * 2 + 2].mv);
	if (!a[tm] || !a[tm + 1] || ((a[tm] < 0) && (a[tm + 1] > 0))) {
		deo[v].rv = deo[v * 2 + 2].rv;
		deo[v].lv = deo[v * 2 + 1].lv;
	} else {
		deo[v].mv = max(deo[v].mv, deo[v * 2 + 1].rv + deo[v * 2 + 2].lv);
		if (deo[v * 2 + 1].mv == tm - tl + 1) {
			deo[v].lv = deo[v * 2 + 1].mv + deo[v * 2 + 2].lv;
		} else {
			deo[v].lv = deo[v * 2 + 1].lv;
		}
		if (deo[v * 2 + 2].mv == tr - tm) {
			deo[v].rv = deo[v * 2 + 2].mv + deo[v * 2 + 1].rv;
		} else {
			deo[v].rv = deo[v * 2 + 2].rv;
		}
	}
}

void build(int v = 0, int tl = 0, int tr = n - 1) {
	if (tr < tl)
		return;
	if (tl == tr) {
		deo[v].mv = !!a[tl];
		deo[v].lv = deo[v].mv;
		deo[v].rv = deo[v].mv;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	recalc(v, tl, tr);
}

void upd(int pos, int val, int v = 0, int tl = 0, int tr = n - 1) {
	if (pos < tl || pos > tr) {
		return;
	}
	if (tl == tr) {
		a[tl] += val;
		deo[v].mv = !!a[tl];
		deo[v].lv = deo[v].mv;
		deo[v].rv = deo[v].mv;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(pos, val, v * 2 + 1, tl, tm);
	upd(pos, val, v * 2 + 2, tm + 1, tr);
	recalc(v, tl, tr);
}

int solution() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	n--;
	for (int i = 0; i < n; i++) {
		a[i] = a[i + 1] - a[i];
	}
	build();

	int m;
	scanf("%d", &m);
	for (; m--;) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		l--, r--;
		upd(l - 1, d);
		upd(r, -d);
		printf("%lld\n", deo[0].mv + 1);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim