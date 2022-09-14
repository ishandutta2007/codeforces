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

const int maxn = (int)2e5 + 10;
vector <pii> ed[maxn];
int a[maxn];
int tin[maxn];
int tout[maxn];
int tt = 0;
ll h[maxn];
ll b[maxn];
vector <ll> t[4 * maxn];

void build(int it, int l, int r) {
	if (l == r) {
		t[it].push_back(b[l]);
	} else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		t[it].resize(r - l + 1);
		merge(t[2 * it].begin(), t[2 * it].end(), t[2 * it + 1].begin(), t[2 * it + 1].end(), t[it].begin());
	}
}

void dfs(int v, ll hh = 0) {
	h[v] = hh;
	tt++;
	tin[v] = tt;
	
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		dfs(u, hh + ed[v][i].second);
	}

	tout[v] = tt;
}

int go(int it, int l, int r, int lm, int rm, ll x) {
	if (l == lm && r == rm) {
		return upper_bound(t[it].begin(), t[it].end(), x) - t[it].begin();
	} else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm, x);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm, x);
		} else {
			return go(2 * it, l, m, lm, m, x) + go(2 * it + 1, m + 1, r, m + 1, rm, x);
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 2; i <= n; i++) {
		int p, w;

		scanf("%d %d", &p, &w);

		ed[p].push_back(mp(i, w));
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		b[tin[i]] = h[i] - a[i];
	}

	build(1, 1, n);

	for (int i = 1; i <= n; i++) {
		printf("%d ", go(1, 1, n, tin[i], tout[i], h[i]) - 1);
	}

	return 0;
}