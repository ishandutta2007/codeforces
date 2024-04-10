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
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

struct Fenwick {
	vector <int> t;

	Fenwick() {

	}

	Fenwick(int n) {
		t.assign(n, 0);
	}

	void change(int pos, int x) {
		for (; pos < (int)t.size(); pos |= pos + 1) {
			t[pos] += x;
		}
	}

	int go(int pos) {
		int ans = 0;

		for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			ans += t[pos];
		}
		return ans;
	}

	int go(int l, int r) {
		return go(r) - go(l - 1);
	}
};

const int maxn = (int)2e5 + 10, maxlog = 19;

mt19937 rr;

struct vt {
	int x;
	int v;
	int y;
	int sz;
	int l;
	int r;

	vt() {

	}

	vt(int x, int v) : x(x), v(v), y(rr()), sz(1), l(-1), r(-1) {

	}
};

vt mas[maxn * 40];
int posit = 0;

int my_new(int x, int v) {
	mas[posit] = vt(x, v);
	return posit++;
}

int sz(int t) {
	return (t == -1 ? 0 : mas[t].sz);
}

void recalc(int t) {
	mas[t].sz = 1 + sz(mas[t].l) + sz(mas[t].r);
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	}

	if (r == -1) {
		return l;
	}

	if (mas[l].y > mas[r].y) {
		mas[l].r = merge(mas[l].r, r);
		recalc(l);
		return l;
	}

	mas[r].l = merge(l, mas[r].l);
	recalc(r);
	return r;
}

void split(int t, int x, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
		return;
	}

	if (mas[t].x < x) {
		split(mas[t].r, x, mas[t].r, r);
		l = t;
		recalc(l);
	}
	else {
		split(mas[t].l, x, l, mas[t].l);
		r = t;
		recalc(r);
	}
}

int par[maxlog][maxn];
vector <int> ed[maxn];
vector <int> vert;
int pos[maxn];
int h[maxn];
int tin[maxn], tout[maxn];
int tt = -1;

void dfs(int v, int p, int hh) {
	tt++;
	tin[v] = tt;
	pos[v] = (int)vert.size();
	vert.push_back(v);
	h[v] = hh;

	par[0][v] = p;

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	for (int u : ed[v]) {
		if (u != p) {
			dfs(u, v, hh + 1);
			vert.push_back(v);
		}
	}

	tout[v] = tt;
}

pii tab[maxlog][2 * maxn];
int st[2 * maxn];

int lca(int a, int b) {
	int l = pos[a];
	int r = pos[b];

	if (l > r) {
		swap(l, r);
	}

	int it = st[r - l + 1];

	return min(tab[it][l], tab[it][r - (1 << it) + 1]).second;
}

int up(int v, int d) {
	int ans = v;
	for (int i = 0; d; d >>= 1, i++) {
		if (d & 1) {
			ans = par[i][ans];
		}
	}
	return ans;
}

int a[maxn], b[maxn], lc[maxn];

int k;

vector <int> e[maxn];
vector <int> z[maxn];

ll ans;

int calc(int t, int r) {
	if (t == -1) {
		return 0;
	}

	if (mas[t].x <= r) {
		return sz(mas[t].l) + 1 + calc(mas[t].r, r);
	}
	else {
		return calc(mas[t].l, r);
	}
}

int calc(int t, int l, int r) {
	return calc(t, r) - calc(t, l - 1);
}

void add_ans(int t, int v, int root, int d) {
	if (d > 0 && d < k) {
		int ds = h[v] - h[root];

		if (d <= ds) {
			int u = up(v, ds - d);
			ans += calc(t, tin[u], tout[u]);
		}

		if (k <= ds) {
			int u = up(v, ds - k);
			ans -= calc(t, tin[u], tout[u]);
		}
	}

	if (d <= 0) {
		int ds = h[v] - h[root];

		if (k <= ds) {
			int u = up(v, ds - k);
			ans -= calc(t, tin[u], tout[u]);
		}
	}
}

void add_ans_tr(int t, int nt, int root, int d) {
	if (nt == -1) {
		return;
	}

	add_ans_tr(t, mas[nt].l, root, d);
	add_ans_tr(t, mas[nt].r, root, d);
	add_ans(t, mas[nt].v, root, d);
}

