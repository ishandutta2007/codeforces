#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void initialization() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solve();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 400100;

vector<pair<int, int> > rb[maxn];
int u[maxn], v[maxn], o[maxn], st[maxn], snm[maxn], sz[maxn], tin[maxn], fup[maxn], tt = 0, msz = 1, vv = 0;
bool pm1[maxn], pm[maxn];

int getroot(int u) {
	return (snm[u] == u ? u : snm[u] = getroot(snm[u]));
}

void merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	if (u == v)
		return;
	snm[v] = u;
	sz[u] += sz[v];
	if (sz[u] > msz) {
		msz = sz[u];
		vv = u;
	}
}

void dfs1(int u, int p = -1) {
	pm1[u] = 1;
	tin[u] = fup[u] = tt++;
	for (int i = 0; i < (int) rb[u].size(); i++) {
		int v = rb[u][i].fs;
		if (p == v) {
			continue;
		}
		if (pm1[v]) {
			fup[u] = min(tin[v], fup[u]);
			continue;
		}
		dfs1(v, u);
		if (fup[v] > tin[u]) {

		} else {
			merge(u, v);
		}
		fup[u] = min(fup[v], fup[u]);
	}
}

void dfs(int uu, int p = -1) {
	pm[uu] = 1;
	for (int i = 0; i < (int) rb[uu].size(); i++) {
		int vv = rb[uu][i].fs, cc = rb[uu][i].sc;
		if (vv == p)
			continue;
		if (u[cc] == vv) {
			st[cc] = 1;
		} else {
			if (!st[cc]) {
				st[cc] = 1;
				o[cc] = 1;
			}
		}
		if (pm[vv]) {
			continue;
		}
		dfs(vv, uu);
	}
}

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		snm[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		u[i]--, v[i]--;
		rb[u[i]].pb(mp(v[i], i));
		rb[v[i]].pb(mp(u[i], i));
	}

	dfs1(0);
	dfs(vv);

	printf("%d\n", msz);
	for (int i = 0; i < m; i++) {
		if (o[i]) {
			printf("%d %d\n", v[i] + 1, u[i] + 1);
		} else {
			printf("%d %d\n", u[i] + 1, v[i] + 1);
		}
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim