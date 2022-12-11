#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

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

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int c[256], d[256];

bool check(int md, ll cnt) {
	for(int i = 0; i < 256; i++) {
		if(c[i])
			cnt -= max(c[i] * 1ll * md - d[i], 0ll);
	}
	return(cnt >= 0);
}

int solution() {

	string s, t;
	getline(cin, s);
	getline(cin, t);
	for(char ch : t) {
		c[ch]++;
	}
	int cnt = 0;
	for(char ch : s) {
		if(ch == '?') {
			cnt++;
		} else {
			d[ch]++;
		}
	}
	int lf = 0, rg = mod;
	while(lf + 1 < rg) {
		int md = (lf + rg) >> 1;
		if(check(md, cnt)) {
			lf = md;
		} else {
			rg = md;
		}
	}

	int id = 0;
	for(char &ch : s) {
		if(ch == '?') {
			while(id < 256 && c[id] * lf <= d[id]) {
				id++;
			}
			d[ch = (char)(id < 256 ? id : 'a')]++;
		}
	}
	printf("%s", s.c_str());

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim