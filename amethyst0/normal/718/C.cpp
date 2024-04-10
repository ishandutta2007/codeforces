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

using namespace std;

#define ll long long

const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

struct mat {
	ll a[2][2];
};

mat operator +(mat a, mat b) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a.a[i][j] += b.a[i][j];

			if (a.a[i][j] >= mod) {
				a.a[i][j] -= mod;
			}
		}
	}

	return a;
}

mat operator *(mat a, mat b) {
	mat c;
	memset(c.a, 0, sizeof c.a);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c.a[i][j] += a.a[i][k] * b.a[k][j];
				c.a[i][j] %= mod;
			}
		}
	}

	return c;
}

mat my_pow(mat a, ll y) {
	if (y == 1) {
		return a;
	}

	if (y & 1) {
		return (a * my_pow(a, y - 1));
	}

	mat t = my_pow(a, y >> 1);

	return t * t;
}

mat t[4 * maxn];
mat st[4 * maxn];
bool fl[4 * maxn];

void sets(int it, mat f) {
	st[it] = st[it] * f;
	t[it] = t[it] * f;
	fl[it] = true;
}

void push(int it) {
	if (fl[it]) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		fl[it] = false;
		st[it].a[0][0] = 1;
		st[it].a[1][0] = 0;
		st[it].a[0][1] = 0;
		st[it].a[1][1] = 1;
	}
}

void change(int it, int l, int r, int lm, int rm, mat a) {
	if (l == lm && r == rm) {
		sets(it, a);
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, a);
		} else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, a);
		} else {
			change(2 * it, l, m, lm, m, a);
			change(2 * it + 1, m + 1, r, m + 1, rm, a);
		}

		t[it] = t[2 * it] + t[2 * it + 1];
	}
}

mat go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		} else {
			return go(2 * it, l, m, lm, m) + go(2 * it + 1, m + 1, r, m + 1, rm);
		}
	}
}

mat v[maxn];

void build(int it, int l, int r) {
	st[it].a[0][0] = 1;
	st[it].a[1][1] = 1;
	st[it].a[1][0] = 0;
	st[it].a[0][1] = 0;
	if (l == r) {
		t[it] = v[l];
	} else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		t[it] = t[2 * it] + t[2 * it + 1];
	}
}

mat fib;

int main() {
	fib.a[0][0] = 1;
	fib.a[0][1] = 1;
	fib.a[1][0] = 1;
	fib.a[1][1] = 0;

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		v[i] = my_pow(fib, x);
	}

	build(1, 0, n - 1);

	while (m--) {
		int tp, l, r;

		scanf("%d %d %d", &tp, &l, &r);
		l--;
		r--;

		if (tp == 1) {
			int x;

			scanf("%d", &x);

			change(1, 0, n - 1, l, r, my_pow(fib, x));
		} else {
			mat a = go(1, 0, n - 1, l, r);

			printf("%lld\n", a.a[0][1]);
		}
	}

	return 0;
}