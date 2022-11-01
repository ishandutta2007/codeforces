#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


ll dp[2001][2001];

int main() {
	int n, k;
	cin >> n >> k;

	dp[0][1] = 1;
	FOR(i, k) {
		ll *d = dp[i + 1], *p = dp[i];
		for (int j = 1; j <= n; j++) {
			ll add = p[j];
			for (int k = j; k <= n; k += j) {
				d[k] += add;
			}
		}
		for (int j = 1; j <= n; j++) d[j] %= MOD;
	}

	ll ans = 0;
	FOR(i, n + 1) ans += dp[k][i];
	cout << ans % MOD << endl;

	return 0;
}