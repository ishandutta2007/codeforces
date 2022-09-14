#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (int)2e5 + 10, maxlog = 18;
int p[maxlog][maxn];
vector <int> ed[maxn];
int tt = -1;
int tin[maxn], tout[maxn];

void dfs(int v, int par) {
	p[0][v] = par;

	for (int i = 1; i < maxlog; i++) {
		p[i][v] = p[i - 1][p[i - 1][v]];
	}

	tin[v] = ++tt;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs(u, v);
	}

	tout[v] = tt;
}

int dp[maxlog][maxn];

void dfs1(int v) {
	for (int i = 1; i < maxlog; i++) {
		dp[i][v] = dp[i - 1][dp[i - 1][v]];
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs1(u);
	}
}

int anc(int x, int y) {
	return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
	if (anc(x, y)) {
		return x;
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (!anc(p[i][x], y)) {
			x = p[i][x];
		}
	}

	return p[0][x];
}

bool cmp(pair <int, pii> a, pair <int, pii> b) {
	return tin[a.first] < tin[b.first];
}

int pr[maxn];

int make(int x, int l) {
	if (x != l && anc(x, l)) {
		return l;
	}
	
	if (dp[0][x] == -1) {
		dp[0][x] = l;
	}

	if (x == l) {
		return l;
	}

	pr[x] = make(pr[x], l);
}

int get_cnt(int a, int l) {
	if (a == l) {
		return 0;
	}

	int ans = 0;

	for (int i = maxlog - 1; i >= 0; i--) {
		if (!anc(dp[i][a], l)) {
			a = dp[i][a];
			ans += (1 << i);
		}
	}

	if (dp[0][a] == a) {
		return maxn;
	}

	return ans + 1;
}

int up(int a, int cnt) {
	for (int i = maxlog - 1; i >= 0; i--) {
		if ((1 << i) <= cnt) {
			a = dp[i][a];
			cnt -= (1 << i);
		}
	}

	return a;
}

int res[maxn];

pair <pii, pii> z[maxn];

vector <int> pt[maxn];
vector <int> t[4 * maxn];

void build(int it, int l, int r) {
	if (l == r) {
		t[it] = pt[l];
		sort(t[it].begin(), t[it].end());
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		t[it].resize(t[2 * it].size() + t[2 * it + 1].size());

		merge(t[2 * it].begin(), t[2 * it].end(), t[2 * it + 1].begin(), t[2 * it + 1].end(), t[it].begin());
	}
}

bool go(int it, int l, int r, int lm, int rm, int tl, int tr) {
	if (l == lm && r == rm) {
		return lower_bound(t[it].begin(), t[it].end(), tl) != upper_bound(t[it].begin(), t[it].end(), tr);
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm, tl, tr);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm, tl, tr);
		}
		else {
			return go(2 * it, l, m, lm, m, tl, tr) || go(2 * it + 1, m + 1, r, m + 1, rm, tl, tr);
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		int x;

		scanf("%d", &x);

		ed[x].push_back(i);

		pr[i] = x;
	}

	dfs(1, 1);

	vector <pair <int, pii> > g;

	int m;

	cin >> m;

	g.resize(m);

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		g[i] = mp(lca(x, y), mp(x, y));

		pt[tin[x]].push_back(tin[y]);
		pt[tin[y]].push_back(tin[x]);
	}

	build(1, 0, n - 1);

	sort(g.begin(), g.end(), cmp);

	memset(dp, -1, sizeof dp);

	for (int i = 0; i < m; i++) {
		int x = g[i].second.first;
		int y = g[i].second.second;
		int l = g[i].first;

		make(x, l);
		make(y, l);
	}

	for (int i = 1; i <= n; i++) {
		if (dp[0][i] == -1) {
			dp[0][i] = i;
		}
	}

	dfs1(1);

	int q;

	cin >> q;

	vector <int> nd;

	for (int i = 0; i < q; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		int l = lca(a, b);

		int cnt1 = get_cnt(a, l);
		int cnt2 = get_cnt(b, l);

		if (cnt1 == maxn || cnt2 == maxn) {
			res[i] = -1;
			continue;
		}

		res[i] = cnt1 + cnt2;

		if (cnt1 != 0 && cnt2 != 0) {
			nd.push_back(i);
			a = up(a, cnt1 - 1);
			b = up(b, cnt2 - 1);

			z[i] = mp(mp(tin[a], tout[a]), mp(tin[b], tout[b]));
		}
	}

	for (int i = 0; i < (int)nd.size(); i++) {
		int p = nd[i];

		if (go(1, 0, n - 1, z[p].first.first, z[p].first.second, z[p].second.first, z[p].second.second)) {
			res[p]--;
		}
	}

	for (int i = 0; i < q; i++) {
		printf("%d\n", res[i]);
	}

	//system("pause");
}