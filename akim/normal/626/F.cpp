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
const int maxn = 220;

int a[maxn], dp[maxn][maxn][1010];

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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(&a[0], &a[n]);
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = 0; k <= m; k++) {
				if(k + (a[i] - (i ? a[i - 1] : 0)) * j > m) continue;
				if(j + 1 <= n) {
					int &pdp = dp[i + 1][j + 1][k + ((i ? a[i] - a[i - 1] : 0)) * j];
					pdp = pdp + dp[i][j][k];
					pdp-= pdp >= mod ? mod : 0;
				}
				if(j - 1 >= 0) {
					int &pdp = dp[i + 1][j - 1][k + ((i ? a[i] - a[i - 1] : 0)) * j];
					pdp = (pdp + dp[i][j][k] * 1ll * j) % mod;
				}
				{
					int &pdp = dp[i + 1][j][k + ((i ? a[i] - a[i - 1] : 0)) * j];
					pdp = (pdp + dp[i][j][k] * 1ll * (j + 1)) % mod;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i <= m; i++) {
		ans = ans + dp[n][0][i];
		ans -= ans >= mod ? mod : 0;
	}
	printf("%lld\n", ans);

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