//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <limits.h>
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

const int maxn = (int)3e5 + 10;
vector <int> ed[maxn];
vector <int> red[maxn];
int tin[maxn], tout[maxn];
int tt = -1;

void dfs(int v) {
	tt++;
	tin[v] = tt;
	for (int u : red[v]) {
		dfs(u);
	}

	tout[v] = tt;
}

ll t[2][4 * maxn];
int st[2][4 * maxn];

void sets(int v, int it, int l, int r, int x) {
	t[v][it] += (ll)x * (r - l + 1);
	st[v][it] += x;
}

void push(int v, int it, int l, int r) {
	if (st[v][it] != 0) {
		int m = (l + r) >> 1;
		sets(v, 2 * it, l, m, st[v][it]);
		sets(v, 2 * it + 1, m + 1, r, st[v][it]);
		st[v][it] = 0;
	}
}

void change(int v, int it, int l, int r, int lm, int rm, int x) {
	if (l == lm && r == rm) {
		sets(v, it, l, r, x);
	}
	else {
		push(v, it, l, r);
		int m = (l + r) >> 1;

		if (rm <= m) {
			change(v, 2 * it, l, m, lm, rm, x);
		}
		else if (lm > m) {
			change(v, 2 * it + 1, m + 1, r, lm, rm, x);
		}
		else {
			change(v, 2 * it, l, m, lm, m, x);
			change(v, 2 * it + 1, m + 1, r, m + 1, rm, x);
		}

		t[v][it] = t[v][2 * it] + t[v][2 * it + 1];
	}
}

ll go(int v, int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[v][it];
	}
	else {
		int m = (l + r) >> 1;
		push(v, it, l, r);

		if (rm <= m) {
			return go(v, 2 * it, l, m, lm, rm);
		}
		else if (lm > m) {
			return go(v, 2 * it + 1, m + 1, r, lm, rm);
		}
		else {
			return go(v, 2 * it, l, m, lm, m) + go(v, 2 * it + 1, m + 1, r, m + 1, rm);
		}
	}
}

int n;

set <pii> s;

int goa(int v, int h) {
	int l = tin[v];
	int r = tout[v];

	auto itr = s.lower_bound(mp(l, -1));

	int lm = -1;
	int rm = -1;
	bool ok = false;

	if (itr == s.end() || itr->first > r) {
		if (itr != s.begin()) {
			itr--;
			if (itr->second >= r) {
				lm = itr->first;
				rm = itr->second;
				s.erase({ lm, rm });
			}
		}

		s.insert({ l, r });
		ok = true;
	}

	int ans = (int)s.size();
	for (int u : ed[v]) {
		ans = max(ans, goa(u, h + 1));
	}

	if (ok) {
		s.erase({ l, r });
	}
	if (lm != -1) {
		s.insert({ lm, rm });
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			ed[i].clear();
			red[i].clear();
		}

		for (int i = 1; i < n; i++) {
			int x;
			scanf("%d", &x);
			x--;
			ed[x].push_back(i);
		}

		for (int i = 1; i < n; i++) {
			int x;
			scanf("%d", &x);
			x--;
			red[x].push_back(i);
		}

		tt = -1;
		dfs(0);

		int ans = goa(0, 0);
		printf("%d\n", ans);
	}
}