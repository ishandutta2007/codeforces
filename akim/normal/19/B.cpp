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
const int maxn = 4100;

ll dp[2][maxn];
bool pm[2][maxn];

int solve() {

	int n;
	scanf("%d", &n);
	dp[1][2000] = 0;
	pm[1][2000] = 1;
	for (int j = 0; j < n; j++) {
		ll t, c;
		scanf("%lld%lld", &t, &c);
		for (int i = 0; i < maxn; i++) {
			if (!pm[1 ^ (j & 1)][i])
				continue;
			pm[1 ^ (j & 1)][i] = 0;
			if (i + t < maxn) {
				pm[j & 1][i + t] = 1;
				dp[j & 1][i + t] = dp[1 ^ (j & 1)][i] + c;
			}
			if (pm[j & 1][i - 1])
				dp[j & 1][i - 1] = min(dp[j & 1][i - 1], dp[1 ^ (j & 1)][i]);
			else {
				pm[j & 1][i - 1] = 1;
				dp[j & 1][i - 1] = dp[1 ^ (j & 1)][i];
			}
		}
	}

	ll ans = mod * 1ll * mod;
	for (int i = 2000; i < maxn; i++) {
		if (pm[1 ^ (n & 1)][i]) {
			ans = min(ans, dp[1 ^ (n & 1)][i]);
		}
	}

	printf("%lld\n", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim