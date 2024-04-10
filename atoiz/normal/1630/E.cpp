#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

const int MOD = 998244353;
struct intmod
{
	int val;

	intmod(int64_t _val = 0) { val = (int) (_val % MOD); val += (val < 0 ? MOD : 0); }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod& operator+=(intmod rhs) { val += rhs.val; val -= (val >= MOD ? MOD : 0); return *this; }
	intmod& operator-=(intmod rhs) { val -= rhs.val; val += (val < 0 ? MOD : 0); return *this; }
	intmod& operator*=(intmod rhs) { val = (int) ((int64_t) val * rhs.val % MOD); return *this; }

	friend intmod operator+(intmod lhs, intmod rhs) { return lhs += rhs; }
	friend intmod operator-(intmod lhs, intmod rhs) { return lhs -= rhs; }
	friend intmod operator*(intmod lhs, intmod rhs) { return lhs *= rhs; }

	friend intmod sqr(intmod a) { return a * a; }
	friend intmod bpow(intmod a, int p) { intmod ans(1); while (p) { if (p & 1) ans *= a; a = sqr(a); p >>= 1; } return ans; }
	friend intmod inv(intmod a) { return bpow(a, MOD - 2); }

	intmod& operator/=(intmod rhs) { return (*this) *= inv(rhs); }
	friend intmod operator/(intmod lhs, intmod rhs) { return lhs /= rhs; }

	friend istream& operator>>(istream &is, intmod &im) { return is >> im.val; }
	friend ostream& operator<<(ostream &os, intmod im) { return os << im.val; }
};

// start of code

const int MAXN = 1000006;
intmod fact[MAXN], ifact[MAXN];
intmod choose(int n, int k) {
	return (n >= k && k >= 0) ? fact[n] * ifact[n - k] * ifact[k] : 0;
}

int N, val[MAXN];
intmod multi_w[MAXN], multi_all[MAXN];
intmod dp[MAXN];
vector<int> vec, tmp;
intmod solve() {
	cin >> N;
	memset(val, 0, sizeof(val[0]) * (N + 1));
	FOR(_, 1, N) { int x; cin >> x; ++val[x]; }

	vec.clear();
	FOR(i, 1, N) if (val[i]) vec.push_back(val[i]);
	if (SZ(vec) == 1) return 1;

	intmod cnt_all = 0;
	int gcd_all = N;
	for (int x : vec) gcd_all = __gcd(gcd_all, x);
	
	intmod cnt_w = 0;
	FOR(c, 1, gcd_all) if (gcd_all % c == 0) {
		intmod cnt_c = fact[N / c];
		for (int x : vec) if (x / c > 1) {
		    intmod cnt_x = choose(N / c - 2, x / c - 2);
		    cnt_x *= fact[x / c] * fact[N / c - x / c];
		    cnt_c -= cnt_x;
		}
		for (int x : vec) cnt_c *= ifact[x / c];
		
		cnt_w += cnt_c * multi_w[c];
	}
	
	FOR(c, 1, gcd_all) if (gcd_all % c == 0) {
		intmod cnt_c = fact[N / c];
		for (int x : vec) cnt_c *= ifact[x / c];
		cnt_all += cnt_c * multi_w[c];
	}
	cnt_all /= N;

	return cnt_w / cnt_all;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 1; FOR(i, 1, MAXN - 1) fact[i] = fact[i - 1] * i;
	ifact[MAXN - 1] = inv(fact[MAXN - 1]); FORB(i, MAXN - 1, 1) ifact[i - 1] = ifact[i] * i;
	FOR(i, 1, MAXN - 1) {
		multi_w[i] += i;
		for (int j = i + i; j < MAXN; j += i) multi_w[j] -= multi_w[i];
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';

	return 0;
}