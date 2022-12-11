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

int a[maxn], nx[8][maxn], id[maxn];
vector<int> pos[8];

bool dp[1010][256];
int le[1010][256];


int solution() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		id[i] = pos[a[i]].size();
		pos[a[i]].pb(i);
	}

	nx[0][n] = nx[1][n] = -1;
	nx[2][n] = nx[3][n] = -1;
	nx[4][n] = nx[5][n] = -1;
	nx[6][n] = nx[7][n] = -1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			nx[j][i] = nx[j][i + 1];
		}
		nx[a[i]][i] = id[i];
	}

	int ans = -1;
	for (int l = 1; l <= 1000; l++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 256; j++) {
				dp[i][j] = 0;
				le[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 256; j++) {
				if (!dp[i][j])
					continue;
				for (int k = 0; k < 8; k++) {
					if ((j & (1 << k)))
						continue;
					int p = nx[k][i];
					if (l - 1 == 0) {
						if (dp[i][j | (1 << k)]) {
							le[i][j | (1 << k)] = max(le[i][j | (1 << k)], le[i][j]);
						} else {
							dp[i][j | (1 << k)] = 1;
							le[i][j | (1 << k)] = le[i][j];
						}
					} else if (p >= 0) {
						if (p + l - 2 < (int) pos[k].size()) {
							int ps = pos[k][p + l - 2] + 1;
							if (dp[ps][j | (1 << k)]) {
								le[ps][j | (1 << k)] = max(le[ps][j | (1 << k)], le[i][j] + l - 1);
							} else {
								dp[ps][j | (1 << k)] = 1;
								le[ps][j | (1 << k)] = le[i][j] + l - 1;
							}
						}
					}
					if (p >= 0)
						if (p + l - 1 < (int) pos[k].size()) {
							int ps = pos[k][p + l - 1] + 1;
							if (dp[ps][j | (1 << k)]) {
								le[ps][j | (1 << k)] = max(le[ps][j | (1 << k)], le[i][j] + l);
							} else {
								dp[ps][j | (1 << k)] = 1;
								le[ps][j | (1 << k)] = le[i][j] + l;
							}
						}
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			if (dp[i][255]) {
//				cout << i << " " << le[i][255] << endl;
				ans = max(ans, le[i][255]);
			}
		}
	}
	printf("%d", ans);

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim