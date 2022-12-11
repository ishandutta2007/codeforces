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
typedef long double ld;

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

const long double eps = 1e-14;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;



int solution() {

	int n;
	scanf("%d", &n);
	int x0, y0, x1, y1;
	scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
	ld lans = 0, rans = mod;
	for(int i = 0; i < n; i++) {
		int rx, ry, vx, vy;
		scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
		if(vx == 0 && vy == 0) {
			if(!(rx > x0 && ry > y0 && rx < x1 && ry < y1)) {
				printf("-1");
				return(0);
			}
		} else
		if(vx == 0) {
			if(!(rx > x0 && rx < x1)) {
				printf("-1");
				return(0);
			}
			ld lf = max({ min((y0 - ry) * ld(1.) / vy, (y1 - ry) * ld(1.) / vy) });
			ld rg = min({ max((y0 - ry) * ld(1.) / vy, (y1 - ry) * ld(1.) / vy) });
			lf = max(lf, (ld)0.);
			if(lf + eps < rg) {
				lans = max(lans, lf);
				rans = min(rans, rg);
			} else {
				printf("-1");
				return(0);
			}
		} else
		if(vy == 0) {
			if(!(ry > y0 && ry < y1)) {
				printf("-1");
				return(0);
			}
			ld lf = max({ min((x0 - rx) * ld(1.) / vx, (x1 - rx) * ld(1.) / vx) });
			ld rg = min({ max((x0 - rx) * ld(1.) / vx, (x1 - rx) * ld(1.) / vx) });
			lf = max(lf, (ld)0.);
			if(lf + eps < rg) {
				lans = max(lans, lf);
				rans = min(rans, rg);
			} else {
				printf("-1");
				return(0);
			}
		} else {
			ld lf = max(min((x0 - rx) * ld(1.) / vx, (x1 - rx) * ld(1.) / vx), min((y0 - ry) * ld(1.) / vy, (y1 - ry) * ld(1.) / vy));
			ld rg = min(max((x0 - rx) * ld(1.) / vx, (x1 - rx) * ld(1.) / vx), max((y0 - ry) * ld(1.) / vy, (y1 - ry) * ld(1.) / vy));
			lf = max(lf, (ld)0.);
			if(lf + eps < rg) {
				lans = max(lans, lf);
				rans = min(rans, rg);
			} else {
				printf("-1");
				return(0);
			}
		}
	}
	if(lans + eps < rans) {
		printf("%.10lf", (double)lans);
	} else {
		printf("-1");
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim