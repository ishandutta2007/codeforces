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

const int maxn = (int)2e5 + 10, maxlog = 20;

struct Tree {
	vector <vector <int> > ed;
	int n;
	vector <int> h;
	vector <int> par[maxlog];
	vector <int> tin;
	int tt;
	vector <int> proj[2];
	vector <int> used;
	int last;
	int posit;

	void dfs(int v, int p, int hh) {
		tt++;
		tin[v] = tt;
		h[v] = hh;
		par[0][v] = p;

		for (int i = 1; i < maxlog; i++) {
			par[i][v] = par[i - 1][par[i - 1][v]];
		}

		for (int u : ed[v]) {
			if (u != p) {
				dfs(u, v, hh + 1);
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

	Tree() {

	}

	Tree(int n, vector <pii> e) : n(n) {
		used.resize(n);
		last = 0;
		tt = -1;
		ed.resize(n);
		h.resize(n);
		tin.resize(n);
		proj[0].resize(n);
		proj[1].resize(n);

		for (int i = 0; i < maxlog; i++) {
			par[i].resize(n);
		}

		for (auto[v, u] : e) {
			ed[v].push_back(u);
			ed[u].push_back(v);
		}

		dfs(0, 0, 0);
	}

	vector <vector <pii> > e;

	int get_num(int v) {
		if (used[v] == last) {
			return proj[0][v];
		}

		e.push_back(vector <pii>());
		used[v] = last;
		proj[0][v] = posit;
		proj[1][posit++] = v;
		return proj[0][v];
	}

	vector <vector <pii> > build(vector <int> vert) {
		e.clear();
		posit = 0;
		last++;
		sort(all(vert), [&](int a, int b) {
			return tin[a] < tin[b];
		});

		vector <int> st;

		for (int v : vert) {
			if (st.empty()) {
				st.push_back(v);
				continue;
			}

			int l = lca(st.back(), v);

			int pv = get_num(v);
			int pl = get_num(l);

			int lst = -1;
			int plst = -1;

			while (!st.empty() && h[l] <= h[st.back()]) {
				int u = st.back();

				st.pop_back();
				int pu = get_num(u);
				if (lst != -1) {
					e[pu].push_back(mp(plst, h[lst] - h[u]));
					e[plst].push_back(mp(pu, h[lst] - h[u]));
				}

				lst = u;
				plst = pu;
			}

			if (lst != -1 && lst != l) {
				e[pl].push_back(mp(plst, h[lst] - h[l]));
				e[plst].push_back(mp(pl, h[lst] - h[l]));
			}

			st.push_back(l);

			if (v != l) {
				st.push_back(v);
			}
		}

		int lst = -1;
		int plst = -1;

		while (!st.empty()) {
			int u = st.back();
			st.pop_back();
			int pu = get_num(u);
			if (lst != -1) {
				e[pu].push_back(mp(plst, h[lst] - h[u]));
				e[plst].push_back(mp(pu, h[lst] - h[u]));
			}

			lst = u;
			plst = pu;
		}

		return e;
	}
};

vector <int> ed[maxn];
vector <vector <pii> > e;

struct vt {
	int len;
	int s;
	int num;

	vt() {

	}

	vt(int len, int s, int num) : len(len), s(s), num(num) {

	}
};

bool operator <(vt a, vt b) {
	int na = (a.len + a.s - 1) / a.s;
	int nb = (b.len + b.s - 1) / b.s;
	if (na != nb) {
		return na < nb;
	}

	return a.num < b.num;
}

int wh[maxn];

int main() {
	int n;

	cin >> n;
	vector <pii> ee;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
		ee.push_back(mp(x, y));
	}

	Tree t = Tree(n, ee);

	int q;

	cin >> q;

	while (q--) {
		int k, m;

		scanf("%d %d", &k, &m);

		vector <pii> a;
		vector <int> b;
		vector <int> vert;

		for (int i = 0; i < k; i++) {
			int x, c;

			scanf("%d %d", &x, &c);
			x--;
			a.push_back(mp(x, c));
			vert.push_back(x);
		}

		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			x--;
			b.push_back(x);
			vert.push_back(x);
		}

		sort(all(vert));
		vert.resize(unique(all(vert)) - vert.begin());

		e = t.build(vert);

		for (int i = 0; i < (int)e.size(); i++) {
			wh[i] = -1;
		}

		set <pair <vt, int> > s;

		for (int i = 0; i < (int)a.size(); i++) {
			int v = t.proj[0][a[i].first];
			int sp = a[i].second;

			s.insert(mp(vt(0, sp, i), v));
		}

		while (!s.empty()) {
			vt cur = s.begin()->first;
			int v = s.begin()->second;
			s.erase(s.begin());
			if (wh[v] != -1) {
				continue;
			}

			wh[v] = cur.num;

			for (auto [u, d] : e[v]) {
				cur.len += d;
				s.insert(mp(cur, u));
				cur.len -= d;
			}
		}

		//printf("ANSWER:\n");

		for (int v : b) {
			printf("%d ", wh[t.proj[0][v]] + 1);
		}

		printf("\n");
	}
}