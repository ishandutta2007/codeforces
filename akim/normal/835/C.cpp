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

int fv[12][110][110];

void add(int (&fv)[110][110], int x, int y, int z) {
	for(int u = x; u < 110; u |= u + 1) {
		for(int v = y; v < 110; v |= v + 1) {
			fv[u][v] += z;
		}
	}
}

int sum(int (&fv)[110][110], int x, int y) {
	int ret = 0;
	for(int u = x; u >= 0; u &= u + 1, u-- 	) {
		for(int v = y; v >= 0; v &= v + 1, v--) {
			ret += fv[u][v];
		}
	}
	return(ret);
}

int sum(int (&fv)[110][110], int x1, int y1, int x2, int y2) {
	// cout << sum(fv, x2, y2) << " " <<  sum(fv, x2, y1) << " " << sum(fv, x1, y2) << " " << sum(fv, x1, y1) << endl;
	return(sum(fv, x2, y2) - sum(fv, x2, y1) - sum(fv, x1, y2) + sum(fv, x1, y1));
}

int solution() {

	int n, q, c;
	scanf("%d%d%d", &n, &q, &c);
	c++;
	for(int i = 0; i < n; i++) {
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		for(int j = 0; j < c; j++) {
			// cout << j << " " << x << " " << y << " " << s << endl;
			add(fv[j], x, y, s);
			s = (s + 1) % c;
		}
	}
	for(int i = 0; i < q; i++) {
		int t, x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		x1--, y1--;
		printf("%d\n", sum(fv[t % c], x1, y1, x2, y2));
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim