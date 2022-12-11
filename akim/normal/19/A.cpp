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

map<string, int> ma;
int id = 0;

vector<pair<int, pair<int, pair<int, string> > > > vc;

int solve() {

	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		ma[s] = id++;
		vc.pb(mp(0, mp(0, mp(0, s))));
	}
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		string s, t;
		cin >> s;
		bool ok = 0;
		for (int i = 0; i < (int) s.length(); i++) {
			if (ok)
				t.pb(s[i]);
			if (s[i] == '-')
				ok = 1;
		}
		while (s.back() != '-') {
			s.ppb();
		}
		s.ppb();
		int x, y;
		scanf("%d:%d\n", &x, &y);
		int id1 = ma[s], id2 = ma[t];
		vc[id1].fs += (x > y ? 3 : (x == y ? 1 : 0));
		vc[id2].fs += (y > x ? 3 : (y == x ? 1 : 0));
		vc[id1].sc.fs += x - y;
		vc[id2].sc.fs += y - x;
		vc[id1].sc.sc.fs += x;
		vc[id2].sc.sc.fs += y;
	}

	sort(vc.begin(), vc.end());
	reverse(vc.begin(), vc.end());
	vector<string> vc1;
	for (int i = 0; i < n / 2; i++) {
		vc1.pb(vc[i].sc.sc.sc);
	}
	sort(vc1.begin(), vc1.end());
	for (int i = 0; i < n / 2; i++) {
		printf("%s\n", vc1[i].c_str());
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

// by Andrey Kim