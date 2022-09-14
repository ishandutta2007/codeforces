/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
 
#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
 
using namespace std;

const int maxn = (int)3e5 + 10;
int t[4 * maxn];

void sets(int it, int x) {
	t[it] += x;
}

void push(int it) {
	if (t[it] != 0) {
		sets(2 * it, t[it]);
		sets(2 * it + 1, t[it]);
		t[it] = 0;
	}
}

void change(int it, int l, int r, int lm, int rm, int x) {
	if (l == lm && r == rm) {
		sets(it, x);
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, x);
		} else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, x);
		} else {
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
		}
	}
}

int v[maxn];

void make(int it, int l, int r) {
	if (l == r) {
		v[l] = t[it];
	} else {
		push(it);
		int m = (l + r) >> 1;

		make(2 * it, l, m);
		make(2 * it + 1, m + 1, r);
	}
}

pair <pll, pll> tr[4 * maxn];

pair <pll, pll> merg(pair <pll, pll> a, pair <pll, pll> b) {
	pair <pll, pll> c;

	c.second.second = max(max(a.second.second, b.second.second), a.first.second + b.first.first);
	c.second.first = a.second.first + b.second.first;
	c.first.first = max(a.first.first, a.second.first + b.first.first);
	c.first.second = max(b.first.second, b.second.first + a.first.second);

	return c;
}

ll z[maxn];

void build(int it, int l, int r) {
	if (l == r) {
		tr[it] = mp(mp(z[l], z[l]), mp(z[l], z[l]));
		if (z[l] < 0) {
			tr[it] = mp(mp(0, 0), mp(z[l], 0));
		}
	} else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		tr[it] = merg(tr[2 * it], tr[2 * it + 1]);
	}
}

pair <pll, pll> go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return tr[it];
	} else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		} else {
			return merg(go(2 * it, l, m, lm, m), go(2 * it + 1, m + 1, r, m + 1, rm));
		}
	}
}

int x[maxn];
int p[maxn];
int l[maxn], r[maxn];

int main() {
	int n, m, c;

	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < m; i++) {
		int lm, rm;

		scanf("%d %d", &lm, &rm);
		lm--;
		rm--;

		change(1, 0, n - 1, lm, rm - 1, 1);

		l[i] = lm;
		r[i] = rm - 1;
	}

	make(1, 0, n - 1);

	for (int i = 0; i < n - 1; i++) {
		z[i] = (50 * (x[i + 1] - x[i]) - p[i] * c);
	}

	build(1, 0, n - 2);

	ll ans = 0;
	
	for (int i = 0; i < m; i++) {
		pair <pll, pll> f = go(1, 0, n - 2, l[i], r[i]);

		ans += f.second.second;
	}

	printf("%.10lf\n", (double)ans / 100);

	return 0;
}