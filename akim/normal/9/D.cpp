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

ll dp[40][40];
bool was[40][40];

ll rec(int n, int m) {
	if(was[n][m]) return(dp[n][m]);
	if(m > n || m < 0) return(0);
	if(m == 0 && n == 0) {
		return(1);
	}
	if(m == 1 && n == 1) {
		return(1);
	}
	was[n][m] = 1;
	dp[n][m] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dp[n][m] += rec(i, m - 1) * rec(n - i - 1, j);
		}
		for(int j = 0; j < m; j++) {
			dp[n][m] += rec(i, j) * rec(n - i - 1, m - 1);
		}
		dp[n][m] -= rec(i, m - 1) * rec(n - i - 1, m - 1);
	}
//	cout << n << " " << m << " " << dp[n][m] << endl;
	return(dp[n][m]);
}

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
	cin >> n >> m;
	ll ans = 0;
	while(m <= 35) {
		ans += rec(n, m++);
	}

	cout << ans;


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