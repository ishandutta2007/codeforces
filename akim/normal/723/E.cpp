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
const int maxn = 100100;

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

int pm[maxn];
int u[maxn], v[maxn];
int gd[maxn];

vector<pair<int, int> > rb[maxn];

void dfs(int u) {
	for (int i = 0; i < (int) rb[u].size(); i++) {
		int vv = rb[u][i].fs, c = rb[u][i].sc;
		if (pm[c])
			continue;
		pm[c] = 1;
		dfs(vv);
		if (v[c] == vv) {
			gd[c] = 1;
		} else {
			gd[c] = 0;
		}
	}
}

int solve() {

	int t;
	scanf("%d", &t);
	for (; t--;) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			rb[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u[i], &v[i]);
			u[i]--, v[i]--;
			rb[u[i]].pb(mp(v[i], i));
			rb[v[i]].pb(mp(u[i], i));
			pm[i] = 0;
		}
		int c = 0;
		vector<int> vc;
		for (int i = 0; i < n; i++) {
			if (rb[i].size() & 1) {
				vc.pb(i);
			} else
				c++;
		}
		int mm = m;
		while (!vc.empty()) {
			int u = vc.back();
			vc.ppb();
			int v = vc.back();
			vc.ppb();
			rb[u].pb(mp(v, mm));
			rb[v].pb(mp(u, mm));
			pm[mm] = 0;
			mm++;
		}
		for (int i = 0; i < n; i++) {
			dfs(i);
		}

		printf("%d\n", c);
		for (int i = 0; i < m; i++) {
			if (gd[i]) {
				printf("%d %d\n", u[i] + 1, v[i] + 1);
			} else {
				printf("%d %d\n", v[i] + 1, u[i] + 1);
			}
		}

	}

	return (0);
}

// by Andrey Kim