#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
	starttime = 1000. * clock() / CLOCKS_PER_SEC;
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
	} else
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
	fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
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
const int maxn = 1010;

long double p[maxn];
long double dp[maxn][maxn];

int solution() {

	int n, k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		r++;
		ll cnt = 0, all = r - l;
		for(ll i = 1, j = 1; j <= 19; j++, i *= 10) {
			ll u = i * 2, d = i;
			cnt += (u > r ? r : (u < l ? l : u)) - (d > r ? r : (d < l ? l : d));
		}
		p[i] = ((long double)1.) * cnt / all;
	}
	scanf("%d", &k);
	k = (n * k + 99) / 100;

	dp[0][0] = ((long double)1.);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i + 1][j + 1] += dp[i][j] * p[i];
			dp[i + 1][j] += dp[i][j] * (((long double)1.) - p[i]);
		}
	}

	long double ans = 0.;
	for(int j = k; j <= n; j++) {
		ans += dp[n][j];
	}
	printf("%.15lf", (double)ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim