#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10, maxlog = 20;
vector <int> ed[maxn];
int par[maxlog][maxn];
int d[maxn];
int h[maxn];
int tt;
int tin[maxn], tout[maxn];
set <pii> vert[maxn][2];
int g[maxn][2];

int dfs(int v, int p, int hh = 0) {
	tt++;
	vert[hh][0].insert(mp(tt, v));
	vert[hh][1].insert(mp(tt, v));

	tin[v] = tt;
	par[0][v] = p;
	h[v] = hh;

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	d[v] = 0;
	g[v][0] = g[v][1] = 0;

	for (int u : ed[v]) {
		if (u != p) {
			d[v] = max(d[v], dfs(u, v, hh + 1) + 1);
			int cur = d[u] + 1;

			if (cur > g[v][0]) {
				g[v][1] = g[v][0];
				g[v][0] = cur;
			}
			else if (cur > g[v][1]) {
				g[v][1] = cur;
			}
		}
	}

	tout[v] = tt;
	return d[v];
}

int up(int v, int d) {
	for (int i = maxlog - 1; i >= 0; i--) {
		if ((1 << i) <= d) {
			d -= (1 << i);
			v = par[i][v];
		}
	}

	return v;
}

bool used[maxn][2];

int main() {
	int t;

	cin >> t;

	while (t--) {
		tt = -1;
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		a--;
		b--;

		for (int i = 0; i < n; i++) {
			ed[i].clear();
			vert[i][0].clear();
			vert[i][1].clear();
			used[i][0] = used[i][1] = false;
		}

		for (int i = 0; i < n - 1; i++) {
			int x, y;

			scanf("%d %d", &x, &y);
			x--;
			y--;
			ed[x].push_back(y);
			ed[y].push_back(x);
		}

		dfs(a, a);

		int len = h[b];

		used[b][0] = true;
		queue <pii> q;
		q.push(mp(b, 0));

		while (!q.empty()) {
			int v = q.front().first;
			int tp = q.front().second;
			q.pop();

			int pl = up(v, len - 1);
			int l = par[0][pl];

			for (int u : ed[v]) {
				if (u == par[0][v]) {
					if (l != a) {
						if (!used[u][tp]) {
							used[u][tp] = true;
							q.push(mp(u, tp));
						}
					}

					continue;
				}

				if (!used[u][tp]) {
					used[u][tp] = true;
					q.push(mp(u, tp));
				}
			}

			int gl = g[l][0];

			if (gl == d[pl] + 1) {
				gl = g[l][1];
			}

			if (gl >= len) {
				gl = len;
			}

			if (gl == 0) {
				continue;
			}

			int pr = up(v, min(gl, len - 1));

			int hh = h[v];

			auto itr = vert[hh][tp].lower_bound(mp(tin[pr], -1));
			
			while (itr != vert[hh][tp].end() && itr->first <= tout[pr]) {
				auto nxt = next(itr);
				if (!used[itr->second][tp]) {
					used[itr->second][tp] = true;
					q.push(mp(itr->second, tp));
				}

				swap(itr, nxt);
				vert[hh][tp].erase(nxt);
			}

			if (gl != len) {
				continue;
			}

			itr = vert[hh][tp ^ 1].lower_bound(mp(tin[l], -1));

			while (itr != vert[hh][tp ^ 1].end() && itr->first < tin[pl]) {
				auto nxt = next(itr);
				if (!used[itr->second][tp ^ 1]) {
					used[itr->second][tp ^ 1] = true;
					q.push(mp(itr->second, tp ^ 1));
				}

				swap(itr, nxt);
				vert[hh][tp ^ 1].erase(nxt);
			}

			itr = vert[hh][tp ^ 1].lower_bound(mp(tout[pl] + 1, -1));

			while (itr != vert[hh][tp ^ 1].end() && itr->first <= tout[l]) {
				auto nxt = next(itr);
				if (!used[itr->second][tp ^ 1]) {
					used[itr->second][tp ^ 1] = true;
					q.push(mp(itr->second, tp ^ 1));
				}

				swap(itr, nxt);
				vert[hh][tp ^ 1].erase(nxt);
			}
		}

		if (used[b][1]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}