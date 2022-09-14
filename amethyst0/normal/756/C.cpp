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
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];
int t[4 * maxn];
int st[4 * maxn];

void sets(int it, int x) {
	t[it] += x;
	st[it] += x;
}

void push(int it) {
	if (st[it] != 0) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		st[it] = 0;
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

		t[it] = max(t[2 * it], t[2 * it + 1]);
	}
}

int go(int it, int l, int r) {
	if (l == r) {
		return v[l];
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (t[2 * it + 1] > 0) {
			return go(2 * it + 1, m + 1, r);
		}

		return go(2 * it, l, m);
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int p, tp, x;

		scanf("%d %d", &p, &tp);
		if (tp == 1) {
			scanf("%d", &x);
		}
		v[p] = x;

		if (tp == 0) {
			change(1, 1, n, 1, p, -1);
		} else {
			change(1, 1, n, 1, p, +1);
		}

		if (t[1] <= 0) {
			printf("-1\n");
		} else {
			printf("%d\n", go(1, 1, n));
		}
	}

	return 0;
}