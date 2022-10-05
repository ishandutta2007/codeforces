#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")
 
using namespace std;
 
#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
 
ll n;
bool viv = false;
bool tp = true;
vector<pll> v;
vector<ll> mn;
 
vector<ll> build() {
	vector<vector<ll>> e, b;
	e.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		b[v[i].F].push_back(i);
		e[v[i].S].push_back(i);
		if (viv)
			cout << "See " << i << ' ' << v[i].F << ' ' << v[i].S << endl; 
	}
 
	set<pll> s;
	vector<ll> res(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		if (viv)
			cout << "Start " << i << endl;
		for (auto val : e[i]) {
			s.insert({-v[val].F, val});
		}
		if (viv) {
			cout << "s = ";
			for (auto p : s)
				cout << p.F << ' ' << p.S << "; ";
			cout << endl;
		}
		assert(s.size() != 0);
		auto p = *s.begin();
		if (-p.F > i)
			return mn;
		if (-p.F == i || s.size() == 1) {
			res[p.S] = i;
			s.erase(p);
		} else {
			auto bb = *s.begin();
			s.erase(bb);
			auto rb = *s.begin();
			s.insert(bb);
			if (tp) {
				res[bb.S] = i;
				s.erase(bb);
			} else {
				res[rb.S] = i;
				s.erase(rb);
				tp = true;
			}
			if (viv) {
				cout << "Now: ";
				for (auto i : res)
					cout << i << ' ';
				cout << endl;
			}
		}
	}
	return res;
}
 
bool can(ll pl, ll val) {
	if (val < v[pl].F)
		return false;
	if (val > v[pl].S)
		return false;
	return true;
}

void print(vector<ll> v) {
	for (auto i : v)
		cout << i + 1 << ' ';
	cout << '\n';
}
 
void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i.F >> i.S, i.F--, i.S--;
	tp = true;
	auto v1 = build();
	mn = v1;
	tp = false;
	auto v2 = build();

	vector<ll> pl(n, 0);
	for (int i = 0; i < n; i++)
		pl[v1[i]] = i; 
	for (int i = 1; i < n; i++) {
		ll pla = pl[i - 1];
		ll plb = pl[i];
		if (can(pla, i) && can(plb, i - 1)) {
			v2 = v1;
			swap(v2[pla], v2[plb]);
			i = n;
		}
	}
 

	if (v1 == v2 || v2.empty()) {
		cout << "YES\n";
		print(v1);
	} else {
		cout << "NO\n";
		print(v1);
		print(v2);
	}
}
 
 
int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();
 
	return 0;
}