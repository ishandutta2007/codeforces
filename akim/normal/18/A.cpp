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

void init() {
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
	init();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

int dist(int x1, int y1, int x2, int y2) {
	return (sqr(x1 - x2) + sqr(y1 - y2));
}

bool good(int x1, int y1, int x2, int y2, int x3, int y3) {
	if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && x3 == y3))
		return (0);
	if (dist(x1, y1, x2, y2) + dist(x1, y1, x3, y3) == dist(x2, y2, x3, y3)) {
		return (1);
	}
	swap(x1, x2), swap(y1, y2);
	if (dist(x1, y1, x2, y2) + dist(x1, y1, x3, y3) == dist(x2, y2, x3, y3)) {
		return (1);
	}
	swap(x1, x3), swap(y1, y3);
	if (dist(x1, y1, x2, y2) + dist(x1, y1, x3, y3) == dist(x2, y2, x3, y3)) {
		return (1);
	}
	return (0);
}

int solve() {

	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	if (good(x1, y1, x2, y2, x3, y3)) {
		printf("RIGHT\n");
		return (0);
	}
	if (good(x1 + 1, y1, x2, y2, x3, y3) || good(x1, y1, x2 + 1, y2, x3, y3) || good(x1, y1, x2, y2, x3 + 1, y3)) {
		printf("ALMOST\n");
		return (0);
	}
	if (good(x1 - 1, y1, x2, y2, x3, y3) || good(x1, y1, x2 - 1, y2, x3, y3) || good(x1, y1, x2, y2, x3 - 1, y3)) {
		printf("ALMOST\n");
		return (0);
	}
	if (good(x1, y1 + 1, x2, y2, x3, y3) || good(x1, y1, x2, y2 + 1, x3, y3) || good(x1, y1, x2, y2, x3, y3 + 1)) {
		printf("ALMOST\n");
		return (0);
	}
	if (good(x1, y1 - 1, x2, y2, x3, y3) || good(x1, y1, x2, y2 - 1, x3, y3) || good(x1, y1, x2, y2, x3, y3 - 1)) {
		printf("ALMOST\n");
		return (0);
	}
	printf("NEITHER\n");

	return (0);
}

// by Andrey Kim