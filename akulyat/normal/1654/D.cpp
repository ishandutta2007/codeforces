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

vector<vector<int>> cons;

void add(int val, int pr) {
	int st_val = val;
	while (val % pr == 0) {
		cons[st_val].push_back(pr);
		val /= pr;
	}
}

void prepare() {
	vector<bool> prime(300 * kk, true);
	cons.resize(300 * kk);
	prime[0] = prime[1] = false;
	for (int i = 0; i < prime.size(); i++) {
		if (prime[i]) {
			for (int j = i; j < prime.size(); j += i) {
				add(j, i);
				if (j > i)
					prime[j] = false;
			}
		}
	}
}

vector<vector<pair<int, pii>>> e;
vector<int> sz;
void DFS(int v) {
	sz[v] = 1;
	for (auto [u, pr] : e[v]) {
		if (sz[u] == -1) {
			DFS(u);
			sz[v] += sz[u];
		}
	}
}

zet ans = 0;
vector<int> cnt;
vector<int> min_cnt;
void DFS2(int v, zet val) {
	if (viv)	
		cout << v << ' ' << val << endl;
	ans += val;
	sz[v] = 1;
	for (auto [u, pr] : e[v]) {
		if (sz[u] == -1) {
			for (auto p : cons[pr.S]) {
				cnt[p]++;
			}
			for (auto p : cons[pr.F]) {
				cnt[p]--;
			}
			if (viv) {
				cout << " to " << u << ": ";
				for (int i = 1; i < n; i++)
					cout << cnt[i] << "; ";
				cout << endl;
			}
			for (auto p : cons[pr.S]) {
				min_cnt[p] = min(min_cnt[p], cnt[p]);
				if (min_cnt[p] < 0)
					cout << p << endl;
				assert(min_cnt[p] >= 0);
			}
			for (auto p : cons[pr.F]) {
				min_cnt[p] = min(min_cnt[p], cnt[p]);
				if (min_cnt[p] < 0)
					cout << p << endl;
				assert(min_cnt[p] >= 0);
			}
			DFS2(u, (val / pr.F) * pr.S);
			for (auto p : cons[pr.S]) {
				cnt[p]--;
			}
			for (auto p : cons[pr.F]) {
				cnt[p]++;
			}
			sz[v] += sz[u];
		}
	}
}

void solve() {
	cin >> n;
	e.assign(n, {});
	vector<array<int, 4>> ed;
	for (int i = 1; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		auto g = __gcd(c, d);
		c /= g;
		d /= g;

		a--, b--;
		e[a].push_back({b, {c, d}});
		e[b].push_back({a, {d, c}});
		ed.push_back({a, b, c, d});
	}

	sz.assign(n, -1);
	int root = 0;
	DFS(root);

	zet root_val = 1;

	cnt.assign(n + 1, 0);
	for (auto [v, u, c, d] : ed) {
		if (sz[v] < sz[u])
			swap(v, u), swap(c, d);
		if (viv)
			cout << "by " << v << ' ' << u << ' ' << " add " << c << endl;
		root_val *= c;
		for (auto p : cons[c]) {
			cnt[p]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (viv)
			cout << i << " start " << cnt[i] << endl;
	}
	min_cnt = cnt;

	sz.assign(n, -1);
	ans = 0;
	DFS2(root, root_val);
	if (viv)	
		cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (viv)
			cout << i << " give " << min_cnt[i] << endl;
		for (int j = 0; j < min_cnt[i]; j++)
			ans /= i;
	}
	cout << ans << '\n';
	if (viv)
		cout << endl;
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