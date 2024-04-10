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
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define dec aksldal

const int maxn = (int)5e5 + 10, maxlog = 19;
vector <pii> ed[maxn];
int par[maxlog][maxn];
int wup[maxn];

int h[maxn];
int pr[maxn];

int getp(int x) {
	return (pr[x] == x ? x : pr[x] = getp(pr[x]));
}

int x[maxn], y[maxn];
int inc[maxn], dec[maxn];

void dfs(int v, int p, int we, int hh) {
	h[v] = hh;
	par[0][v] = p;
	wup[v] = we;

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	for (auto[u, num] : ed[v]) {
		if (u != p) {
			if (v == 0 || num > we) {
				dec[u] = dec[v] + 1;
			}
			else {
				dec[u] = 1;
			}

			if (v == 0 || num < we) {
				inc[u] = inc[v] + 1;
			}
			else {
				inc[u] = 1;
			}

			dfs(u, v, num, hh + 1);
		}
	}
}

int lca(int x, int y) {
	if (h[x] < h[y]) {
		swap(x, y);
	}

	for (int i = 0; i < maxlog; i++) {
		if (((h[x] - h[y]) >> i) & 1) {
			x = par[i][x];
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

int up(int x, int d) {
	for (int i = 0; i < maxlog; i++) {
		if ((d >> i) & 1) {
			x = par[i][x];
		}
	}

	return x;
}

bool tr[maxn];
int f[maxn];
int val[maxn];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		pr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
	}

	for (int i = m - 1; i >= 0; i--) {
		int a = x[i];
		int b = y[i];
		int pa = getp(a);
		int pb = getp(b);

		if (pa != pb) {
			ed[a].push_back(mp(b, i));
			ed[b].push_back(mp(a, i));
			pr[pa] = pb;
			tr[i] = true;
		}
	}

	dfs(0, 0, -1, 0);

	for (int i = 0; i < n; i++) {
		val[i] = 1;
	}

	for (int i = m - 1; i >= 0; i--) {
		int a = x[i];
		int b = y[i];

		if (tr[i]) {
			f[i] = val[a] + val[b];
			val[a] = val[b] = f[i];
			continue;
		}
		else {
			int l = lca(a, b);
			int x = val[a] + val[b];

			if (b == l) {
				swap(a, b);
			}

			if (a == l) {
				int d = inc[b];

				if (h[b] - h[a] <= d) {
					d = h[b] - h[a];
				}

				int m = up(b, d - 1);

				if (dec[m] >= h[m] - h[a]) {
					x -= f[wup[m]];
				}
			}
			else {
				int da = inc[a];
				int db = inc[b];

				if (h[a] - h[l] <= da && h[b] - h[l] <= db) {
					int pa = up(a, h[a] - h[l] - 1);
					int pb = up(b, h[b] - h[l] - 1);
					x -= f[max(wup[pa], wup[pb])];
				}
				else {
					if (h[a] - h[l] <= da) {
						swap(a, b);
						swap(da, db);
					}

					if (h[b] - h[l] <= db) {
						int m = up(a, da - 1);
						if (dec[m] >= h[m] - h[l]) {
							int pa = up(a, h[a] - h[l] - 1);
							int pb = up(b, h[b] - h[l] - 1);

							if (wup[pb] < wup[pa]) {
								x -= f[wup[m]];
							}
						}
					}
				}
			}

			f[i] = x;
			val[a] = val[b] = x;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", val[i] - 1);
	}
}