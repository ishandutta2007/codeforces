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
const int maxn = 1200;

int pl[maxn];
int pr[maxn];
int po[maxn];

int dp[5][maxn][110];

int solution() {

	int n, p, q;
	scanf("%d%d%d", &n, &p, &q);

	int ls;
	scanf("%d", &ls);
	for(int i = 0; i < ls; i++) {
		int x;
		scanf("%d", &x);
		x--;
		pl[x]++;
	}

	int rs;
	scanf("%d", &rs);
	for(int i = 0; i < rs; i++) {
		int x;
		scanf("%d", &x);
		x--;
		pr[x]++;
	}

	for(int i = 0; i < n; i++) {
		po[i] = pl[i] & pr[i];
	}

	for(int i = 1; i < n + 100; i++) {
		pl[i] += pl[i - 1];
		pr[i] += pr[i - 1];
		po[i] += po[i - 1];
	}


	for(int ii = 0; ii < p; ii++) {
		int i = ii % 5;

		for(int j = 0; j < n; j++) {
			for(int k = -q; k <= q; k++) {
				if(k < 0) {
					dp[i][j + 1][51 + k + 1] = max(dp[i][j + 1][51 + k + 1], dp[i][j][51 + k]);
					dp[(i + 1) % 5][min(j + abs(k), n)][51 + q + k] = max(dp[(i + 1) % 5][min(j + abs(k), n)][51 + q + k], dp[i][j][51 + k] + (pr[j + q - 1] - (j ? pr[j - 1] : 0)) - (po[j + abs(k) - 1] - (j ? po[j - 1] : 0)));

				} else if(k > 0) {
					dp[i][j + 1][51 + k - 1] = max(dp[i][j + 1][51 + k - 1], dp[i][j][51 + k]);

					dp[(i + 1) % 5][min(j + abs(k), n)][51 + k - q] = max(dp[(i + 1) % 5][min(j + abs(k), n)][51 + k - q], dp[i][j][51 + k] + (pl[j + q - 1] - (j ? pl[j - 1] : 0)) - (po[j + abs(k) - 1] - (j ? po[j - 1] : 0)));

				} else {
					dp[i][j + 1][51 + k] = max(dp[i][j + 1][51 + k], dp[i][j][51 + k]);
					dp[(i + 1) % 5][j][51 + k] = max(dp[(i + 1) % 5][j][51 + k], dp[i][j][51 + k]);
					dp[(i + 1) % 5][j + 1][51 + k - q + 1] = max(dp[(i + 1) % 5][j + 1][51 + k - q + 1], dp[i][j][51 + k] + (pl[j + q - 1] - (j ? pl[j - 1] : 0)));
					dp[(i + 1) % 5][j + 1][51 + k + q - 1] = max(dp[(i + 1) % 5][j + 1][51 + k + q - 1], dp[i][j][51 + k] + (pr[j + q - 1] - (j ? pr[j - 1] : 0)));
					dp[(i + 2) % 5][min(j + q, n)][51 + k] = max(dp[(i + 2) % 5][min(j + q, n)][51 + k], dp[i][j][51 + k] + (pl[j + q - 1] - (j ? pl[j - 1] : 0)) + (pr[j + q - 1] - (j ? pr[j - 1] : 0)) - (po[j + q - 1] - (j ? po[j - 1] : 0)));
				}
			}
		}

		i = (ii + 4) % 5;
		for(int j = 0; j < n; j++) {
			for(int k = -q; k <= q; k++) {
				dp[i][j][51 + k] = 0;
			}
		}
	}


	p %= 5;
	int ans = 0;
	for(int j = 0; j <= n; j++) {
		for(int i = -q; i <= q; i++) {
			ans = max(ans, dp[p][j][51 + i]);
		}
	}
	printf("%d", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim