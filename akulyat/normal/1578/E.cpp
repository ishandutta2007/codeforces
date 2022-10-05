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
// const long long ml = kk * kk;
const long long mod = kk * kk * kk + 7;
// const long long inf = ml * ml * ml + 7; 
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
int n, m;
vector<vector<pll>> e;
vector<ll> d;

zet ans;
vector<ll> cur;
vector<int> c0, c1;
ll orer, ml, tml;

void DFS(int v, ll c) {
	d[v] = c;
	for (int i = 0; i < 60; i++) {
		c0[i] += ((c >> i) & 1) == 0;
		c1[i] += ((c >> i) & 1) == 1;
	}

	for (auto [u, w] : e[v]) {
		if (d[u] == -1) {
			DFS(u, c ^ w);
		} else {
			cur.push_back(d[u] ^ d[v] ^ w);
		}
	}
}

ll get_B(ll val) {
	val |= val >> 1;
	val |= val >> 2;
	val |= val >> 4;
	val |= val >> 8;
	val |= val >> 16;
	val |= val >> 32;
	return val - (val >> 1);
}

void changer() {
	if (viv) {
		cout << "was: ";
		for (auto i : cur)
			cout << i << ' ';
		cout << endl;
	}
	vector<ll> res;
	for (int i = 0; i < cur.size(); i++) {
		ll add = cur[i];
		for (auto val : res)
			if (get_B(val) == get_B(add))
				add ^= val;
		if (add)
			res.push_back(add);
		sort(res.rbegin(), res.rend());
	}
	cur = res;
	orer = 0;
	tml = ml = 1;
	for (int i = 1; i < cur.size(); i++)
		ml <<= 1;
	for (int i = 0; i < cur.size(); i++)
		tml <<= 1;
	for (auto val : cur)
		orer |= val;
	if (viv) {
		cout << "now: ";
		for (auto i : cur)
			cout << i << ' ';
		cout << endl;
		cout << "orer = " << orer << endl;
		cout << "ml = " << ml << endl;
		cout << endl;
	}
}

zet pairs(ll k) {
	zet res = k;
	res *= k - 1;
	res /= 2;
	return res;
} 

void counter() {
	zet po = 1;
	ml %= mod;
	tml %= mod;
	zet pr = pairs(c0[0] + c1[0]);

	for (int b = 0; b < 60; b++) {
		if ((orer >> b) & 1) {
			ans += (po * ml) * pr;
		} else {
			if (viv)
				if (zet(c0[b]) * zet(c1[b]) != 0)
					cout << b << ": " << c0[b] << ' ' << c1[b] << endl;
			ans += po * (zet(c0[b]) * zet(c1[b])) * tml;
		}
		po *= 2;
	}
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	d.resize(n, -1);
	for (int i = 0; i < n; i++) {
		if (d[i] == -1) {
			cur.clear();
			c0.assign(60, 0);
			c1.assign(60, 0);
			DFS(i, 0);
			changer();			
			counter();
		}
	}
	cout << ans.val << endl;
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