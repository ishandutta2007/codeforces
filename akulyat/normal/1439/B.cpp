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
 
ll n, m, k;
vector<unordered_set<int>> e;
set<pii> s;
bool viv = false;
vector<pll> h, hsh;
 
 
void prepare() {
	hsh.resize(n, {0, 0});
	for (auto &p : hsh) {
		p.F = uniform_int_distribution<int>(0, mod)(rng);
		p.S = uniform_int_distribution<int>(0, mod)(rng);
	}
	h = hsh;
}
 
int bad() {
	if (s.size() == 0)
		return false;
	auto p = *s.begin();
	if (p.F < k)
		return true;
	return false;
}
 
void add(int v, int u) {
	s.erase({e[v].size(), v});
	e[v].insert(u);
	s.insert({e[v].size(), v});
	h[v].F += hsh[u].F;
	h[v].S += hsh[u].S;
}
 
void delet(int v, int u) {
	s.erase({e[v].size(), v});
	e[v].erase(u);
	s.insert({e[v].size(), v});
	h[v].F -= hsh[u].F;
	h[v].S -= hsh[u].S;
}
 
void adder(int v, int u) {
	if (viv)
		cout << "adder " << v << ' ' << u << endl;
	add(v, u);
	add(u, v);
}
 
void deleter(int v, int u) {
	if (viv)
		cout << "deleter " << v << ' ' << u << endl;
	delet(v, u);
	delet(u, v);
}
 
bool is_c(int v, vector<int> u) {
	if (u.size() != k - 1)
		return false;
	u.push_back(v);
	for (auto s : u) 
		for (auto t : u)
			if (e[s].find(t) == e[s].end() && s != t)
				return false;
	cout << 2 << '\n';
	for (auto s : u)
		cout << s + 1 << ' ';
	cout << '\n';
	return true;
}
 
bool del() {
	auto p = *s.begin();
	auto v = p.S;
	if (viv) {
		cout << "del " << v << endl;
		for (auto p : s)
			cout << p.F << ' ' << p.S << "; ";
		cout << endl;
	}
	vector<int> u;
	for (auto s : e[v])
		u.push_back(s);
	if (is_c(v, u))
		return true;
	for (auto s : u)
		deleter(v, s);
	s.erase({e[v].size(), v});
	return false;
}
 
void cool() { 
	cout << "1 " << s.size() << '\n';
	for (auto &p : s)
		cout << p.S + 1 << ' ';
	cout << '\n';
}
 
void solve() {
	cin >> n >> m >> k;
	prepare();
	e.clear();
	e.resize(n);
	s.clear();
	for (int i = 0; i < n; i++)
		s.insert({0, i});
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adder(a, b);
	}
	while (bad())
		if (del())
			return;
	if (s.size()) {
		cool();
		return;
	}
	cout << "-1\n";
}
 
int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}