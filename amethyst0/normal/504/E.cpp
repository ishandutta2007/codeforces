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
//#include <random>
#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)3e5 + 10, maxlog = 19;
const int mod1 = (int)1e9 + 7, mod2 = (int)1e9 + 9;
ll t[maxn];
vector <int> ed[maxn];
char cc[maxn];
int h[maxn];
int p[maxlog][maxn];
int hsh[maxlog][maxn], rhsh[maxlog][maxn];

pll operator +(pll a, pll b) {
	a.first += b.first;
	a.second += b.second;

	if (a.first >= mod1) {
		a.first -= mod1;
	}

	if (a.second >= mod2) {
		a.second -= mod2;
	}

	return a;
}

pll operator -(pll a, pll b) {
	a.first -= b.first;
	a.second -= b.second;

	if (a.first < 0) {
		a.first += mod1;
	}

	if (a.second < 0) {
		a.second += mod2;
	}

	return a;
}

pll operator *(pll a, pll b) {
	a.first *= b.first;
	a.second *= b.second;

	a.first %= mod1;
	a.second %= mod2;

	return a;
}

void dfs(int v, int par, int hh) {
	p[0][v] = par;
	h[v] = hh;
	hsh[0][v] = cc[v] - 'a' + 1;//mp(cc[v] - 'a' + 1, cc[v] - 'a' + 1);
	rhsh[0][v] = cc[par] - 'a' + 1;//mp(cc[par] - 'a' + 1, cc[par] - 'a' + 1);

	for (int i = 1; i < maxlog; i++) {
		p[i][v] = p[i - 1][p[i - 1][v]];
		ll a = hsh[i - 1][v];
		ll b = hsh[i - 1][p[i - 1][v]];

		hsh[i][v] = (a * t[1 << (i - 1)] + b) % mod1;
		a = rhsh[i - 1][v];
		b = rhsh[i - 1][p[i - 1][v]];

		rhsh[i][v] = (b * t[1 << (i - 1)] + a) % mod1;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != par) {
			dfs(u, v, hh + 1);
		}
	}
}

int st[maxn];

int up(int x, int cnt) {
	while (cnt != 0) {
		x = p[st[cnt]][x];
		cnt -= (1 << st[cnt]);
	}

	return x;
}

int lca(int a, int b) {
	if (h[a] < h[b]) {
		swap(a, b);
	}

	a = up(a, h[a] - h[b]);

	if (a == b) {
		return a;
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (p[i][a] != p[i][b]) {
			a = p[i][a];
			b = p[i][b];
		}
	}

	return p[0][a];
}

vector <int> g[2][maxn];

void gethsh(int l, int x, int it) {
	g[it][x].clear();
	int dst = h[x] - h[l];
	int y = x;

	g[it][x].push_back(y);

	for (int i = 0; i < maxlog; i++) {
		if (dst == 0) {
			break;
		}
		if (dst & 1) {
			g[it][x].push_back(p[i][y]);
			y = p[i][y];
		}

		dst >>= 1;
	}
}

pair <int, int> gethsh(int l, int x, int i, int it) {
	if (l == g[it][x].back()) {
		g[it][x].pop_back();
		int z = g[it][x].back();
		return mp(rhsh[i][z], z);
	} else {
		int z = g[it][x].back();
		while (h[z] - h[l] != (1 << (i + 1))) {
			int num = st[h[z] - h[l]];
			num--;

			z = p[num][z];
		}

		g[it][x].back() = z;

		z = p[i][z];

		return mp(rhsh[i][z], z);
	}
}

int main() {
	for (int i = 0; i < maxlog; i++) {
		st[1 << i] = i;
	}

	for (int i = 1; i < maxn; i++) {
		if (st[i] == 0) {
			st[i] = st[i - 1];
		}
	}

	t[0] = 1;//mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		t[i] = t[i - 1] * 1234567;//mp(1234567, 1234567);
		t[i] %= mod1;
	}

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf(" %c", &cc[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	dfs(1, 1, 0);

	int q;

	cin >> q;

	while (q--) {
		int a, b, c, d;

		scanf("%d %d %d %d", &a, &b, &c, &d);

		int l1 = lca(a, b);
		int l2 = lca(c, d);

		if (h[c] - h[l2] > h[a] - h[l1]) {
			swap(a, c);
			swap(b, d);
			swap(l1, l2);
		}

		int ans = 0;

		for (int i = st[h[c] - h[l2]]; i >= 0; i--) {
			if (h[c] - h[l2] < (1 << i)) {
				continue;
			}

			if (hsh[i][a] == hsh[i][c]) {
				ans += (1 << i);
				a = p[i][a];
				c = p[i][c];
			}
		}

		if (c != l2) {
			printf("%d\n", ans);
		} else {
			gethsh(l2, d, 0);
			for (int i = st[h[d] - h[l2]]; i >= 0; i--) {
				pair <int, int> z;

				if ((1 << i) <= h[d] - h[l2]) {
					z = gethsh(l2, d, i, 0);
				}

				if ((1 << i) <= h[a] - h[l1] && (1 << i) <= h[d] - h[l2]) {
					if (hsh[i][a] == z.first) {
						ans += (1 << i);
						a = p[i][a];
						l2 = z.second;
					}
				}
			}

			if (a != l1) {
				if (cc[a] == cc[l2]) {
					ans++;
				}

				printf("%d\n", ans);
				continue;
			}
			 
			gethsh(l2, d, 0);
			gethsh(l1, b, 1);

			for (int i = max(st[h[d] - h[l2]], st[h[b] - h[l1]]); i >= 0; i--) {
				pair <int, int> z, y;

				if ((1 << i) <= h[d] - h[l2]) {
					z = gethsh(l2, d, i, 0);
				}

				if ((1 << i) <= h[b] - h[l1]) {
					y = gethsh(l1, b, i, 1);
				}

				if ((1 << i) <= h[b] - h[l1] && (1 << i) <= h[d] - h[l2]) {
					if (z.first == y.first) {
						l2 = z.second;
						l1 = y.second;
						ans += (1 << i);
					}
				}
			}

			if (cc[l1] == cc[l2]) {
				ans++;
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}