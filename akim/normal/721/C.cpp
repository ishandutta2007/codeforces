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

inline pair<pair<bool, bool>, string> useinout();

void init() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
	const string file = useinout().sc;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
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
const int maxn = 5000;

inline pair<pair<bool, bool>, string> useinout() {
	return (mp(mp(0, 0), ""));
}

int t;
bool pm[maxn][maxn];
int l[maxn][maxn];
int to[maxn][maxn];
vector<pair<int, int> > rb[maxn];

bool was[maxn];

void dfs(int u) {
	was[u] = 1;
	for (int i = 0; i < (int) rb[u].size(); i++) {
		int v = rb[u][i].fs, c = rb[u][i].sc;
		if (!was[v])
			dfs(v);
		for (int j = 0; j < maxn; j++) {
			if (pm[v][j] && l[v][j] + c <= t) {
				if (!pm[u][j + 1] || l[u][j + 1] > l[v][j] + c) {
					pm[u][j + 1] = 1;
					l[u][j + 1] = l[v][j] + c;
					to[u][j + 1] = v;
				}
			}
		}
	}
}

int solve() {

	int n, m;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		rb[u].pb(mp(v, c));
	}

	pm[n - 1][0] = 1;
	l[n - 1][0] = 0;
	dfs(0);

	int pos = 0, c = -1;
	for (int i = maxn - 1; i >= 0; i--) {
		if (pm[pos][i]) {
			c = i;
			break;
		}
	}
	printf("%d\n%d ", c + 1, pos + 1);
	while (pos != n - 1) {
		pos = to[pos][c--];
		printf("%d ", pos + 1);
	}

	return (0);
}

// by Andrey Kim