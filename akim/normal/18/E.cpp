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

char c[550][550];
int dp[550][26][26];
int p[550][26][26];

void rec(int m, int n, int c1, int c2) {
	if (n == 0)
		return;
	rec(m, n - 1, p[n][c1][c2] / 26, p[n][c1][c2] % 26);
	for (int i = 0; i < m; i++) {
		printf("%c", (i & 1) ? c2 + 'a' : c1 + 'a');
	}
	printf("\n");
}

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("\n");
		for (int j = 0; j < m; j++) {
			c[i][j] = getchar();
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int c1 = 0; c1 < 26; c1++)
			for (int c2 = 0; c2 < 26; c2++) {
				if (c1 == c2) {
					continue;
				}
				dp[i][c1][c2] = mod;
				int cst = 0;
				for (int j = 0; j < m; j++) {
					if (!((!(j & 1) && c[i][j] - 'a' == c1) || ((j & 1) && c[i][j] - 'a' == c2))) {
						cst++;
					}
				}
				for (int c3 = 0; c3 < 26; c3++)
					for (int c4 = 0; c4 < 26; c4++) {
						if (c3 == c4 || c1 == c3 || c2 == c4) {
							continue;
						}
						if (dp[i][c1][c2] > dp[i - 1][c3][c4] + cst) {
							dp[i][c1][c2] = dp[i - 1][c3][c4] + cst;
							p[i][c1][c2] = 26 * c3 + c4;
						}
					}
			}
	}

	int mn = mod, p1, p2;
	for (int c1 = 0; c1 < 26; c1++) {
		for (int c2 = 0; c2 < 26; c2++) {
			if (c1 == c2)
				continue;
			if (dp[n][c1][c2] < mn) {
				p1 = c1, p2 = c2, mn = dp[n][c1][c2];
			}
		}
	}

	printf("%d\n", mn);
	rec(m, n, p1, p2);

	return (0);
}

// by Andrey Kim