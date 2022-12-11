#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;
const int N = int(2e5) + 20, mod = int(1e9) + 7;

struct deov {
	ll mn0, mn1, rg, ad;
};

int a[N];
deov deo[4 * N];

void build(int v = 0, int tl = 0, int tr = N - 1) {
	if (tl == tr) {
		deo[v].mn0 = a[tl];
		deo[v].mn1 = mod * 1ll * mod;
		deo[v].rg = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	ll lmn0 = deo[v * 2 + 1].mn0, lmn1 = deo[v * 2 + 1].mn1, lrg = deo[v * 2 + 1].rg;
	ll rmn0 = deo[v * 2 + 2].mn0, rmn1 = deo[v * 2 + 2].mn1, rrg = deo[v * 2 + 2].rg;
	rmn0 -= lrg;
	rmn1 += lrg;
	if ((tm - tl + 1) & 1) {
		deo[v].mn0 = min(lmn0, rmn1);
		deo[v].mn1 = min(lmn1, rmn0);
	} else {
		deo[v].mn0 = min(lmn0, rmn0);
		deo[v].mn1 = min(lmn1, rmn1);
	}
	if ((tr - tm) & 1) {
		rrg -= lrg;
	} else {
		rrg += lrg;
	}
	deo[v].rg = rrg;

	deo[v].mn0 += deo[v].ad;
	if ((tr - tl + 1) & 1)
		deo[v].rg += deo[v].ad;

	return;
}
void add(int lf, int rg, ll val, int v = 0, int tl = 0, int tr = N - 1) {
	if (tr < lf || rg < tl)
		return;
	if (tl == tr) {
		deo[v].mn0 += val;
		deo[v].rg += val;
		return;
	}
	if (lf <= tl && tr <= rg) {
		int tm = (tl + tr) >> 1;
		deo[v].ad += val;
		ll lmn0 = deo[v * 2 + 1].mn0, lmn1 = deo[v * 2 + 1].mn1, lrg = deo[v * 2 + 1].rg;
		ll rmn0 = deo[v * 2 + 2].mn0, rmn1 = deo[v * 2 + 2].mn1, rrg = deo[v * 2 + 2].rg;
		rmn0 -= lrg;
		rmn1 += lrg;
		if ((tm - tl + 1) & 1) {
			deo[v].mn0 = min(lmn0, rmn1);
			deo[v].mn1 = min(lmn1, rmn0);
		} else {
			deo[v].mn0 = min(lmn0, rmn0);
			deo[v].mn1 = min(lmn1, rmn1);
		}
		if ((tr - tm) & 1) {
			rrg -= lrg;
		} else {
			rrg += lrg;
		}
		deo[v].rg = rrg;

		deo[v].mn0 += deo[v].ad;
		if ((tr - tl + 1) & 1)
			deo[v].rg += deo[v].ad;
		return;
	}
	int tm = (tl + tr) >> 1;
	add(lf, rg, val, v * 2 + 1, tl, tm);
	add(lf, rg, val, v * 2 + 2, tm + 1, tr);
	ll lmn0 = deo[v * 2 + 1].mn0, lmn1 = deo[v * 2 + 1].mn1, lrg = deo[v * 2 + 1].rg;
	ll rmn0 = deo[v * 2 + 2].mn0, rmn1 = deo[v * 2 + 2].mn1, rrg = deo[v * 2 + 2].rg;
	rmn0 -= lrg;
	rmn1 += lrg;
	if ((tm - tl + 1) & 1) {
		deo[v].mn0 = min(lmn0, rmn1);
		deo[v].mn1 = min(lmn1, rmn0);
	} else {
		deo[v].mn0 = min(lmn0, rmn0);
		deo[v].mn1 = min(lmn1, rmn1);
	}
	if ((tr - tm) & 1) {
		rrg -= lrg;
	} else {
		rrg += lrg;
	}
	deo[v].rg = rrg;

	deo[v].mn0 += deo[v].ad;
	if ((tr - tl + 1) & 1)
		deo[v].rg += deo[v].ad;
	return;
}

ll grg;
bool ok;
void get(int lf, int rg, int v = 0, int tl = 0, int tr = N - 1, ll sad = 0) {
	if (tr < lf || rg < tl)
		return;
	if (lf <= tl && tr <= rg) {
		ll cmn0 = deo[v].mn0 - grg + sad, cmn1 = deo[v].mn1 + grg, crg = deo[v].rg;
		if ((tr - tl + 1) & 1) {
			crg -= grg;
			crg += sad;
		} else {
			crg += grg;
		}
		ll cmn = min(cmn0, cmn1);
		if (cmn < 0)
			ok = 0;
		if (tr == rg) {
			if (crg != 0) {
				ok = 0;
			}
		}
		grg = crg;
		return;
	}
	int tm = (tl + tr) >> 1;
	get(lf, rg, v * 2 + 1, tl, tm, sad + deo[v].ad);
	get(lf, rg, v * 2 + 2, tm + 1, tr, sad + deo[v].ad);
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}

	build();

	int q;
	scanf("%d", &q);
	for (; q--;) {
		int z;
		scanf("%d", &z);
		if (z == 1) {
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			add(l, r, v);
		}
		if (z == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			grg = 0, ok = 1;
			get(l, r);
			printf("%d\n", ok);
		}
	}

	return 0;
}