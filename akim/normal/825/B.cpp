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


char c[11][11];
int solution() {

	int n = 10;
	for(int i = 0; i < n; i++) {
		if(i) scanf("\n");
		for(int j = 0; j < n; j++) {
			scanf("%c", &c[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i >= 4) {
				int cnt1 = (c[i][j] == 'X') + (c[i - 1][j] == 'X') + (c[i - 2][j] == 'X') + (c[i - 3][j] == 'X') + (c[i - 4][j] == 'X');
				int cnt2 = (c[i][j] == '.') + (c[i - 1][j] == '.') + (c[i - 2][j] == '.') + (c[i - 3][j] == '.') + (c[i - 4][j] == '.');
				if(cnt1 == 4 && cnt2 == 1) {
					printf("YES");
					return(0);
				}
			}
			if(j >= 4) {
				int cnt1 = (c[i][j] == 'X') + (c[i][j - 1] == 'X') + (c[i][j - 2] == 'X') + (c[i][j - 3] == 'X') + (c[i][j - 4] == 'X');
				int cnt2 = (c[i][j] == '.') + (c[i][j - 1] == '.') + (c[i][j - 2] == '.') + (c[i][j - 3] == '.') + (c[i][j - 4] == '.');
				if(cnt1 == 4 && cnt2 == 1) {
					printf("YES");
					return(0);
				}
			}
			if(i >= 4 && j >= 4) {
				int cnt1 = (c[i][j] == 'X') + (c[i - 1][j - 1] == 'X') + (c[i - 2][j - 2] == 'X') + (c[i - 3][j - 3] == 'X')
							+ (c[i - 4][j - 4] == 'X');
				int cnt2 = (c[i][j] == '.') + (c[i - 1][j - 1] == '.') + (c[i - 2][j - 2] == '.') + (c[i - 3][j - 3] == '.')
							+ (c[i - 4][j - 4] == '.');
				if(cnt1 == 4 && cnt2 == 1) {
					printf("YES");
					return(0);
				}
				cnt1 = (c[i][j - 4] == 'X') + (c[i - 1][j - 3] == 'X') + (c[i - 2][j - 2] == 'X') + (c[i - 3][j - 1] == 'X')
							+ (c[i - 4][j] == 'X');
				cnt2 = (c[i][j - 4] == '.') + (c[i - 1][j - 3] == '.') + (c[i - 2][j - 2] == '.') + (c[i - 3][j - 1] == '.')
							+ (c[i - 4][j] == '.');
				if(cnt1 == 4 && cnt2 == 1) {
					printf("YES");
					return(0);
				}
			}
		}
	}
	printf("NO");

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim