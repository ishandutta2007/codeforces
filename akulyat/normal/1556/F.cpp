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

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

ll n, S;
vector<ll> v;
vector<zet> ans;
bool viv = false;

zet ii[20][20];

int cnt(int val) {
	if (!val)
		return 0;
	return 1 + cnt(val & (val - 1));
}

vector<int> get(int mask) {
	int now = mask;
	vector<int> res;
	while (now) {
		now = mask & (now - 1);
		res.push_back(now);
	}
	res.push_back(mask);
	// cout << "get(" << mask << ") = ";
	// for (auto i :res)
	// 	cout << i << ' ';
	// cout << endl;
	return res;
}


// map<int, zet> pr;
// map<int, zet> ipr;
vector<zet> pr;
vector<zet> ipr;


int prr(int mask, int rest) {
	int res = 0;
	for (int i = 0; i < 14; i++)
		res *= 3, res += (((mask >> i) & 1) << 1) | ((rest >> i) & 1);
	return res;
	return (mask << 15) | rest;
	// return {mask, rest};
}

void prepare(int mask, int rest) {
	vector<int> a, b;
	for (int i = 0; i < n; i++)
		if ((mask >> i) & 1)
			a.push_back(i);
	for (int i = 0; i < n; i++)
		if ((rest >> i) & 1)
			b.push_back(i);
	zet prob = 1;
	for (auto p1 : a)
		for (auto p2 : b) {
			prob *= zet(v[p1]);
			prob *= ii[p1][p2];
		}

	// cout << "ans " << mask << ' ' << rest << " is " << prob << endl;

	auto pa = prr(mask, rest);
	pr[pa] = prob;
	ipr[pa] = inv(prob);
}

void prepare(int mask) {
	int rest = S - 1 - mask;
	vector<int> all = get(rest);
	for (auto r : all)
		prepare(mask, r);
}

void prepare() {
	for (int i = 0; i < S; i++) {
		prepare(i);		
	}
}

zet solver(int mask) {
	if (!mask) {
		return 0;
	}

	int rest = S - 1 - mask;
	// vector<int> all = get(rest);

	auto m = get(mask);
	m.pop_back();
	// cout << "START " << prob << endl;
	zet base = pr[(prr(mask, rest))];
	zet prob = 1;
	for (auto mm: m) {
		// prob -= ans[mm] * ipr[prr(mm, rest)];
		prob -= ans[mm] * inv(pr[prr(mm, rest)]);
		// cout << "NOW: " << prob << endl;
	}
	prob *= base;
	return prob;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	S = (1 << n);

	int p = 1;
	for (int i = 0; i < 14; i++)
		p *= 3;
	pr.resize(p);
	ipr.resize(p);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			zet sum = zet(v[i] + v[j]);
			ii[i][j] = inv(sum);
		}
	}
	prepare();

	vector<int> m, sz;
	for (int i = 0; i < S; i++) {
		m.push_back(i);
		sz.push_back(cnt(i));
	}
	sort(m.begin(), m.end(), [&](int a, int b) {
		return sz[a] < sz[b];
	});

	ans.resize(S);
	for (auto i : m)
		ans[i] = solver(i);

	zet res = 0;
	for (auto i : m) {
		if (viv)
			cout << i << ' ' << sz[i] << ' ' << ans[i] << endl;
		res += sz[i] * ans[i];
	}
	cout << res << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

    // #ifdef DEBUG
        // cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    // #endif
}