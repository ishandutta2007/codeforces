#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10;

char s[maxn], f[maxn];

int t[4 * maxn];
int st[4 * maxn];

void build(int it, int l, int r) {
	st[it] = -1;
	if (l == r) {
		t[it] = f[l] - '0';
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it] = t[2 * it] + t[2 * it + 1];
	}
}

void sets(int it, int l, int r, int x) {
	st[it] = x;
	t[it] = (r - l + 1) * x;
}

void push(int it, int l, int r) {
	if (st[it] != -1) {
		int m = (l + r) >> 1;
		sets(2 * it, l, m, st[it]);
		sets(2 * it + 1, m + 1, r, st[it]);
		st[it] = -1;
	}
}

int go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	}
	else {
		int m = (l + r) >> 1;
		push(it, l, r);
		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		}
		else {
			return go(2 * it, l, m, lm, m) + go(2 * it + 1, m + 1, r, m + 1, rm);
		}
	}
}

void change(int it, int l, int r, int lm, int rm, int x) {
	if (l == lm && r == rm) {
		sets(it, l, r, x);
	}
	else {
		push(it, l, r);
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

		t[it] = t[2 * it] + t[2 * it + 1];
	}
}

bool check(int it, int l, int r) {
	if (l == r) {
		return t[it] == (s[l] - '0');
	}
	else {
		int m = (l + r) >> 1;
		push(it, l, r);
		return check(2 * it, l, m) & check(2 * it + 1, m + 1, r);
	}
}

int l[maxn], r[maxn];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		scanf("%s %s", s, f);

		build(1, 0, n - 1);

		for (int i = 0; i < q; i++) {
			scanf("%d %d", &l[i], &r[i]);
			l[i]--;
			r[i]--;
		}

		bool ok = true;

		for (int i = q - 1; i >= 0; i--) {
			int x = go(1, 0, n - 1, l[i], r[i]);
			int d = r[i] - l[i] + 1;
			if (2 * x > d) {
				change(1, 0, n - 1, l[i], r[i], 1);
			}
			else if (2 * x < d) {
				change(1, 0, n - 1, l[i], r[i], 0);
			}
			else {
				ok = false;
				break;
			}
		}

		if (!ok) {
			printf("NO\n");
			continue;
		}

		ok = check(1, 0, n - 1);

		if (!ok) {
			printf("NO\n");
			continue;
		}

		printf("YES\n");
	}
}