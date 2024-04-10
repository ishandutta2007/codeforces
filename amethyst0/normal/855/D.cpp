/*AMETHYSTS*/
#include <cstdio>
#include <fstream>
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10, maxlog = 20;

int par[maxlog][maxn];
int tp[maxlog][maxn];
vector <int> ed[maxn];
int up[maxn];
int h[maxn];
int c[maxn];

void dfs(int v, int p, int hh, int cm) {
	par[0][v] = p;
	tp[0][v] = up[v];
	h[v] = hh;
	c[v] = cm;

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
		if (tp[i - 1][v] != tp[i - 1][par[i - 1][v]]) {
			tp[i][v] = -1;
		} else {
			tp[i][v] = tp[i - 1][v];
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs(u, v, hh + 1, cm);
	}
}

int lca(int x, int y) {
	if (h[x] > h[y]) {
		swap(x, y);
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (h[par[i][y]] >= h[x]) {
			y = par[i][y];
		}
	}

	if (x == y) {
		return x;
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (par[i][x] != par[i][y]) {
			x = par[i][x];
			y = par[i][y];
		}
	}

	return par[0][x];
}

int upp(int x, int l) {
	if (x == l) {
		return -1;
	}

	int tpp = up[x];

	for (int i = maxlog - 1; i >= 0; i--) {
		if (h[x] - (1 << i) >= h[l]) {
			if (tpp != tp[i][x]) {
				tpp = -1;
			}

			x = par[i][x];
		}
	}

	return tpp;
}

int main() {
	int n;

	cin >> n;

	vector <int> ver;

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d %d", &x, &up[i]);

		if (x != -1) {
			ed[x].push_back(i);
		} else {
			ver.push_back(i);
		}
	}

	int cm = 0;

	for (int i = 0; i < (int)ver.size(); i++) {
		dfs(ver[i], ver[i], 0, cm++);
	}

	int q;

	cin >> q;

	while (q--) {
		int x, y, cc;

		scanf("%d %d %d", &cc, &x, &y);
		swap(x, y);

		if (c[x] != c[y]) {
			printf("NO\n");
			continue;
		}

		int l = lca(x, y);

		int tp1 = upp(x, l);
		int tp2 = upp(y, l);

		if (cc == 1) {
			if (x != y && y == l && tp1 == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if (x == y || x == l) {
				printf("NO\n");
			} else if (y == l) {
				if (tp1 == 1) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			} else {
				if (tp1 == 1 && tp2 == 0) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			}
		}
	}

	return 0;
}