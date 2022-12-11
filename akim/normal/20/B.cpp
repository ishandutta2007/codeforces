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
const int maxn = 100100;



int solve() {

	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);

	if (abs(a) < eps) {
		if (abs(b) < eps) {
			if (abs(c) < eps) {
				printf("-1\n");
				return (0);
			} else {
				printf("0\n");
				return (0);
			}
		} else {
			if (abs(c) < eps) {
				printf("1\n0.00\n");
				return (0);
			} else {
				printf("1\n%.10lf", -c / b);
				return (0);
			}
		}
	} else {
		if (abs(b) < eps) {
			if (abs(c) < eps) {
				printf("1\n0.00");
				return (0);
			} else {
				if (-c / a >= 0) {
					printf("1\n%.10lf", sqrt(-c / a));
					return (0);
				} else {
					printf("0\n");
					return (0);
				}
			}
		} else {

			double d = sqr(b) - 4. * a * c;
			if (d < -eps) {
				printf("0\n");
				return (0);
			} else if (abs(d) < eps) {
				printf("1\n%.10lf", -b / 2. / a);
				return (0);
			} else {
				printf("2\n%.10lf\n%.10lf", min((-b + sqrt(d)) / 2. / a, (-b - sqrt(d)) / 2. / a), max((-b + sqrt(d)) / 2. / a, (-b - sqrt(d)) / 2. / a));
				return (0);
			}
		}
	}


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim