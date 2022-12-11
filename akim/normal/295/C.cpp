#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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
/*tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;*/
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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

struct state {
	int c1, c2, b;
	state(int c1 = 0, int c2 = 0, int b = 0) : c1(c1), c2(c2), b(b) {

	}
};

bool pm[200][200][2];
int dp[200][200][2];
int cnt[200][200][2];
int cnk[200][200];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	cnk[0][0] = 1;
	for(int i = 1; i < 200; i++) {
		for(int j = 0; j < 200; j++) {
			cnk[i][j] = (cnk[i - 1][j] + (j ? cnk[i - 1][j - 1] : 0)) % mod;
		}
	}

	int n, k;
	scanf("%d%d", &n, &k);
	int fc1 = 0, fc2 = 0;
	for(int i = 0; i < n; i++) {
		int u;
		scanf("%d", &u);
		fc1 += u == 50;
		fc2 += u == 100;
	}

	vector<state> vc;
	pm[fc1][fc2][0] = 1;
	dp[fc1][fc2][0] = 0;
	cnt[fc1][fc2][0] = 1;
	vc.pb(state(fc1, fc2, 0));
	for(int i = 0; i < (int)vc.size(); i++) {
		int c1 = vc[i].c1, c2 = vc[i].c2, b = vc[i].b;
		if(b == 0) {
			int cc1 = c1, cc2 = c2;
			for(int i = 0; i <= cc1; i++) {
				for(int j = 0; j <= cc2; j++) {
					if(i + j && 50 * i + 100 * j <= k) {
						if(!pm[c1 - i][c2 - j][1]) {
							pm[c1 - i][c2 - j][1] = 1;
							dp[c1 - i][c2 - j][1] = dp[c1][c2][b] + 1;
							cnt[c1 - i][c2 - j][1] = cnt[c1][c2][b] * 1ll * (cnk[cc1][i] * 1ll * cnk[cc2][j] % mod) % mod;
							vc.pb(state(c1 - i, c2 - j, 1));
						} else
						if(dp[c1 - i][c2 - j][1] == dp[c1][c2][b] + 1) {
							cnt[c1 - i][c2 - j][1] += cnt[c1][c2][b] * 1ll * (cnk[cc1][i] * 1ll * cnk[cc2][j] % mod) % mod;
							cnt[c1 - i][c2 - j][1] %= mod;
						}
					}
				}
			}
		} else {
			int cc1 = fc1 - c1, cc2 = fc2 - c2;
			for(int i = 0; i <= cc1; i++) {
				for(int j = 0; j <= cc2; j++) {
					if(i + j && 50 * i + 100 * j <= k) {
						if(!pm[c1 + i][c2 + j][0]) {
							pm[c1 + i][c2 + j][0] = 1;
							dp[c1 + i][c2 + j][0] = dp[c1][c2][b] + 1;
							cnt[c1 + i][c2 + j][0] = cnt[c1][c2][b] * 1ll * (cnk[cc1][i] * 1ll * cnk[cc2][j] % mod) % mod;
							vc.pb(state(c1 + i, c2 + j, 0));
						} else
						if(dp[c1 + i][c2 + j][0] == dp[c1][c2][b] + 1) {
							cnt[c1 + i][c2 + j][0] += cnt[c1][c2][b] * 1ll * (cnk[cc1][i] * 1ll * cnk[cc2][j] % mod) % mod;
							cnt[c1 + i][c2 + j][0] %= mod;
						}
					}
				}
			}
		}
	}

	if(!pm[0][0][1]) {
		printf("-1\n0\n");
	} else {
		printf("%d\n", dp[0][0][1]);
		printf("%d\n", cnt[0][0][1]);
	}


	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim