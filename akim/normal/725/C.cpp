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

vector<int> vc[26];
char ans[2][30];

int solve() {

	string s;
	getline(cin, s);
	int c;
	for (int i = 0; i < 27; i++) {
		if (i && s[i] == s[i - 1]) {
			printf("Impossible\n");
			return (0);
		}
		vc[s[i] - 'A'].pb(i);
		if ((int) vc[s[i] - 'A'].size() == 2) {
			c = s[i] - 'A';
		}
	}

	s.erase(vc[c][1], 1);

	int pos = 13 - (vc[c][1] - vc[c][0] + 1) / 2, p = 0;
	int i = vc[c][0];
	while (i < 26) {
		ans[p][pos] = s[i];
		i++;
		if (p) {
			pos--;
			if (pos == -1) {
				pos++, p = 1 - p;
			}
		} else {
			pos++;
			if (pos == 13) {
				pos--, p = 1 - p;
			}
		}
	}
	i = 0;
	while (i < vc[c][0]) {
		ans[p][pos] = s[i];
		i++;
		if (p) {
			pos--;
			if (pos == -1) {
				pos++, p = 1 - p;
			}
		} else {
			pos++;
			if (pos == 13) {
				pos--, p = 1 - p;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 13; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim