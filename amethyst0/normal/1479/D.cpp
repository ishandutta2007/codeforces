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

const int maxm = (int)3e7 + 10;
struct vt {
	ll x;
	int l, r;

	vt() : x(0), l(-1), r(-1) {

	}
};

vt mas[maxm];
int posit = 0;

int my_new() {
	assert(posit < maxm);
	mas[posit++] = vt();
	return posit++;
}

int cpy(int t) {
	int nt = my_new();
	mas[nt].x = mas[t].x;
	mas[nt].l = mas[t].l;
	mas[nt].r = mas[t].r;
	return nt;
}

void build(int t) {
	if (mas[t].l == -1) {
		mas[t].l = my_new();
		mas[t].r = my_new();
	}
}

int change(int t, int l, int r, int pos, ll x) {
	t = cpy(t);
	if (l == r) {
		mas[t].x ^= x;
	}
	else {
		int m = (l + r) >> 1;
		build(t);

		if (pos <= m) {
			mas[t].l = change(mas[t].l, l, m, pos, x);
		}
		else {
			mas[t].r = change(mas[t].r, m + 1, r, pos, x);
		}

		mas[t].x = mas[mas[t].l].x ^ mas[mas[t].r].x;
	}

	return t;
}

ll getx(int t) {
	return (t == -1 ? 0 : mas[t].x);
}

const int maxlog = 20;

int go(int t1, int t2, int l, int r, int lm, int rm, int pos, ll z) {
	if (!(l <= pos && pos <= r)) {
		z = 0;
	}
	if ((getx(t1) ^ getx(t2) ^ z) == 0) {
		return -1;
	}

	if (l == r) {
		return l;
	}

	if (t1 == -1) {
		swap(t1, t2);
	}

	if (t1 == -1) {
		if (lm <= pos && pos <= rm) {
			return pos;
		}

		return -1;
	}

	if (l == lm && r == rm) {
		int m = (l + r) >> 1;

		int ans = go(mas[t1].l, (t2 == -1 ? -1 : mas[t2].l), l, m, lm, m, pos, z);
		if (ans == -1) {
			ans = go(mas[t1].r, (t2 == -1 ? -1 : mas[t2].r), m + 1, r, m + 1, rm, pos, z);
		}
		return ans;
	}
	else {
		int m = (l + r) >> 1;
		if (rm <= m) {
			return go(mas[t1].l, (t2 == -1 ? -1 : mas[t2].l), l, m, lm, rm, pos, z);
		}
		else if (lm > m) {
			return go(mas[t1].r, (t2 == -1 ? -1 : mas[t2].r), m + 1, r, lm, rm, pos, z);
		}
		else {
			int ans = go(mas[t1].l, (t2 == -1 ? -1 : mas[t2].l), l, m, lm, m, pos, z);
			if (ans == -1) {
				ans = go(mas[t1].r, (t2 == -1 ? -1 : mas[t2].r), m + 1, r, m + 1, rm, pos, z);
			}
			return ans;
		}
	}
}

const int maxn = (int)3e5 + 10;
int a[maxn];
vector <int> ed[maxn];

int tr[maxn];

ll val[maxn];

mt19937 rr(18973491204867 + 12986481764 + 1298461824 + 89163478239 + 191 + 1289419498134 + 12489712984798124 + 18967417864);
int n;

int par[maxlog][maxn];
int h[maxn];

void dfs(int v, int p, int t, int hh) {
	par[0][v] = p;
	h[v] = hh;

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	t = change(t, 0, n - 1, a[v], val[a[v]]);
	tr[v] = t;

	for (int u : ed[v]) {
		if (u != p) {
			dfs(u, v, t, hh + 1);
		}
	}
}

int lca(int x, int y) {
	if (h[x] < h[y]) {
		swap(x, y);
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (h[x] - (1 << i) >= h[y]) {
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

int main() {
	int q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//a[i] = rr() % n + 1;
		a[i]--;
		val[i] = rr() * (ll)1e9 + rr();
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		//x = i + 2;
		//y = rr() % (i + 1) + 1;
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	int t = my_new();
	dfs(0, 0, t, 0);

	while (q--) {
		int c, b, l, r;
		scanf("%d %d %d %d", &c, &b, &l, &r);
		/*c = rr() % n + 1;
		b = rr() % n + 1;
		l = rr() % n + 1;
		r = rr() % n + 1;*/
		c--;
		b--;
		l--;
		r--;
		int p = lca(c, b);
		int t1 = tr[c];
		int t2 = tr[b];
		int ans = go(t1, t2, 0, n - 1, l, r, a[p], val[a[p]]);
		printf("%d\n", (ans == -1 ? ans : ans + 1));
	}
}