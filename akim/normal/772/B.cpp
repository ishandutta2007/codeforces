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
const int maxn = 100100;

double x[maxn], y[maxn];

double dist(int i, int j, int k) {
	return(abs((y[k] - y[i]) * x[j] - (x[k] - x[i]) * y[j] + x[k] * y[i] - y[k] * x[i]) / sqrt(sqr(y[k] - y[i]) + sqr(x[k] - x[i])));
}

int solution() {

	int n;
	scanf("%d", &n);
	double ans = mod * 1. * mod;
	for(int i = 0; i < n; i++) {
		scanf("%lf%lf", &x[i], &y[i]);
		for(int j = 0; j < i; j++) {
			ans = min(ans, sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])) / 2.);
		}
		x[i + n] = x[i], y[i + n] = y[i];
	}

	for(int i = 0; i < n; i++) {
		int j = i + 1, k = i + 2;
		ans = min(ans, dist(i, j, k) / 2.);
	}

	printf("%.10lf", ans);


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim