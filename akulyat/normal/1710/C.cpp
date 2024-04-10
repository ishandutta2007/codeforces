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
string s;

string mask_to_str(int mask) {
	string res = "000";
	for (int i = 0; i < 3; i++)	{
		res[i] = (mask >> i) & 1;
	}
	reverse(res.begin(), res.end());
	return res;
}

int str_to_mask(string str) {
	int res = 0;
	for (int i = 0; i < 3; i++)	{
		res <<= 1;
		res |= (str[i] == '1');
	}
	return res;
}

void solve() {
	vector<bool> nice(8, true);
	nice[str_to_mask("001")] = false;
	nice[str_to_mask("110")] = false;

	cin >> s;
	n = s.size();
	zet s_mod = 0;
	zet p2 = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1')
			s_mod += p2;
		p2 *= 2;
	}




	vector<zet> dp(8, 0);
	dp[str_to_mask("111")] = 1;

	for (int i = 0; i < n; i++) {
		vector<zet> new_dp(8);
		if (s[i] == '0') {
			for (int mask = 0; mask < 8; mask++)
				if (nice[mask]) {
					for (int same = 0; same < 8; same++) {
						int check_ban = same & mask;
						if (check_ban) {
							// exceed n
						} else {
							int new_same = same & (mask ^ 7);
							new_dp[new_same] += dp[same];
						}					
					}
				}
		} else {
			for (int mask = 0; mask < 8; mask++)
				if (nice[mask]) {
					for (int same = 0; same < 8; same++) {
						int new_same = same & mask;
						new_dp[new_same] += dp[same];
					}
				}			
		}	

		dp = new_dp;
		// cout << "dp = ";
		// for (auto i : dp)
		// 	cout << i << ' ';
		// cout << endl;
	}

	zet ans = 0;
	for (auto i : dp)
		ans += i;
	ans *= 3;
	// cout << "dp ans = " << ans << endl;
	ans -= (s_mod + 1) * 3;
	// cout << "upd1 ans = " << ans << endl;
	ans -= (s_mod + 1) * 2;
	// cout << "upd2 ans = " << ans << endl;

	zet s_3 = 1;
	s_3 *= (s_mod + 1);
	s_3 *= (s_mod + 1);
	s_3 *= (s_mod + 1);
	// cout << "\ts_3 = " << s_3 << " because " << s_mod << endl;

	ans = s_3 - ans;
	// cout << "final ans = " << ans << endl;

	zet add = s_mod;
	add *= s_mod;
	add -= 1;
	add *= 3;
	if (n != 1)
		ans += add;


	cout << (1000 + ans).val - 1000 << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}