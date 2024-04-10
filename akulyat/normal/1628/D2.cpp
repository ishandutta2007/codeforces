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
int n, m, k;
vector<int> v;


vector<zet> f, fi;

void prepare() {
	f.push_back(1);
	for (int i = 1; i <= ml + kk; i++)
		f.push_back(f.back() * i);	
	for (auto val : f)
		fi.push_back(zet(1) / val);	
}

zet C(int n, int k) {
	if (n == k)
		return 1;
	if (k < 0 || n < k)
		return 0;
	zet res = f[n];
	res *= fi[k];
	res *= fi[n - k];
	return res;
}

void solve() {
	cin >> n >> m >> k;
	zet inv_2 = 1;
	inv_2 /= 2;

	int dist = n - m;
	dist -= 1;

	vector<zet> ans(1, 0);

	zet pw = 1;
	for (int i = 1; i <= n; i++) {
		ans.push_back(i * pw);
		pw *= 2;
	}

	zet res = 0;
	for (int i = 0; i <= (m); i++) {
		zet lres = ans[i];
		lres *= C((m - i) + dist, dist);
		res += lres;
		if (viv) 
			cout << "add " << lres << "(" << ans[i] << " * " << C((n - i) + dist, dist) << ")" << '\n';
	}
	res *= k;
	if (viv) {
		cout << "pre " << res << endl;
	}
	for (int i = 1; i < n; i++) 
		res *= inv_2;
	cout << res << '\n';
	if (viv) {
		cout << endl;
		cout << endl;
	}
}

int main() {
	prepare();
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