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
const int maxn = 110;

vector<int> rb[maxn];

ll dp[maxn][22][2], tmp[22][2], tmp2[22][2];
int k;

void dfs(int u, int p = -1) {
	dp[u][0][0] = 1;
	dp[u][0][1] = 1;
	for (int v : rb[u]) {
		if (v == p)
			continue;
		dfs(v, u);

		for (int i = 0; i <= k; i++) {
			tmp[i][0] = tmp[i][1] = 0;
		}

		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
//
				tmp[min(i, j + 1)][0] += dp[u][i][0] * dp[v][j][0] % mod;
//
				if (i + j + 1 > k) {
					tmp[j + 1][1] += dp[u][i][0] * dp[v][j][1] % mod;
				} else {
					tmp[i][0] += dp[u][i][0] * dp[v][j][1] % mod;
				}
//
				if (i + j + 1 > k) {
					tmp[i][1] += dp[u][i][1] * dp[v][j][0] % mod;
				} else {
					tmp[j + 1][0] += dp[u][i][1] * dp[v][j][0] % mod;
				}
//
				tmp[max(i, j + 1)][1] += dp[u][i][1] * dp[v][j][1] % mod;
//
			}
		}

		for (int i = 0; i <= k; i++) {
			dp[u][i][0] = tmp[i][0] % mod;
			dp[u][i][1] = tmp[i][1] % mod;
		}
	}
}

int solution() {

	int n;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	dfs(0);

	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		ans += dp[0][i][0];
//		cout << dp[0][i][0];
	}
	ans %= mod;
	printf("%lld", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim