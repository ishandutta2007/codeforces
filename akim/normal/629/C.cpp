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
const int maxn = 100100;

ll dp[2050][2050];

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

	dp[0][0] = 1;
	for(int i = 0; i < 2020; i++) {
		for(int j = 0; j < 2020; j++) {
			dp[i + 1][j + 1] += dp[i][j];
			dp[i + 1][j + 1] %= mod;
			if(j) {
				dp[i + 1][j - 1] += dp[i][j];
				dp[i + 1][j - 1] %= mod;
			}
		}
	}

	int n, m;
	scanf("%d%d\n", &n, &m);
	string s;
	getline(cin, s);
	int lb = 0, bal = 0;
	for(int i = 0; i < m; i++) {
		bal += (s[i] == '(' ? 1 : -1);
		lb = min(lb, bal);
	}
	ll ans = 0;
	for(int i = 0; i < 2020; i++) {
		for(int j = 0; j < 2020; j++) {
			if(n - m - i >= 0 && j >= -lb && bal + j >= 0 && n - m - i < 2020 && j < 2020 && bal + j < 2020) {
				ans += dp[i][j] * 1ll * dp[n - m - i][bal + j];
				ans %= mod;
			}
		}
	}
	printf("%lld", ans);

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