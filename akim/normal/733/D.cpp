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

map<pair<int, int>, pair<int, int> > ma;

int solve() {

	int n;
	scanf("%d", &n);
	int ans = 0, cc = 0, c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (min(a, min(b, c)) > ans) {
			ans = min(a, min(b, c));
			cc = 1;
			c1 = i + 1;
		}
		if (ma.count(mp(min(b, c), max(b, c)))) {
			ma[mp(min(b, c), max(b, c))];
			if (ans < min(ma[mp(min(b, c), max(b, c))].fs + a, min(b, c))) {
				ans = min(ma[mp(min(b, c), max(b, c))].fs + a, min(b, c));
				cc = 2;
				c1 = ma[mp(min(b, c), max(b, c))].sc;
				c2 = i + 1;
			}
		}
		if (ma.count(mp(min(a, c), max(a, c)))) {
			ma[mp(min(a, c), max(a, c))];
			if (ans < min(ma[mp(min(a, c), max(a, c))].fs + b, min(a, c))) {
				ans = min(ma[mp(min(a, c), max(a, c))].fs + b, min(a, c));
				cc = 2;
				c1 = ma[mp(min(a, c), max(a, c))].sc;
				c2 = i + 1;
			}
		}
		if (ma.count(mp(min(a, b), max(a, b)))) {
			ma[mp(min(a, b), max(a, b))];
			if (ans < min(ma[mp(min(a, b), max(a, b))].fs + c, min(a, b))) {
				ans = min(ma[mp(min(a, b), max(a, b))].fs + c, min(a, b));
				cc = 2;
				c1 = ma[mp(min(a, b), max(a, b))].sc;
				c2 = i + 1;
			}
		}
		ma[mp(min(b, c), max(b, c))] = max(ma[mp(min(b, c), max(b, c))], mp(a, i + 1));
		ma[mp(min(a, c), max(a, c))] = max(ma[mp(min(a, c), max(a, c))], mp(b, i + 1));
		ma[mp(min(a, b), max(a, b))] = max(ma[mp(min(a, b), max(a, b))], mp(c, i + 1));
	}

	printf("%d\n", cc);
	if (cc == 1) {
		printf("%d\n", c1);
	} else {
		printf("%d %d\n", c1, c2);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim