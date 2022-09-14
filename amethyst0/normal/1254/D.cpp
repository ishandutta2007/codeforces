//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
int sz[maxn];
int pr[maxn];
int h[maxn];
vector <int> ed[maxn];

bool cmp(int a, int b) {
	return sz[a] > sz[b];
}

int dfs(int v, int p, int hh = 0) {
	sz[v] = 1;
	pr[v] = p;
	h[v] = hh;
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

const int mod = 998244353;

int t[maxn];

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}

	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		x = mul(x, x);
		y >>= 1;
	}

	return ans;
}

void change(int pos, int x) {
	for (; pos < maxn; pos |= pos + 1) {
		t[pos] = add(t[pos], x);
	}
}

int go(int pos) {
	int ans = 0;

	for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans = add(ans, t[pos]);
	}

	return ans;
}

int dd[maxn];

int go(int l, int r) {
	return sub(go(r), go(l - 1));
}

int tot = 0;
int n;

void change_tr(int v, int d) {
	dd[v] = add(dd[v], d);
	tot = add(tot, mul(sz[v], d));
	int w = way[tin[v]];

	if (tin[v] != rm[v]) {
		int to = vert[tin[v] + 1];

		int cur = n - sz[v] - sz[to];
		if (cur < 0) {
			cur += mod;
		}

		change(tin[v], mul(cur, d));
	}
}

int go_tr(int v) {
	int ans = tot;

	int a = dd[v];
	a = mul(a, n - sz[v]);
	ans = add(ans, a);

	while (v != -1) {
		int w = way[tin[v]];
		if (tin[v] != lm[w]) {
			ans = add(ans, go(lm[w], tin[v] - 1));
		}
		
		v = vert[lm[w]];

		if (v != 0) {
			int cur = n - sz[v] - sz[pr[v]];
			if (cur < 0) {
				cur += mod;
			}

			ans = add(ans, mul(dd[pr[v]], cur));
		}

		v = pr[v];
	}

	return ans;
}

int main() {
	int q;

	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(0, -1);
	build_way();
	build(0);

	int rn = my_pow(n, mod - 2);

	while (q--) {
		int tp;

		scanf("%d", &tp);

		if (tp == 1) {
			int v, d;

			scanf("%d %d", &v, &d);
			v--;

			change_tr(v, d);
		}
		else {
			int v;

			scanf("%d", &v);
			v--;

			printf("%d\n", mul(go_tr(v), rn));
		}
	}

	//system("pause");
}