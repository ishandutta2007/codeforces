// #include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }

struct zet {
    int val;
    explicit operator int() const { return val; }
    zet(ll x = 0) { val = (x >= -mod && x < mod ? x : x % mod); if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
    friend bool operator<(zet const &a, zet const &b) { return a.val < b.val; }
};

bool viv = false;
int n;
vector<zet> dp, p2;
vector<zet> f, fi, f2;


zet C(int n, int k) {
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	zet res = f[n];
	res *= fi[k];
	res *= fi[n - k];
	return res;
}

const int N = 300 * kk + 100;
void prepare() {
	f.resize(N, 1);
	for (int i = 1; i < N; i++)
		f[i] = f[i - 1] * i;
	fi.resize(N, 1);
	fi.back() = zet(1) / f.back();
	for (int i = N - 2; i >= 0; i--)
		fi[i] = fi[i + 1] * (i + 1);

	f2.resize(N, 1);
	for (int i = 2; i < N; i++)
		f2[i] = f2[i - 2] * i;
	p2.resize(N, 1);
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2;


	dp.resize(N, 0);
	dp[0] = 1;
	for (int i = 1 ; i < dp.size(); i++) {
		dp[i] = dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += (i - 1) * dp[i - 2];
	}

}

void solve() {
	cin >> n;
	zet ans = 0;
	for (int q = 0; q < n; q++) {
		if (4 * q > n) 
			break;

		int qpr = q * 2;
		zet vars = C(n - qpr, qpr);
		if (qpr - 1 >= 0)
			vars *= f2[qpr - 1];
		vars *= p2[q];
		ans += vars * dp[n - 4 * q];
		if (viv)
			cout << "\tAdded " << vars * dp[n - 4 * q] << '\n';
	}
	cout << ans << '\n';

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	prepare();
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}