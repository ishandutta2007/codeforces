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
const int maxn = 100;

double a[maxn][maxn];
long double prob[maxn][10];

long double calc(int l, int r, int lev) {
	if(lev == -1) return(0.);
	long double ret = 0.;
	int m = (l + r) >> 1;
	calc(l, m, lev - 1);
	calc(m, r, lev - 1);
	for(int i = l; i < m; i++) {
		for(int j = m; j < r; j++) {
			prob[i][lev + 1] += prob[i][lev] * prob[j][lev] * a[i][j];
			prob[j][lev + 1] += prob[i][lev] * prob[j][lev] * a[j][i];
		}
	}
	return(ret);
}

long double dp[maxn][10][maxn];
bool was[maxn][10][maxn];

long double calc2(int l, int r, int lev, int id = -1) {
	if(lev == -1) return(0.);
	if(!(id  >= l && id < r)) {
		id = maxn - 1;
	}
	if(was[l][lev][id]) {
		return dp[l][lev][id];
	}
	was[l][lev][id] = 1;
	long double &ret = dp[l][lev][id] = 0;
	int m = (l + r) >> 1;
	if(!(id  >= l && id < r)) {
		for(int i = l; i < r; i++) {
			long double ans = 0.;
			ans += calc2(l, m, lev - 1, i);
			ans += calc2(m, r, lev - 1, i);
			ret = max(ret, ans + prob[i][lev + 1] * (1 << lev));
		}
	} else {
		ret = calc2(l, m, lev - 1, id) + calc2(m, r, lev - 1, id) + prob[id][lev + 1] * (1 << lev);
	}
	return(ret);
}

int solution() {

	int n;
	scanf("%d", &n);
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < (1 << n); j++) {
			scanf("%lf", &a[i][j]);
			a[i][j] /= 100;
		}
	}
	for(int i = 0; i < (1 << n); i++) {
		prob[i][0] = 1;
	}
	calc(0, (1 << n), n - 1);
	long double ans = calc2(0, (1 << n), n - 1);
	printf("%.10lf", (double)ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim