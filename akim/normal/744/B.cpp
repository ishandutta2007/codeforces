#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//																														tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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
	srand(__rdtsc());
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

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
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

int q[11][2][1010];
int cc[11][2];
int ans[1010];
int w = 10;

int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < 2; j++) {
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (((k % (1 << i)) ^ (j << (i - 1))) < (1 << (i - 1))) {
					cnt++;
				}
			}
			cc[i][j] = cnt;
			if (cnt) {
				printf("%d\n", cnt);
				for (int k = 0; k < n; k++) {
					if (((k % (1 << i)) ^ (j << (i - 1))) < (1 << (i - 1))) {
						printf("%d ", k + 1);
					}
				}
				printf("\n");
				fflush(stdout);

				for (int k = 0; k < n; k++) {
					scanf("%d", &q[i][j][k]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ans[i] = mod;
	}

	printf("-1\n");
	for (int k = 0; k < n; k++) {
		for (int i = 1; i <= w; i++) {
			for (int j = 0; j < 2; j++) {
				if (cc[i][j])
					if (!(((k % (1 << i)) ^ (j << (i - 1))) < (1 << (i - 1)))) {
						ans[k] = min(ans[k], q[i][j][k]);
					}
			}
		}
		printf("%d ", ans[k]);
	}
	fflush(stdout);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim