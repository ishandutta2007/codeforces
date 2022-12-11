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

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

vector<int> rb[maxn];
int dp[maxn];
int c[maxn];

void dfs(int u, int p = -1) {
	dp[u] = 1;
	for (int v : rb[u]) {
		if (v == p)
			continue;
		dfs(v, u);
		dp[u] = max(dp[u], dp[v] + (c[u] != c[v]));
	}
	return;
}

int ans = mod;
void calc(int u, int w, int p = -1) {
	if (p != -1 && c[p] != c[u]) {
		w++;
	}
	ans = min(ans, max(dp[u], w));
	int mx1 = -1, fr1 = -1, mx2 = -1;
	for (int v : rb[u]) {
		if (v == p)
			continue;
		if (dp[v] + (c[u] != c[v]) > mx1) {
			mx2 = mx1;
			mx1 = dp[v] + (c[u] != c[v]);
			fr1 = v;
		} else if (dp[v] + (c[u] != c[v]) > mx2) {
			mx2 = dp[v] + (c[u] != c[v]);
		}
	}
	for (int v : rb[u]) {
		if (v == p)
			continue;
		calc(v, max(v == fr1 ? mx2 : mx1, w), u);
	}
	return;
}

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}
	dfs(0);
	calc(0, 1);
	ans--;
	printf("%d\n", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim