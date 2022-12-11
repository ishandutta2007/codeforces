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

map<string, int> ma;
char buff[maxn];
string s;

int get(int l, int r) {
	for(int i = r, bal = 0; i >= l; i--) {
		bal += s[i] == '(';
		bal -= s[i] == ')';
		if(!bal && (s[i] == '+' || s[i] == '-')) {
			int lft = get(l, i - 1), rgh = get(i + 1, r);
			return(lft && rgh && (s[i] != '-' || rgh > 1));
		}
	}
	for(int i = r, bal = 0; i >= l; i--) {
		bal += s[i] == '(';
		bal -= s[i] == ')';
		if(!bal && (s[i] == '*' || s[i] == '/')) {
			int lft = get(l, i - 1), rgh = get(i + 1, r);
			return(lft > 1 && rgh > 1 && (s[i] != '/' || rgh > 2)) ? 2 : 0;
		}
	}
	if(s[l] == '(')
		return(get(l + 1, r - 1) ? 3 : 0);
	string u(s.begin() + l, s.begin() + r + 1);
	return(ma.count(u) ? ma[u] : 3);
}

int solve(bool ans = 0) {
	string macro = "#";
	if(!ans) {
		scanf(" # %*s %s", buff);
		macro = string(buff);
	}
	scanf(" %[^\n]s", buff);
	s = string(buff);
	int cur = 0;
	for(int i = 0; i < (int) s.length(); i++) {
		if(s[i] != ' ') s[cur++] = s[i];
	}
	while((int)s.length() > cur) s.ppb();
	ma[macro] = get(0, cur - 1);
	return(ma[macro]);
}

int solution() {

	int n;
	scanf("%d\n", &n);
	for(; n--; ) {
		solve();
	}
	if(solve(1)) {
		printf("OK\n");
	} else {
		printf("Suspicious\n");
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim