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
const int maxn = 100100;

char a[8];
int xx[8], yy[8], f[8];

int solution() {

	int n;
	scanf("%d", &n);
	int x0, y0;
	scanf("%d%d", &x0, &y0);
	for (int i = 0; i < n; i++) {
		char c;
		int x, y;
		scanf("\n%c%d%d", &c, &x, &y);
		if (x - x0 == y - y0) {
			if (x > x0) {
				if (f[0] == 0 || xx[0] - x0 > x - x0) {
					f[0] = 1;
					xx[0] = x;
					yy[0] = y;
					a[0] = c;
				}
			} else {
				if (f[1] == 0 || x0 - xx[1] > x0 - x) {
					f[1] = 1;
					xx[1] = x;
					yy[1] = y;
					a[1] = c;
				}
			}
		}
		if (x - x0 == y0 - y) {
			if (x > x0) {
				if (f[2] == 0 || xx[2] - x0 > x - x0) {
					f[2] = 1;
					xx[2] = x;
					yy[2] = y;
					a[2] = c;
				}
			} else {
				if (f[3] == 0 || x0 - xx[3] > x0 - x) {
					f[3] = 1;
					xx[3] = x;
					yy[3] = y;
					a[3] = c;
				}
			}
		}
		if (x == x0) {
			if (y < y0) {
				if (f[4] == 0 || y0 - yy[4] > y0 - y) {
					f[4] = 1;
					xx[4] = x;
					yy[4] = y;
					a[4] = c;
				}
			} else {
				if (f[5] == 0 || yy[5] - y0 > y - y0) {
					f[5] = 1;
					xx[5] = x;
					yy[5] = y;
					a[5] = c;
				}
			}
		}
		if (y == y0) {
			if (x < x0) {
				if (f[6] == 0 || x0 - xx[6] > x0 - x) {
					f[6] = 1;
					xx[6] = x;
					yy[6] = y;
					a[6] = c;
				}
			} else {
				if (f[7] == 0 || xx[7] - x0 > x - x0) {
					f[7] = 1;
					xx[7] = x;
					yy[7] = y;
					a[7] = c;
				}
			}
		}
	}

	bool ok = 0;
	for (int i = 0; i < 8; i++) {
		if (f[i] && a[i] == 'Q')
			ok = 1;
	}
	for (int i = 0; i < 4; i++) {
		if (f[i] && a[i] == 'B')
			ok = 1;
	}
	for (int i = 4; i < 8; i++) {
		if (f[i] && a[i] == 'R')
			ok = 1;
	}
	if (ok) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim