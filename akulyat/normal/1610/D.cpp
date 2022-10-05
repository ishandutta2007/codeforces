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


bool viv = false;
int n;
vector<int> v;

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

zet work(vector<int> vec) {
	if (viv) {
		cout << "work: ";
		for (auto i : vec)
			cout << i << ' ';
		cout << endl;
	}
	if (vec.empty())
		return 0;

	for (auto &i : vec)
		i /= 2;

	bool need = false;
	for (auto i : vec)
		if (i & 1)
			need = true;

	zet res = 1;
	for (int i = 1; i < vec.size(); i++)
		res *= 2;
	if (!need)
		res = 0;


	vector<int> vec2;
	for (auto &i : vec) {
		if (!(i & 1))
			vec2.push_back(i);
	}
	// cout << "see: " << res << endl;
	res += work(vec2);
	return res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	zet ans = 1;
	for (int i = 0; i < n; i++)
		ans *= 2;
	ans -= 1;

	zet ans1 = 1;
	vector<int> vec;
	for (int i = 0; i < n; i++)
		if ((v[i] & 1) == 0) {
			vec.push_back(v[i]);
			ans1 *= 2;
		}
	ans1 -= 1;

	// ans -= ans1;

	ans -= work(vec);

	cout << ans.val << '\n';
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