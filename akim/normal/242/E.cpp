#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

int deo[22][4 * 100100], a[100100], b[100100], n;
bool izm[22][4 * 100100];

void build(int *deo, bool *izm, int *a, int v = 0, int tl = 0, int tr = n - 1) {
	if(tl == tr) {
		deo[v] = a[tl];
		izm[v] = 0;
	} else {
		int tm = (tl + tr) / 2;
		build(deo, izm, a, v * 2 + 1, tl, tm);
		build(deo, izm, a, v * 2 + 2, tm + 1, tr);
		int s = deo[v * 2 + 1] + deo[v * 2 + 2];
		deo[v] = s;
		izm[v] = 0;
	}
}

int getsum(int *deo, bool *izm, int l, int r, int v = 0, int tl = 0, int tr = n - 1) {
	if(l > r) {
		return(0);
	}
	if(tl == l && tr == r) {
		return(deo[v]);
	} else {
		int tm = (tl + tr) / 2;
		if(izm[v]) {
			izm[v] = 0;
			izm[v * 2 + 1] ^= 1;
			izm[v * 2 + 2] ^= 1;
			deo[v * 2 + 1] = tm - tl + 1 - deo[v * 2 + 1];
			deo[v * 2 + 2] = tr - tm - deo[v * 2 + 2];
		}
		int s = getsum(deo, izm, l, min(tm, r), v * 2 + 1, tl, tm) + getsum(deo, izm, max(l, tm + 1), r, v * 2 + 2, tm + 1, tr);
		return (s);
	}
}

void upd(int *deo, bool *izm, int l, int r, int v = 0, int tl = 0, int tr = n - 1) {
	if(l > r) {
		return;
	}
	if(tl == l && tr == r) {
		izm[v] = !izm[v];
		deo[v] = tr - tl + 1 - (deo[v]);
		//cout<<l<<" "<<r<<" "<<deo[v];
	} else {
		int tm = (tl + tr) / 2;
		if(izm[v]) {
			izm[v] = 0;
			izm[v * 2 + 1] ^= 1;
			izm[v * 2 + 2] ^= 1;
			deo[v * 2 + 1] = tm - tl + 1 - deo[v * 2 + 1];
			deo[v * 2 + 2] = tr - tm - deo[v * 2 + 2];
		}
		upd(deo, izm, l, min(tm, r), v * 2 + 1, tl, tm);
		upd(deo, izm, max(l, tm + 1), r, v * 2 + 2, tm + 1, tr);
		int s = deo[v * 2 + 1] + deo[v * 2 + 2];
		deo[v] = s;
	}
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for(long long i = 0, st = 1; i < 22; i++, st <<= 1) {
		for(int f = 0; f < n; f++) {
			b[f] = (bool)(a[f] & st);

		}
		build(deo[i], izm[i], b);
	}

	int m; scanf("%d", &m);
	for(; m > 0; m--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int l, r; scanf("%d%d", &l ,&r); l--, r--;
			long long otv = 0;
			for(long long i = 0, st = 1; i < 22; i++, st <<= 1) {
				long long s = getsum(deo[i], izm[i], l, r);
				otv += st * s;
			}
			printf("%I64d\n", otv);
		} else {
			int l, r, x; scanf("%d%d%d", &l, &r ,&x); l--, r--;
			for(long long i = 0, st = 1; i < 22; i++, st <<= 1) {
				if(x & 1) {
					upd(deo[i], izm[i], l, r);
				}
				x >>= 1;
			}
		}
	}

	return(0);
}

// by Kim Andrey