/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
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
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)3e5 + 10;

ll t[4 * maxn];

void sets(int it, ll x) {
	t[it] += x;
}

void push(int it) {
	if (t[it] != 0) {
		sets(2 * it, t[it]);
		sets(2 * it + 1, t[it]);
		t[it] = 0;
	}
}

void change(int it, int l, int r, int lm, int rm, ll x) {
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

ll go(int it, int l, int r, int pos) {
	if (l == r) {
		return t[it];
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (pos <= m) {
			return go(2 * it, l, m, pos);
		} else {
			return go(2 * it + 1, m + 1, r, pos);
		}
	}
}

const int inf = (int)1e9;

int v[maxn];
int f[maxn];

pair <pii, int> tr[4 * maxn];

void change(int it, int l, int r, int pos, int x) {
	if (l == r) {
		if (x == 1) {
			tr[it] = mp(mp(1, 1), 1);
		} else {
			tr[it] = mp(mp(0, 0), 0);
		}
	} else {
		int m = (l + r) >> 1;

		if (pos <= m) {
			change(2 * it, l, m, pos, x);
		} else {
			change(2 * it + 1, m + 1, r, pos, x);
		}

		if (tr[2 * it].first.first != m - l + 1) {
			tr[it].first.first = tr[2 * it].first.first;
		} else {
			tr[it].first.first = tr[2 * it].first.first + tr[2 * it + 1].first.first;
		}

		if (tr[2 * it + 1].first.second != r - m) {
			tr[it].first.second = tr[2 * it + 1].first.second;
		} else {
			tr[it].first.second = tr[2 * it + 1].first.second + tr[2 * it].first.second;
		}

		tr[it].second = max(max(tr[2 * it].second, tr[2 * it + 1].second), tr[2 * it].first.second + tr[2 * it + 1].first.first);
	}
}

int n, m;

bool check(int a, int b) {
	return (a == 0 && b != 2) || (a == 1 && b == 1);
}

int sum[3];

void make(int pos, ll x, ll y) {
	sum[f[pos]]--;
	if (x < y) {
		f[pos] = 0;
		sum[0]++;
	} else if (x == y) {
		f[pos] = 2;
		sum[2]++;
	} else {
		f[pos] = 1;
		sum[1]++;
	}

	if (pos != 0) {
		if (check(f[pos - 1], f[pos])) {
			change(1, 0, n - 1, pos - 1, 1);
		} else {
			change(1, 0, n - 1, pos - 1, 0);
		}
	}

	if (pos != n - 1) {
		if (check(f[pos], f[pos + 1])) {
			change(1, 0, n - 1, pos, 1);
		} else {
			change(1, 0, n - 1, pos, 0);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		v[i] = x;

		change(1, 0, n - 1, i, i, x);
	}

	for (int i = 0; i < n - 1; i++) {
		if (v[i] > v[i + 1]) {
			f[i] = 1;
		} else if (v[i] < v[i + 1]) {
			f[i] = 0;
		} else {
			f[i] = 2;
		}

		sum[f[i]]++;
	}

	for (int i = 0; i < n - 2; i++) {
		if (f[i] == 0 && f[i + 1] != 2) {
			change(1, 0, n - 1, i, 1);
		} else if (f[i] == 1 && f[i + 1] == 1) {
			change(1, 0, n - 1, i, 1);
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int l, r, d;

		scanf("%d %d %d", &l, &r, &d);
		l--;
		r--;

		change(1, 0, n - 1, l, r, d);

		if (l != 0) {
			ll x = go(1, 0, n - 1, l - 1);
			ll y = go(1, 0, n - 1, l);

			make(l - 1, x, y);
		}

		if (r != n - 1) {
			ll x = go(1, 0, n - 1, r);
			ll y = go(1, 0, n - 1, r + 1);

			make(r, x, y);
		}

		if (n == 1) {
			printf("1\n");
		} else if (n == 2) {
			ll x = go(1, 0, n - 1, 0);
			ll y = go(1, 0, n - 1, 1);

			if (x != y) {
				printf("2\n");
			} else {
				printf("1\n");
			}
		} else {
			if (tr[1].second != 0) {
				printf("%d\n", tr[1].second + 2);
			} else if (sum[1] != 0 || sum[0] != 0) {
				printf("2\n");
			} else {
				printf("1\n");
			}
		}
	}

	return 0;
}