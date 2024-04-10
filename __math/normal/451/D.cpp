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

int strID2memoID[ten(5)];
ll memo[ten(5) + 10][2];
ll sum[2][ten(5)][2];

int main() {
	string s; cin >> s;
	vector<int> v;
	char last = 'c';
	FOR(i, sz(s)) {
		if (last != s[i]) v.push_back(0);
		v[sz(v) - 1]++;
		last = s[i];
		strID2memoID[i] = sz(v) - 1;
	}
	vector<int> vsum = v;
	FOR(i, sz(v) - 1) vsum[i + 1] += vsum[i];
	{
		ll sum = 0;
		FOR(i, sz(v)) {
			memo[i][0] = v[i] / 2;
			memo[i][1] = v[i] - v[i] / 2;
			if (sum % 2 == 1) swap(memo[i][0], memo[i][1]);
			sum += v[i];
		}
	}

	FOR(i, 2) {
		for (int j = i; j < sz(v); j += 2) {
			int idx = j / 2;
			sum[i][idx + 1][0] = sum[i][idx][0] + memo[j][0];
			sum[i][idx + 1][1] = sum[i][idx][1] + memo[j][1];
		}
	}

	ll ans_even = 0, ans_odd = 0;
	FOR(i, sz(s)) {
		int memo_id = strID2memoID[i];
		int rem_length = vsum[memo_id] - i;
		ans_even += rem_length / 2;
		ans_odd += rem_length - rem_length / 2;
		int j = memo_id % 2;
		bool flip = (i % 2 == 1);
		int mx = (memo_id % 2 == 1) ? sz(v) / 2 : (1 + sz(v)) / 2;
		ll even = sum[j][mx][0] - sum[j][memo_id / 2 + 1][0];
		ll odd = sum[j][mx][1] - sum[j][memo_id / 2 + 1][1];
		if (flip) swap(even, odd);

		ans_even += even;
		ans_odd += odd;
	}

	cout << ans_even << " " << ans_odd << endl;

}