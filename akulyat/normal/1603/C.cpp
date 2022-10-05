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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n;
vector<int> v;

inline pii use(int v, int val) {
	int r = v % val;
	int k = (v + val - 1) / val;
	return {v / k, k - 1};
}

ll work(int pl) {
	ll val = v[pl];
	ll lans = 0;
	ll sum = 0;
	for (int i = pl - 1; i >= 0; i--) {
		pll res = use(v[i], val);
		// if (viv)
		// 	cout << "See: " << res.F << ' ' << res.S << endl;
		val = res.F;
		sum += res.S;
		lans += sum;
	}
	if (viv)
		cout << lans << ' ';
	return lans;
}

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

const int S = 430;
const int C = (100 * kk) / S + 10;
zet mp[C][100 * kk + 10];
bool used[C][100 * kk + 10];

int nice(int pl) {
	return (pl + 1) % S == 0;
}

zet work(int pl, int val, bool force = false) {
	if (pl == -1)
		return 0;
	pii res = use(v[pl], val);

	if (nice(pl) && used[pl / S][res.F])
		return zet(res.S) * zet(pl + 1) + mp[pl / S][res.F];


	zet lans = work(pl - 1, res.F);
	if (nice(pl)) {
		mp[pl / S][res.F] = lans;
		used[pl / S][res.F] = true;
	}
	return zet(res.S) * zet(pl + 1) + lans;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += nice(i);

	for (int i = 0; i < cnt; i++) {
		for (int val = 1; val <= 100 * kk; val++)
			used[i][val] = false;
	}

	zet ans = 0;
	for (int i = 0; i < n; i++) {
		// if (nice(i)) {
		// 	for (int val = 1; val <= 100 * kk; val++)
		// 		work(i, val, true);
		// }
		ans += work(i, v[i]);
	}
	cout << ans.val << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}