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
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll p[ten(4)];

ll dp[5001][5001];

int main() {
	int n, m, k; cin >> n >> m >> k;
	FOR(i, n) cin >> p[i + 1];
	FOR(i, n) p[i + 1] += p[i];
	vector<ll> val;
	FOR(i, n - m + 1) {
		val.push_back(p[i + m] - p[i]);
	}

	ll last[5001] = {};
	const ll X = -ll(ten(9)) * ten(7);
	FOR(i, 5001) dp[0][i] = X;
	FOR(i, 5001) last[i] = X;
	last[0] = 0;
	dp[0][0] = 0;

	FOR(i, sz(val)) {
		int pv = i - m + 1;
		if (pv >= 0) {
			FOR(j, k) {
				last[j] = max(last[j], dp[pv][j]);
			}
		}
		FOR(j, k) {
			dp[i + 1][j + 1] = max(dp[i][j+1],last[j] + val[i]);
		}
	}

	cout << dp[sz(val)][k] << endl;

	return 0;
}