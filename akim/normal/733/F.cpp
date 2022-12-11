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
const int maxn = 200100;

int w[maxn], c[maxn], snm[maxn], id[maxn];
int u[maxn], v[maxn];
bool used[maxn];
int up[maxn][18];
pair<int, int> mx[maxn][18];

vector<pair<int, int> > rb[maxn];

int getroot(int u) {
	return (u == snm[u] ? u : snm[u] = getroot(snm[u]));
}

bool merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	if (u == v) {
		return (0);
	}
	snm[v] = u;
	return (1);
}

bool cmp(int a, int b) {
	return (w[a] < w[b]);
}

bool pm[maxn];
int tin[maxn], tout[maxn], tima;

void dfs(int u, int p = 0, pair<int, int> vv = mp(0, 0)) {
	pm[u] = 1;
	tin[u] = tima++;
	up[u][0] = p, mx[u][0] = vv;
	for (int i = 1; i < 18; i++) {
		up[u][i] = up[up[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1], mx[up[u][i - 1]][i - 1]);
	}
	for (int i = 0; i < (int) rb[u].size(); i++) {
		int v = rb[u][i].fs, id = rb[u][i].sc;
		if (pm[v] || !used[id]) {
			continue;
		}
		dfs(v, u, mp(w[id], id));
	}
	tout[u] = tima++;
}

int lca(int u, int v) {
	for (int i = 17; i >= 0; i--) {
		int c = up[u][i];
		if (!(tin[c] < tin[v] && tout[c] > tout[v])) {
			u = c;
		}
	}
	return (up[u][0]);
}

pair<int, int> upto(int u, int v) {
	pair<int, int> ret = mp(0, 0);
	for (int i = 17; i >= 0; i--) {
		int c = up[u][i];
		if (!(tin[c] <= tin[v] && tout[c] >= tout[v])) {
			ret = max(ret, mx[u][i]);
			u = c;
		}
	}
	ret = max(ret, mx[u][0]);
	return (ret);
}

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		snm[i] = i;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		u[i]--, v[i]--;
		rb[u[i]].pb(mp(v[i], i));
		rb[v[i]].pb(mp(u[i], i));
		id[i] = i;
	}

	sort(&id[0], &id[m], cmp);

	ll ans = 0;
	for (int i = 0; i < m; i++) {
		if (merge(u[id[i]], v[id[i]])) {
			used[id[i]] = 1;
			ans += w[id[i]];
		}
	}

	dfs(0);

	int s;
	scanf("%d", &s);

	int bstadd = 0, bstdel = 0;
	ll bstans = mod * 1ll * mod;
	for (int i = 0; i < m; i++) {
		int uu = u[i], vv = v[i];
		if (tin[uu] > tin[vv])
			swap(uu, vv);
		if (tout[uu] > tout[vv]) {
			int cc = uu;
			pair<int, int> wei = upto(vv, cc);
			if (bstans > ans - wei.fs + w[i] - s / c[i]) {
				bstans = ans - wei.fs + w[i] - s / c[i];
				bstdel = wei.sc;
				bstadd = i;
			}
		} else {
			int cc = lca(uu, vv);
			pair<int, int> wei = max(upto(vv, cc), upto(uu, cc));
			if (bstans > ans - wei.fs + w[i] - s / c[i]) {
				bstans = ans - wei.fs + w[i] - s / c[i];
				bstdel = wei.sc;
				bstadd = i;
			}
		}
	}

	printf("%lld\n", bstans);
	used[bstdel] = 0;
	used[bstadd] = 1;
	w[bstadd] -= s / c[bstadd];
	for (int i = 0; i < m; i++) {
		if (used[i]) {
			printf("%d %d\n", i + 1, w[i]);
		}
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim