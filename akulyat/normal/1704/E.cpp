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


bool viv = false;
int n, m;
vector<int> v, ord;
vector<bool> used;
vector<vector<int>> e, re;

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

void DFS(int v) {
	used[v] = true;
	for (auto u : e[v]) {
		if (!used[u])
			DFS(u);
	}
	ord.push_back(v);
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	e.assign(n, {});
	re.assign(n, {});
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		re[b].push_back(a);
	}

	for (int ep = 0; ep < n; ep++) {
		vector<int> s;
		for (int j = 0; j < n; j++) {
			if (v[j] != 0)
				s.push_back(j);
		}
		if (s.empty()) {
			cout << ep << '\n';
			if (viv)
				cout << endl;
			return;
		}
		for (auto u : s) {
			for (auto t : e[u])
				v[t] += 1;
			v[u] -= 1;
		}
		if (viv) {
	 		for (auto i : v)
				cout << i << ' ';
			cout << endl;
		}
	}
	zet ans = n;
	// vector<bool> act(n);
	// for (int i = 0; i < n; i++)
	// 	act[i] = (v[i] > 0);


	vector<zet> vmod(n);
	for (int i = 0; i < n; i++)
		vmod[i] = v[i];

	// for (int ep = 0; ep < n; ep++) {
	// 	vector<bool> new_act(n, false);
	// 	for (auto u : act)
	// 		for (auto t : e[u])
	// 			new_act[t] = true;
	// 	act = new_act;
	// }


	ord.clear();
	used.assign(n, false);
	for (int i = 0; i < n; i++)
		if (!used[i])
			DFS(i);
	reverse(ord.begin(), ord.end());

	if (viv) {
		cout << "ord: ";
		for (auto i : ord)
			cout << i << ' ';
		cout << endl;
	}

	zet last = 0;
	for (auto i : ord) {
		for (auto u : e[i]) {
			vmod[u] += vmod[i];
		}
		last = vmod[i];
	}
	ans += last;
	cout << ans << '\n';
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