void add(int &t, int v) {
	int l, r;

	split(t, tin[v], l, r);
	t = merge(merge(l, my_new(tin[v], v)), r);
}

void add_tr(int &t, int nt) {
	if (nt == -1) {
		return;
	}

	add_tr(t, mas[nt].l);
	add_tr(t, mas[nt].r);
	add(t, mas[nt].v);
}

int build(int v, int root) {
	int t = -1;

	int ds = h[v] - h[root];
	ds = k - ds;

	for (int u : z[v]) {
		add_ans(t, u, root, ds);
		add(t, u);
	}

	for (int u : e[v]) {
		int nt = build(u, root);

		if (sz(nt) > sz(t)) {
			swap(t, nt);
		}

		add_ans_tr(t, nt, root, ds);
		add_tr(t, nt);
	}

	return t;
}

int main() {
	int curv = -1;
	for (int i = 1; i < 2 * maxn; i++) {
		if ((i & (i - 1)) == 0) {
			curv++;
		}

		st[i] = curv;
	}

	int n, m;

	cin >> n >> m >> k;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(0, 0, 0);

	for (int i = 0; i < (int)vert.size(); i++) {
		tab[0][i] = mp(h[vert[i]], vert[i]);
	}

	for (int i = 1; i < maxlog; i++) {
		for (int j = 0; j <= (int)vert.size() - (1 << i); j++) {
			tab[i][j] = min(tab[i - 1][j], tab[i - 1][j + (1 << (i - 1))]);
		}
	}

	vector <pii> g;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		int l = lca(a[i], b[i]);
		lc[i] = l;

		if (h[a[i]] + h[b[i]] - 2 * h[l] < k) {
			m--;
			i--;
			continue;
		}

		if (h[a[i]] - h[l] >= k) {
			g.push_back(mp(h[l], a[i]));
		}

		if (h[b[i]] - h[l] >= k) {
			g.push_back(mp(h[l], b[i]));
		}
	}

	sort(all(g));
	reverse(all(g));

	Fenwick tr(n);

	for (int i = 0; i < (int)g.size(); i++) {
		tr.change(tin[g[i].second], 1);
	}

	for (int i = 0; i < (int)g.size(); i++) {
		tr.change(tin[g[i].second], -1);
		int v = g[i].second;
		int d = h[v] - g[i].first;
		v = up(v, d - k);
		ans += tr.go(tin[v], tout[v]);
	}

	vector <pair <pii, pii> > f;

	for (int i = 0; i < m; i++) {
		int x = a[i];
		int y = b[i];
		int l = lc[i];

		if (x == l || y == l) {
			continue;
		}

		int px = up(x, h[x] - h[l] - 1);
		int py = up(y, h[y] - h[l] - 1);

		if (px > py) {
			swap(px, py);
			swap(x, y);
		}

		f.push_back(mp(mp(px, py), mp(x, y)));
	}

	sort(all(f));

	int l = 0;

	while (l < (int)f.size()) {
		int r = l;

		while (r < (int)f.size() && f[r].first == f[l].first) {
			r++;
		}

		vector <int> ver;

		for (int i = l; i < r; i++) {
			ver.push_back(f[i].second.second);
		}

		sort(all(ver), [&](int a, int b) {
			return tin[a] < tin[b];
		});

		for (int i = 0; i < r - l - 1; i++) {
			int l = lca(ver[i], ver[i + 1]);
			ver.push_back(l);
		}

		sort(all(ver));
		ver.resize(unique(all(ver)) - ver.begin());
		sort(all(ver), [&](int a, int b) {
			return tin[a] < tin[b];
		});

		vector <int> st;

		st.push_back(ver[0]);

		for (int i = 1; i < (int)ver.size(); i++) {
			int v = ver[i];

			int l = lca(st.back(), v);

			while (st.back() != l) {
				st.pop_back();
			}

			e[l].push_back(v);
			st.push_back(v);
		}

		for (int i = l; i < r; i++) {
			z[f[i].second.second].push_back(f[i].second.first);
		}

		posit = 0;

		build(ver[0], par[0][f[l].first.second]);

		for (int v : ver) {
			e[v].clear();
			z[v].clear();
		}

		l = r;
	}

	cout << ans << '\n';
}