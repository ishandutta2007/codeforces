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

char c[1010][1010];

int solution() {

	int n, m, x0, y0, x1, y1;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int j = 0; j < m; j++) {
			scanf("%c", &c[i][j]);
			if(c[i][j] == 'S') {
				x0 = i, y0 = j;
				c[i][j] = '.';
			}
			if(c[i][j] == 'T') {
				x1 = i, y1 = j;
				c[i][j] = '.';
			}
		}
	}

	for(int i = 0; i < n; i++) {
		bool ok = 1;
		for(int k = x0; k < i; k++) {
			ok &= (c[k][y0] == '.');
		}
		for(int k = x0; k > i; k--) {
			ok &= (c[k][y0] == '.');
		}
		for(int k = x1; k < i; k++) {
			ok &= (c[k][y1] == '.');
		}
		for(int k = x1; k > i; k--) {
			ok &= (c[k][y1] == '.');
		}
		for(int j = y0; j <= y1; j++) {
			ok &= (c[i][j] == '.');
		}
		for(int j = y1; j <= y0; j++) {
			ok &= (c[i][j] == '.');
		}
		if(ok) {
			printf("YES\n");
			return(0);
		}
	}
	for(int j = 0; j < m; j++) {
		bool ok = 1;
		for(int k = y0; k < j; k++) {
			ok &= (c[x0][k] == '.');
		}
		for(int k = y0; k > j; k--) {
			ok &= (c[x0][k] == '.');
		}
		for(int k = y1; k < j; k++) {
			ok &= (c[x1][k] == '.');
		}
		for(int k = y1; k > j; k--) {
			ok &= (c[x1][k] == '.');
		}
		for(int i = x0; i <= x1; i++) {
			ok &= (c[i][j] == '.');
		}
		for(int i = x1; i <= x0; i++) {
			ok &= (c[i][j] == '.');
		}
		if(ok) {
			printf("YES\n");
			return(0);
		}
	}

	printf("NO\n");


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim