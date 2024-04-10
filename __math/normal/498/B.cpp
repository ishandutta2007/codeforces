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

typedef long long ll;
typedef unsigned long long ull;
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

double dp[5001][5001];
const double EPS = 1e-14;

int main() {
	int n, T; cin >> n >> T;
	dp[0][0] = 1.0;
	FOR(i, n) {
		double p; cin >> p; p /= 100;
		int t; cin >> t;
		double lp = p;
		double lp2 = 1.0;
		FOR(_, t - 1) {
			lp2 -= lp;
			lp *= (1 - p);
		}
		double cur = 0;
		FOR(j, T) {
			cur = cur * (1 - p) + dp[i][j] * p;
			if (j + 1 >= t) {
				cur -= lp * dp[i][j + 1 - t];
				dp[i + 1][j + 1] += lp2 * dp[i][j + 1 - t];
			}
			dp[i + 1][j + 1] += cur;
		}
	}

	double ans = 0;
	double prev_sum = 0;
	for (int i = n; i > 0; i--) {
		double sum = 0;
		FOR(j, T + 1) sum += dp[i][j];
		ans += (sum - prev_sum) * i;
		prev_sum = sum;
	}
	printf("%.10lf\n",ans);
}