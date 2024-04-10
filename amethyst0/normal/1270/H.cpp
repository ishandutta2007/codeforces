//#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;
const int inf = maxn - 1;

bool active[maxn];
pii t[2][4 * maxn];
int st[4 * maxn];

pii recalc(pii a, pii b) {
	if (a.first < b.first) {
		return a;
	}

	if (a.first > b.first) {
		return b;
	}

	return mp(a.first, a.second + b.second);
}

void build(int it, int l, int r) {
	if (l == r) {
		if (active[l]) {
			t[0][it] = mp(0, 1);
			t[1][it] = mp(inf, 1);
		}
		else {
			t[0][it] = mp(inf, 1);
			t[1][it] = mp(0, 1);
		}
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[0][it] = recalc(t[0][2 * it], t[0][2 * it + 1]);
		t[1][it] = recalc(t[1][2 * it], t[1][2 * it + 1]);
	}
}

void sets(int it, int x) {
	st[it] += x;
	t[0][it].first += x;
	t[1][it].first += x;
}

void push(int it) {
	if (st[it] != 0) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		st[it] = 0;
	}
}

void change(int it, int l, int r, int pos) {
	if (l == r) {
		active[l] ^= 1;
		swap(t[0][it], t[1][it]);
	}
	else {
		push(it);
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos);
		}
		else {
			change(2 * it + 1, m + 1, r, pos);
		}

		t[0][it] = recalc(t[0][2 * it], t[0][2 * it + 1]);
		t[1][it] = recalc(t[1][2 * it], t[1][2 * it + 1]);
	}
}

void change(int it, int l, int r, int lm, int rm, int x) {
	if (l == lm && r == rm) {
		sets(it, x);
	}
	else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, x);
		}
		else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, x);
		}
		else {
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
		}

		t[0][it] = recalc(t[0][2 * it], t[0][2 * it + 1]);
		t[1][it] = recalc(t[1][2 * it], t[1][2 * it + 1]);
	}
}

int v[maxn];

void upd(int i, int x) {
	int l = min(v[i], v[i + 1]);
	int r = max(v[i], v[i + 1]);
	l++;
	change(1, 0, maxn - 1, l, r, x);
}

int main() {
	int n, q;

	cin >> n >> q;

	v[0] = inf;
	v[n + 1] = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		active[v[i]] = true;
	}

	build(1, 0, maxn - 1);

	for (int i = 0; i <= n; i++) {
		upd(i, 1);
	}

	while (q--) {
		int pos, x;

		scanf("%d %d", &pos, &x);

		change(1, 0, maxn - 1, v[pos]);
		change(1, 0, maxn - 1, x);

		upd(pos - 1, -1);
		upd(pos, -1);

		v[pos] = x;

		upd(pos - 1, 1);
		upd(pos, 1);

		printf("%d\n", t[0][1].second);
	}
}