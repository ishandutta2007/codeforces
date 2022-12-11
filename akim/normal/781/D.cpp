#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//																														tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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
	srand(__rdtsc());
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
const int maxn = 100100;

bitset<550> dp[61][2][550], tmp;

bool pm[550][61][2];
ll pd[550][61][2];

int solution() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		dp[0][c][u][v] = 1;
	}

	for (int i = 1; i < 61; i++) {
		for (int u = 0; u < n; u++) {
			tmp.reset();
			for (int v = 0; v < n; v++) {
				if (dp[i - 1][0][u][v]) {
					tmp |= dp[i - 1][1][v];
				}
			}
			dp[i][0][u] = tmp;
			tmp.reset();
			for (int v = 0; v < n; v++) {
				if (dp[i - 1][1][u][v]) {
					tmp |= dp[i - 1][0][v];
				}
			}
			dp[i][1][u] = tmp;
		}
	}

	ll ans = 0;
	pm[0][60][0] = 1;
	pd[0][60][0] = 0;
	for (int i = 60; i >= 0; i--) {
		for (int u = 0; u < n; u++) {
			if (pm[u][i][0]) {
				pm[u][i - 1][0] = 1;
				pd[u][i - 1][0] = max(pd[u][i - 1][0], pd[u][i][0]);
				for (int v = 0; v < n; v++) {
					if (dp[i][0][u][v]) {
						ll dist = pd[u][i][0] + (1ll << i);
						if (i - 1 >= 0) {
							pm[v][i - 1][1] = 1;
							pd[v][i - 1][1] = max(pd[v][i - 1][1], dist);
						}
						ans = max(ans, dist);
					}
				}
			}
			if (pm[u][i][1]) {
				pm[u][i - 1][1] = 1;
				pd[u][i - 1][1] = max(pd[u][i - 1][1], pd[u][i][1]);
				for (int v = 0; v < n; v++) {
					if (dp[i][1][u][v]) {
						ll dist = pd[u][i][1] + (1ll << i);
						if (i - 1 >= 0) {
							pm[v][i - 1][0] = 1;
							pd[v][i - 1][0] = max(pd[v][i - 1][0], dist);
						}
						ans = max(ans, dist);
					}
				}
			}
		}
	}

	if (ans > 1e18) {
		printf("-1");
	} else {
		printf("%lld", ans);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim