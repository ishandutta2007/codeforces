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
const int maxn = 200100;

int p[maxn];
pair<int, int> s[maxn];
map<int, vector<int> > c;
int pe[maxn], ans[maxn];

int solve() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		c[p[i]].pb(i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &s[i].fs);
		s[i].sc = i;
	}
	sort(&s[0], &s[m]);
	int u = 0, cc = 0;
	for (int i = 0; i < m; i++) {
		while (s[i].fs > 1 && c[s[i].fs].empty()) {
			s[i].fs = (s[i].fs + 1) / 2;
			pe[s[i].sc]++;
		}
		if (!c[s[i].fs].empty()) {
			ans[c[s[i].fs].back()] = s[i].sc + 1;
			c[s[i].fs].ppb();
			u += pe[s[i].sc];
			cc++;

		} else {
			pe[s[i].sc] = 0;
		}
	}
	printf("%d %d\n", cc, u);
	for (int i = 0; i < m; i++) {
		printf("%d ", pe[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

// by Andrey Kim