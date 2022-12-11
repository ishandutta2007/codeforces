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
	return (mp(mp(1, 0), mp("", 0)));
}

int deo[4 * maxn];

void build(int v = 0, int tl = 0, int tr = maxn - 1) {
	if (tl == tr) {
		deo[v] = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	deo[v] = (deo[v * 2 + 1] | deo[v * 2 + 2]);
	return;
}

void del(int pos, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (pos < tl || pos > tr)
		return;
	if (tl == tr) {
		deo[v] = 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	del(pos, v * 2 + 1, tl, tm);
	del(pos, v * 2 + 2, tm + 1, tr);
	deo[v] = (deo[v * 2 + 1] | deo[v * 2 + 2]);
	return;
}

int get(int lf, int rg, int np, int v = 0, int tl = 0, int tr = maxn - 1) {
	if (rg < tl || lf > tr)
		return (-1);
	if (tl == tr) {
		return (deo[v] ? tr : -1);
	}
	if (!deo[v])
		return (-1);
	int tm = (tl + tr) >> 1;
	if (np == 1) {
		int r = get(lf, rg, np, v * 2 + 2, tm + 1, tr);
		if (r == -1) {
			int l = get(lf, rg, np, v * 2 + 1, tl, tm);
			return (l);
		} else {
			return (r);
		}
	} else {
		int l = get(lf, rg, np, v * 2 + 1, tl, tm);
		if (l == -1) {
			int r = get(lf, rg, np, v * 2 + 2, tm + 1, tr);
			return (r);
		} else {
			return (l);
		}
	}
}

vector<int> c[maxn];

int solve() {

	int m;
	scanf("%d\n", &m);
	string s;
	getline(cin, s);
	int n = s.length();
	char BUG = 'z';
	for (int i = 0; i < n; i++) {
		c[s[i] - 'a'].pb(i + 1);
		BUG = min(s[i], BUG);
	}

	build();

	for (int i = 26; i >= 0; i--) {
		bool ok = 1;

		for (int j = c[i].size() - 1; j >= 0; j--) {
			int pos = c[i][j];
			int lf = get(pos - m + 1, pos - 1, 1), rg = get(pos + 1, pos + m - 1, 0);
			if (lf != -1 && rg != -1 && rg - lf <= m) {
				c[i].ppb();
				del(pos);
			} else {
				ok = 0;
			}
		}

		if (!ok) {
			break;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		while (!c[i].empty()) {
			c[i].ppb();
			printf("%c", 'a' + i);
			cnt++;
		}
	}
	if (!cnt) {
		printf("%c", BUG);
	}

	return (0);
}

// by Andrey Kim