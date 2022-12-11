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

int n;
char c[maxn];
int r[maxn], b[maxn];
bool pm[1 << 16][300];
int dp[1 << 16][300];


int solution() {

	int rr = 0, bb = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("\n%c %d %d", &c[i], &r[i], &b[i]);
		rr += r[i], bb += b[i];
	}

	pm[0][0] = 1;
	dp[0][0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < 300; j++) {
			if (!pm[i][j])
				continue;
//			cout << i << " " << j << " " << dp[i][j] << endl;
			int cr = 0, cb = 0;
			for (int k = 0; k < n; k++) {
				if (!(i & (1 << k)))
					continue;
				cr += c[k] == 'R';
				cb += c[k] == 'B';
			}
			for (int k = 0; k < n; k++) {
				if ((i & (1 << k)))
					continue;
				int nr = min(r[k], cr);
				int nb = min(b[k], cb);
				if (pm[i | (1 << k)][j + nr]) {
					dp[i | (1 << k)][j + nr] = max(dp[i | (1 << k)][j + nr], dp[i][j] + nb);
				} else {
					pm[i | (1 << k)][j + nr] = 1;
					dp[i | (1 << k)][j + nr] = dp[i][j] + nb;
				}
			}
		}
	}

	int mm = (1 << n) - 1, ans = mod;
	for (int i = 0; i < 300; i++) {
		if (pm[mm][i]) {
			ans = min(ans, max(rr - i, bb - dp[mm][i]));
		}
	}

	printf("%d", ans + n);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim