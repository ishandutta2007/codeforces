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

const int maxn = (int)1e5 + 10;

vector <pii> ed[maxn];
vector <pair <pii, int> > edg[maxn];
const ll inf = (ll)1e18;
ll d[maxn];
pair <ll, int> t[4 * maxn];
ll st[4 * maxn];

void sets(int it, ll z) {
	if (t[it].first == inf + 1) {
		return;
	}

	t[it].first = min(t[it].first, z);

	if (st[it] == -1) {
		st[it] = z;
	} else {
		st[it] = min(st[it], z);
	}
}

void push(int it) {
	if (st[it] != -1) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		st[it] = -1;
	}
}

void change(int it, int l, int r, int lm, int rm, ll z) {
	if (l == lm && r == rm) {
		sets(it, z);
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, z);
		} else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, z);
		} else {
			change(2 * it, l, m, lm, m, z);
			change(2 * it + 1, m + 1, r, m + 1, rm, z);
		}

		t[it] = min(t[2 * it], t[2 * it + 1]);
	}
}

void changef(int it, int l, int r, int x) {
	if (l == r) {
		t[it] = mp(inf + 1, l);
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (x <= m) {
			changef(2 * it, l, m, x);
		} else {
			changef(2 * it + 1, m + 1, r, x);
		}

		t[it] = min(t[2 * it], t[2 * it + 1]);
	}
}

void build(int it, int l, int r) {
	st[it] = -1;
	if (l == r) {
		t[it] = mp(inf, l);
	} else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		t[it] = min(t[2 * it], t[2 * it + 1]);
	}
}

vector <pair <pii, int> > g[maxn];
int tree[4 * maxn];

void buil(int it, int l, int r) {
	if (l == r) {
		if (!g[l].empty()) {
			tree[it] = g[l].back().first.first;
		} else {
			tree[it] = -1;
		}
	} else {
		int m = (l + r) >> 1;

		buil(2 * it, l, m);
		buil(2 * it + 1, m + 1, r);

		tree[it] = max(tree[2 * it], tree[2 * it + 1]);
	}
}

vector <pii> now;

void go(int it, int l, int r, int x) {
	if (l > x) {
		return;
	}

	if (tree[it] < x) {
		return;
	}

	if (l == r) {
		while (!g[l].empty() && g[l].back().first.first >= x) {
			now.push_back(mp(g[l].back().first.second, g[l].back().second));
			g[l].pop_back();
		}

		if (g[l].empty()) {
			tree[it] = -1;
		} else {
			tree[it] = g[l].back().first.first;
		}

		return;
	}

	int m = (l + r) >> 1;

	go(2 * it, l, m, x);
	go(2 * it + 1, m + 1, r, x);
	tree[it] = max(tree[2 * it], tree[2 * it + 1]);
}

int n;

void dij(int s) {
	build(1, 1, n);

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	change(1, 1, n, s, s, 0);

	while (true) {
		int v = t[1].second;
		ll ds = t[1].first;

		if (ds == inf + 1) {
			break;
		}

		d[v] = ds;

		changef(1, 1, n, v);

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i].first;
			int w = ed[v][i].second;

			change(1, 1, n, u, u, d[v] + w);
		}

		for (int i = 0; i < (int)edg[v].size(); i++) {
			int l = edg[v][i].first.first;
			int r = edg[v][i].first.second;
			int w = edg[v][i].second;

			change(1, 1, n, l, r, d[v] + w);
		}

		now.clear();
		go(1, 1, n, v);

		for (int i = 0; i < (int)now.size(); i++) {
			int u = now[i].first;
			int w = now[i].second;

			change(1, 1, n, u, u, d[v] + w);
		}
	}
}

int main() {
	int m, s;

	scanf("%d %d %d", &n, &m, &s);

	for (int i = 0; i < m; i++) {
		int tp;

		scanf("%d", &tp);

		if (tp == 1) {
			int x, y, z;

			scanf("%d %d %d", &x, &y, &z);

			ed[x].push_back(mp(y, z));
		} else {
			int x, l, r, w;

			scanf("%d %d %d %d", &x, &l, &r, &w);

			if (tp == 2) {
				edg[x].push_back(mp(mp(l, r), w));
			} else {
				g[l].push_back(mp(mp(r, x), w));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	buil(1, 1, n);

	dij(s);

	for (int i = 1; i <= n; i++) {
		if (d[i] == inf) {
			printf("-1 ");
		} else {
			printf("%I64d ", d[i]);
		}
	}

	return 0;
}