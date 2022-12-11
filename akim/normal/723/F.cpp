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

void init() {
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
	init();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

int snm[maxn];
int cs[maxn], ct[maxn];
bool pm[maxn];
vector<int> rb[maxn];
vector<pair<int, int> > ans;

int getroot(int u) {
	return (u == snm[u] ? u : snm[u] = getroot(snm[u]));
}

void merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	snm[v] = u;
}

void dfs(int u) {
	pm[u] = 1;
	for (int i = 0; i < (int) rb[u].size(); i++) {
		int v = rb[u][i];
		if (pm[v])
			continue;
		dfs(v);
		merge(u, v);
		ans.pb(mp(u, v));
	}
}

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		snm[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	int s, t, ds, dt;
	scanf("%d%d%d%d", &s, &t, &ds, &dt);
	s--, t--;
	pm[s] = 1;
	pm[t] = 1;
	for (int i = 0; i < n; i++) {
		if (!pm[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < (int) rb[s].size(); i++) {
		int v = getroot(rb[s][i]);
		cs[getroot(v)] = 1;
	}
	for (int i = 0; i < (int) rb[t].size(); i++) {
		int v = getroot(rb[t][i]);
		ct[getroot(v)] = 1;
	}

	for (int i = 0; i < (int) rb[s].size(); i++) {
		int v = getroot(rb[s][i]);
		if (v != getroot(s) && v != getroot(t) && ct[v] == 0) {
			ans.pb(mp(s, rb[s][i]));
			merge(s, v);
			ds--;
		}
	}
	for (int i = 0; i < (int) rb[t].size(); i++) {
		int v = getroot(rb[t][i]);
		if (v != getroot(s) && v != getroot(t) && cs[v] == 0) {
			ans.pb(mp(t, rb[t][i]));
			merge(t, v);
			dt--;
		}
	}

	for (int i = 0; i < (int) rb[s].size(); i++) {
		int v = getroot(rb[s][i]);
		if (v != getroot(s) && v != getroot(t) && ds > 0) {
			ans.pb(mp(s, rb[s][i]));
			merge(s, v);
			ds--;
		}
	}
	for (int i = 0; i < (int) rb[t].size(); i++) {
		int v = getroot(rb[t][i]);
		if (v != getroot(s) && v != getroot(t) && dt > 0) {
			ans.pb(mp(t, rb[t][i]));
			merge(t, v);
			dt--;
		}
	}

	for (int i = 0; i < (int) rb[s].size(); i++) {
		int v = getroot(rb[s][i]);
		if (v != getroot(s) && rb[s][i] != t && ds > 0) {
			ans.pb(mp(s, rb[s][i]));
			merge(s, v);
			ds--;
		}
	}
	for (int i = 0; i < (int) rb[t].size(); i++) {
		int v = getroot(rb[t][i]);
		if (v != getroot(t) && rb[t][i] != s && dt > 0) {
			ans.pb(mp(t, rb[t][i]));
			merge(t, v);
			dt--;
		}
	}
	for (int i = 0; i < (int) rb[s].size(); i++) {
		int v = getroot(rb[s][i]);
		if (v != getroot(s) && rb[s][i] == t && ds > 0) {
			ans.pb(mp(s, rb[s][i]));
			merge(s, v);
			ds--;
			dt--;
		}
	}

	bool ok = 1;
	int rt = getroot(0);
	for (int i = 0; i < n; i++) {
		if (getroot(i) != rt) {
			ok = 0;
		}
	}

	if (ds >= 0 && dt >= 0 && ok) {
		printf("Yes\n");
		for (int i = 0; i < (int) ans.size(); i++) {
			printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
		}
	} else {
		printf("No\n");
	}

	return (0);
}

// by Andrey Kim