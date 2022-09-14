//#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)4e5 + 10, maxlog = 19;
int sz[maxn];
int pr[maxn];
int h[maxn];
vector <int> ed[maxn];
int par[maxlog][maxn];

bool cmp(int a, int b) {
	return sz[a] > sz[b];
}

int dfs(int v, int p, int hh = 0) {
	sz[v] = 1;
	pr[v] = p;
	h[v] = hh;

	par[0][v] = (p == -1 ? v : p);

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			sz[v] += dfs(u, v, hh + 1);
		}
		else {
			swap(ed[v][i], ed[v].back());
			ed[v].pop_back();
			i--;
		}
	}
	return sz[v];
}

int lca(int x, int y) {
	if (h[x] > h[y]) {
		swap(x, y);
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (h[y] - (1 << i) >= h[x]) {
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

int tt = -1;
int tin[maxn], tout[maxn], lm[maxn], rm[maxn], vert[maxn], way[maxn];
//way[v] - way of vertex v
//vert[pos] - vertex on position pos
//lm[w], rm[w] - start and end of way w
//tin[v] - position of vertex v
//ways go from up to down
int posit = -1;

void build_way() {
	posit++;
	lm[posit] = tt + 1;
	rm[posit] = tt;
}

void build(int v) {
	tt++;
	tin[v] = tt;
	tout[v] = tt;
	way[tt] = posit;
	vert[tt] = v;
	rm[posit]++;
	sort(ed[v].begin(), ed[v].end(), cmp);
	if (ed[v].empty()) {
		return;
	}

	build(ed[v][0]);
	for (int i = 1; i < (int)ed[v].size(); i++) {
		build_way();
		build(ed[v][i]);
	}
}

int t[maxn];

void change(int pos, int x) {
	//cout << "!" << pos << ' ' << x << endl;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		t[pos] += x;
	}
}

int go(int pos) {
	int ans = 0;
	for (; pos < maxn; pos |= pos + 1) {
		ans += t[pos];
	}
	return ans;
}

map <pii, int> vals[maxn];

void change_tr(int v, int cur, int up) {
	while (true) {
		int w = way[tin[v]];
		int r = tin[v];
		int l = lm[w];
		if (way[tin[up]] == w) {
			l = tin[up];
		}

		auto it = vals[w].lower_bound(mp(l, -1));

		int tot = 0;

		if (it == vals[w].end() || it->first.first > l) {
			auto nit = prev(it);
			if (nit->first.second <= r) {
				change(nit->second, -(nit->first.second - l + 1));
				tot += -(nit->first.second - l + 1);
				int le = nit->first.first;
				int x = nit->second;
				vals[w].erase(nit);
				vals[w][mp(le, l - 1)] = x;
			}
			else {
				change(nit->second, -(r - l + 1));
				tot += -(r - l + 1);
				int le = nit->first.first;
				int ri = nit->first.second;
				int x = nit->second;
				vals[w].erase(nit);
				vals[w][mp(le, l - 1)] = x;
				vals[w][mp(r + 1, ri)] = x;
			}
		}

		while (it != vals[w].end() && it->first.second <= r) {
			change(it->second, -(it->first.second - it->first.first + 1));
			tot += -(it->first.second - it->first.first + 1);
			auto nit = next(it);
			vals[w].erase(it);
			it = nit;
		}

		if (it != vals[w].end() && it->first.first <= r) {
			change(it->second, -(r - it->first.first + 1));
			tot += -(r - it->first.first + 1);
			int re = it->first.second;
			int x = it->second;
			vals[w].erase(it);
			vals[w][mp(r + 1, re)] = x;
		}

		change(cur, r - l + 1);
		tot += r - l + 1;
		if (tot != 0) {
			cout << v << ' ' << l << ' ' << r << ' ' << tot << endl;
			system("pause");
		}
		vals[w][mp(l, r)] = cur;
		if (way[tin[v]] == way[tin[up]]) {
			break;
		}
		v = pr[vert[lm[w]]];
	}
}

void add(int x, int y, int cur) {
	int l = lca(x, y);
	change_tr(x, cur, l);
	change_tr(y, cur, l);
}

int n;

int g[maxn];

int get_time(int v) {
	int w = way[tin[v]];
	int pos = tin[v];

	auto it = vals[w].lower_bound(mp(pos + 1, -1));
	it--;
	int x = it->second;
	int ans = go(x);
	int l = lca(v, g[x]);
	ans -= h[v] + h[g[x]] - 2 * h[l];

	return n - ans + 1;
}

char s[10];

int main() {
	int q;

	bool test = false;

	if (!test)
		cin >> n >> q;
	else
		n = 5000, q = 0;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		if (!test)
			scanf("%d %d", &x, &y);
		else
			x = i + 2, y = rand() % (i + 1) + 1;
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(0, -1);
	build_way();
	build(0);

	change(maxn - 1, n);

	for (int i = 0; i <= posit; i++) {
		vals[i][mp(lm[i], rm[i])] = maxn - 1;
	}

	int cur = 0;

	int prev = 0;

	g[0] = 0;

	for (int i = 1; i < n; i++) {
		add(i, prev, cur++);
		g[cur] = i;
		prev = i;
	}

	if (test) {
		set <int> ss;

		for (int i = 0; i < n; i++) {
			ss.insert(get_time(i));
		}

		cout << ss.size();

		cout << endl;

		cout << (*ss.begin()) << ' ' << (*ss.rbegin()) << endl;
		cout << go(0) << endl;
	}

	while (q--) {
		scanf("%s", s);

		if (s[0] == 'u') {
			int v;

			scanf("%d", &v);
			v--;
			add(v, prev, cur++);
			g[cur] = v;
			prev = v;
		}
		else if (s[0] == 'w') {
			int v;
			scanf("%d", &v);
			v--;
			printf("%d\n", get_time(v));
		}
		else {
			int v, u;
			scanf("%d %d", &v, &u);
			v--;
			u--;
			if (get_time(v) < get_time(u)) {
				printf("%d\n", v + 1);
			}
			else {
				printf("%d\n", u + 1);
			}
		}
	}

	//system("pause");
	return 0;
}