#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
 
ll n, m, k;
vector<pll> a, b;
vector<pair<pll, ll>> op;
bool viv = false;

struct tree {
	vector<pll> t;
	ll n, s;

	tree() {

	}

	void build(ll sz) {
		n = sz;
		s = 1;
		while (s < n)
			s <<= 1;
		t.resize(2 * s);
	}

	void push(ll v) {
		if (v >= s)
			return;
		ll ps = t[v].S;
		t[v].S = 0;
		t[2 * v].F += ps;
		t[2 * v].S += ps;
		t[2 * v + 1].F += ps;
		t[2 * v + 1].S += ps;
	}

	void upd(ll v) {
		if (v >= s)
			return;
		t[v].F = max(t[2 * v].F, t[2 * v + 1].F);
	}

	void adder(pair<pll, ll> p) {
		add(p.F.S, s, 1, 0, s, p.S);
	}

	void add(ll l, ll r, ll v, ll tl, ll tr, ll val) {
		if (r <= tl || tr <= l)
			return;
		push(v);
		if (l <= tl && tr <= r) {
			t[v].F += val;
			t[v].S += val;
			return;
		}
		ll tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
		upd(v);
	}

	ll val() {
		return t[1].F;
	}

	// void show(ll v) {
	// 	if (v >= s) {
	// 		cout << t[v].F << ' ' << t[v].S << "; ";
	// 		return;
	// 	}
	// 	show(2 * v);
	// 	show(2 * v + 1);
	// }

	// void show() {
	// 	for (ll i = 1; i < 2 * s; i++) {
	// 		cout << t[i].F << ' ' << t[i].S << "; ";
	// 		if (!(i & (i + 1)))
	// 			cout << endl;
	// 	}
	// }

} t;

void solve() {
	cin >> n >> m >> k;
	a.resize(n);
	b.resize(m);
	op.resize(k);
	for (auto &i : a)
		cin >> i.F >> i.S;
	for (auto &i : b)
		cin >> i.F >> i.S;
	for (auto &i : op)
		cin >> i.F.F >> i.F.S >> i.S;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	auto rb = b;
	rb.clear();
	reverse(b.begin(), b.end());
	ll mini = mod;
	for (auto p : b) {
		if (p.S < mini)
			rb.push_back(p), mini = p.S;
	}
	b = rb;
	reverse(b.begin(), b.end());

	sort(op.begin(), op.end());
	reverse(op.begin(), op.end());

	/////////////////////////////////////////////////
	t.build(ml + 110);
	for (ll i = 0; i < b.size(); i++) {
		ll l = 0;
		ll r = t.s;
		if (i > 0)
			l = b[i - 1].F;
		r = b[i].F;
		t.add(l, r, 1, 0, t.s, -b[i].S);
	}
	t.add(b.back().F, t.s, 1, 0, t.s, -100 * mod);


	ll ans = -100 * mod;
	for (auto p : a) {
		while (op.size() && op.back().F.F < p.F)
			t.adder(op.back()), op.pop_back();
		ll res = t.val();
		// if (viv)
		// 	cout << "Now " << res << endl;
		res -= p.S;
		ans = max(ans, res);
		// if (viv)
		// 	t.show();
	}
	cout << ans << endl;

}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}