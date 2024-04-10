#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, q;
bool viv = false;

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

inline void gmod(ll &val) {
	val %= mod;
	if (val < 0)
		val += mod;
}

ll bpow(ll val, ll mod, ll st = -1) {
	if (st == -1)
		st = mod - 2;
	if (st == 0)
		return 1;
	ll res = bpow(val, mod, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

vector<ll> f, fi;
void prepare() {
	f.resize(1, 1);
	for (int i = 1; i < 3 * ml + 10; i++)
		f.push_back(f.back() * i), gmod(f.back());
	for (auto val : f)
		fi.push_back(bpow(val, mod));
}

ll C(int n, int k) {
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	ll val = f[n];

	val *= fi[k];
	gmod(val);

	val *= fi[n - k];
	gmod(val);

	if (viv)
		cout << "\tC(" << n << ", " << k << ") = " << val << endl;
	return val;
}

ll dp[3 * ml + 10][3];
void solve() {
	// prepare();
	cin >> n >> q;

	dp[3 * n][0] = 1;
	dp[3 * n][1] = 0;
	dp[3 * n][2] = 0;

	zet val = 1;
	for (int i = 3 * n - 1; i >= 0; i--) {
		// if (viv) {
		// 	cout << "was: ";
		// 	cout << dp[i + 1][0] << ' ';
		// 	cout << dp[i + 1][1] << ' ';
		// 	cout << dp[i + 1][2] << ' ';
		// 	cout << endl;
		// }
		val *= (i + 2);
		// gmod(val);
		// val *= bpow(3 * n - i, mod);
		zet z = 3 * n - i;
		val *= inv(z);
		// val *= 3;
		// cout << val << endl;
		// gmod(val);

		dp[i][2] = dp[i + 1][0] - dp[i + 1][2];
		if (dp[i][2] < 0)
			dp[i][2] += mod;
		dp[i][1] = dp[i + 1][2] - dp[i + 1][1];
		if (dp[i][1] < 0)
			dp[i][1] += mod;

		// val = C(3 * n + 1, i + 1);
		ll value = val.val;
		dp[i][0] = value + dp[i + 1][1];
		if (dp[i][0] >= mod)
			dp[i][0] -= mod;
		dp[i][0] -= dp[i + 1][0];
		if (dp[i][0] < 0)
			dp[i][0] += mod;
	}

	while (q--) {
		ll v;
		cin >> v;
		cout << dp[v][0] << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	// cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;


	return 0;
}