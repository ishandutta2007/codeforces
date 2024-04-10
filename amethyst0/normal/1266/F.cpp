//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)5e5 + 10;

int d[maxn];
int up[maxn];

vector <int> ed[maxn];

void dfs(int v, int p = -1) {
	d[v] = 0;

	for (int u : ed[v]) {
		if (u != p) {
			dfs(u, v);
			d[v] = max(d[v], d[u] + 1);
		}
	}
}

int pr[maxn];

bool cmp(int x, int y) {
	return d[x] < d[y];
}

vector <pii> w[maxn];

void rdfs(int v, int p, int u) {
	u++;
	up[v] = u;
	pr[v] = p;

	pii f = mp(u, 0);

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		int x = d[u] + 1;

		if (f.first < x) {
			f.second = f.first;
			f.first = x;
		}
		else if (f.second < x) {
			f.second = x;
		}
	}

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		if (d[u] + 1 != f.first) {
			rdfs(u, v, f.first);
		}
		else {
			rdfs(u, v, f.second);
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		if (ed[v][i] == pr[v]) {
			swap(ed[v][i], ed[v].back());
			ed[v].pop_back();
		}
	}

	sort(ed[v].begin(), ed[v].end(), cmp);

	vector <int> x;

	for (int u : ed[v]) {
		x.push_back(d[u] + 1);
	}

	if (v != 1)
		x.push_back(up[v]);
	sort(x.begin(), x.end());

	for (int i = 0; i < (int)x.size(); ) {
		int r = i;

		while (r < (int)x.size() && x[r] == x[i]) {
			r++;
		}

		w[v].push_back(mp(x[i], (int)x.size() - i));
		i = r;
	}
}

int a[maxn];
int b[maxn];

void upd(int v) {
	vector <int> g;
	g.push_back(up[v]);
	
	for (int u : ed[v]) {
		g.push_back(d[u] + 1);
	}

	sort(g.begin(), g.end());

	for (int i = 0; i < (int)g.size(); ) {
		int r = i;

		while (r < (int)g.size() && g[r] == g[i]) {
			r++;
		}

		if (g[i] != 0) {
			a[g[i] - 1] = max(a[g[i] - 1], (int)g.size() - i);
		}

		b[g[i]] = max(b[g[i]], (int)g.size() - i);

		a[g[i]] = max(a[g[i]], (int)g.size() - r + 1);

		i = r;
	}
}

int c[maxn];

void build(int v, int it) {
	int u = ed[v][it];

	int a = up[u];
	int b = d[u] + 1;

	int pos = 0;

	int i = 0;

	while (!(i == (int)w[v].size() && pos == (int)w[u].size())) {
		int cur = 0;
		
		int x = (int)1e9;
		
		if (i < (int)w[v].size()) {
			cur += w[v][i].second;
			x = min(x, w[v][i].first);
		}

		if (pos != (int)w[u].size()) {
			cur += w[u][pos].second;
			x = min(x, w[u][pos].first);
		}

		if (a >= x) {
			cur--;
		}

		if (b >= x) {
			cur--;
		}

		c[x] = max(c[x], cur);

		if (i == (int)w[v].size()) {
			pos++;
		}
		else if (pos == (int)w[u].size()) {
			i++;
		}
		else if (w[v][i].first < w[u][pos].first) {
			i++;
		}
		else {
			pos++;
		}
	}
}

int ans[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		ans[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		ans[1] = max(ans[1], (int)ed[i].size() + 1);
	}

	dfs(1);
	rdfs(1, -1, -1);

	for (int v = 1; v <= n; v++) {
		upd(v);

		for (int i = 0; i < (int)ed[v].size(); i++) {
			build(v, i);
		}
	}

	for (int i = maxn - 2; i >= 0; i--) {
		a[i] = max(a[i + 1], a[i]);
		b[i] = max(b[i + 1], b[i]);
		c[i] = max(c[i + 1], c[i]);

		ans[2 * i + 1] = max(ans[2 * i + 1], a[i]);
		ans[2 * i] = max(ans[2 * i], b[i]);
		ans[2 * i] = max(ans[2 * i], c[i]);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

	//system("pause");
}