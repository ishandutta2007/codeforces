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

template<class T> ll mod_pow(T a, T n, T mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}

int main() {
	int t; cin >> t;
	FOR(i, t) {
		ll n, k, d[2];
		cin >> n >> k >> d[0] >> d[1];
		ll m = n - k;
		bool ok = false;
		FOR(i, 2) FOR(j, 2) {
			ll dx[] = { i == 0 ? d[0] : -d[0], j == 0 ? d[1] : -d[1] };
			ll x[3] = {};
			x[1] = x[0] + (i == 0 ? d[0] : -d[0]);
			x[2] = x[1] + (j == 0 ? d[1] : -d[1]);
			sort(x, x + 3);
			x[2] -= x[0];
			x[1] -= x[0];
			if (x[1] + x[2] > k) continue;
			if ((x[1] + x[2] - k) % 3 != 0) continue;
			ll diff = x[2] * 2 - x[1];
			if (diff > m) continue;
			if ((diff - m) % 3 == 0) ok = true;
		}

		puts(ok ? "yes" : "no");
	}
}