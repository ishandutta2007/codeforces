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
#define uint unsigned int
#define pb push_back
#define sz(a) (int)(a.size())

using namespace std;

const int maxn = (int)2e5 + 10, maxlog = 20;
vector <pii> ed[maxn];
vector <int> num[maxn];

pair <pii, pii> edge[maxn];

int pr[maxn];

int getp(int x) {
	return pr[x] = (pr[x] == x ? x : getp(pr[x]));
}

int h[maxn];
int cost[maxlog][maxn], z[maxlog][maxn];
int p[maxlog][maxn];

const int inf = (int)1e9 + 10;

void dfs(int v, int par, int w, int hh) {
	h[v] = hh;
	p[0][v] = par;
	cost[0][v] = w;
	z[0][v] = inf;

	for (int i = 1; i < maxlog; i++) {
		p[i][v] = p[i - 1][p[i - 1][v]];
		cost[i][v] = max(cost[i - 1][v], cost[i - 1][p[i - 1][v]]);
		z[i][v] = inf;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u != par) {
			dfs(u, v, ed[v][i].second, hh + 1);
		}
	}
}

int lca(int x, int y) {
	if (h[x] < h[y]) {
		swap(x, y);
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (h[p[i][x]] >= h[y]) {
			x = p[i][x];
		}
	}

	if (x == y) {
		return x;
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (p[i][x] != p[i][y]) {
			x = p[i][x];
			y = p[i][y];
		}
	}

	return p[0][x];
}

bool used[maxn];
int res[maxn];

int getcost(int v, int w, int c) {
	int ans = 0;

	for (int i = maxlog - 1; i >= 0; i--) {
		if ((1 << i) <= w) {
			ans = max(ans, cost[i][v]);
			w -= (1 << i);
			z[i][v] = min(z[i][v], c);
			v = p[i][v];
		}
	}

	return ans;
}

void make(int v, int par, int nm) {
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first;

		if (u != par) {
			make(u, v, num[v][i]);
		}
	}

	for (int i = maxlog - 1; i >= 1; i--) {
		if (z[i][v] == inf) {
			continue;
		}

		z[i - 1][v] = min(z[i - 1][v], z[i][v]);
		z[i - 1][p[i - 1][v]] = min(z[i - 1][p[i - 1][v]], z[i][v]);
	}

	res[nm] = z[0][v];
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		pr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int v, u, c;

		scanf("%d %d %d", &v, &u, &c);

		edge[i] = mp(mp(c, i), mp(v, u));
	}

	sort(edge, edge + m);
	
	for (int i = 0; i < m; i++) {
		int x = edge[i].second.first;
		int y = edge[i].second.second;

		int px = getp(x);
		int py = getp(y);

		if (px != py) {
			ed[x].push_back(mp(y, edge[i].first.first));
			ed[y].push_back(mp(x, edge[i].first.first));
			num[x].push_back(edge[i].first.second);
			num[y].push_back(edge[i].first.second);

			pr[px] = py;
			used[i] = true;
		}
	}

	dfs(1, 1, inf, 0);

	for (int i = 0; i < m; i++) {
		if (!used[i]) {
			int x = edge[i].second.first;
			int y = edge[i].second.second;

			int l = lca(x, y);

			int ans = max(getcost(x, h[x] - h[l], edge[i].first.first), getcost(y, h[y] - h[l], edge[i].first.first));
			
			res[edge[i].first.second] = ans;
		}
	}

	make(1, 1, m);

	for (int i = 0; i < m; i++) {
		if (res[i] == inf) {
			printf("-1 ");
		} else {
			printf("%d ", res[i] - 1);
		}
	}
	
	return 0;
}