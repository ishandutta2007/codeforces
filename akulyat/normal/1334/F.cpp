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
// const long long inf = 1000; 


bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
//	ll my_null = 0; // sum
	ll my_null = inf; // min
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) {
		// return v1 + v2; // sum
		return min(v1, v2); // min
	}

	void cnt_seg() {
		seg.resize(2 * s);
		seg[1] = {0, s};
		for (int i = 1; i < s; i++) {
			int tm = seg[i].F + seg[i].S >> 1;
			seg[2 * i] = {seg[i].F, tm};
			seg[2 * i + 1] = {tm, seg[i].S};
		}
	}

	void build(ll sz) {
		n = sz;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, 0});
		cnt_seg();
	}

	void build(vector<ll> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, 0});
		for (int i = 0; i < n; i++)
			t[s + i] = {v[i], 0};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}

	inline void adder(int v, ll val) {
		// t[v].F += val * (seg[v].S - seg[v].F); /// sum
		t[v].F += val; /// min
		t[v].S += val;
	}


	void upd(int v) {
		if (v >= s)
			return;
		t[v].F = res(t[2 * v].F, t[2 * v + 1].F);
	}


	void push(int v) {
		if (v >= s)
			return;
		ll psh = t[v].S;
		if (psh == 0)
			return;
		t[v].S = 0;
		adder(2 * v, psh);
		adder(2 * v + 1, psh);
	}



	ll val(int l, int r, int v, int tl, int tr) {
		if (viv && false)
			cout << "At " << l << ' ' << r << endl;
		if (r <= tl || tr <= l)
			return 5 * my_null;
		push(v);
		if (l <= tl && tr <= r) 
			return t[v].F;

		int tm = tl + tr >> 1;
		ll v1 = val(l, r, 2 * v, tl, tm);
		ll v2 = val(l, r, 2 * v + 1, tm, tr);
		upd(v);
		return res(v1, v2);
	}

	ll val(int l, int r) { return val(l, r + 1, 1, 0, s); }

	ll val(int pl) { return val(pl, pl + 1, 1, 0, s); }



	void add(int l, int r, int v, int tl, int tr, ll val) {
		if (r <= tl || tr <= l)
			return;
		push(v);
		if (l <= tl && tr <= r) 
			return void(adder(v, val));

		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
		upd(v);
	}

	void add(int v, ll val) {
		v += s;
		t[v].F += val;
		v >>= 1;
		while (v)
			upd(v), v >>= 1;
	}

	void add(int l, int r, ll t) { add(l, r + 1, 1, 0, s, t); }

	void make(int pl, ll val_) {
		if (val(pl) < val_)
			return;
		add(pl, val_ - val(pl));
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};


ll n, l;
vector<ll> a, p, b;
Tree t;

void good(ll pl, ll v) {
	auto make_v = min(t.val(pl - 1), t.val(pl) + min(v, 0ll));
	if (viv)
		cout << "Good " << pl << " with " << make_v << endl;
	t.make(pl, make_v);
}

void bad(ll pl, ll pl2, ll v) {
	if (viv)
		cout << "Bad to " << pl << " with " << v << endl;
	t.add(0, pl, v);
	if (v < 0)
		t.add(pl2, t.s - 1, v);
}

void show() {
	if (!viv)
		return;
	cout << "Now : ";
	for (int i = 0; i <= l; i++)
		cout << t.val(i) << ' ';
	cout << '\n';
}

void solve() {
	cin >> n;
	a.resize(n);
	p.resize(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : p)
		cin >> i;
	cin >> l;
	b.resize(l);
	for (auto &i : b)
		cin >> i;

	vector<ll> lans(l + 1, inf);
	lans[0] = 0;
	t.build(lans);
	for (int i = 0; i < n; i++) {
		auto pl = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		auto pl2 = pl + 1;
		if (pl != l && a[i] == b[pl]) {
			good(pl + 1, p[i]);
			pl2++;
		}
		bad(pl, pl2, p[i]);
		show();
	}

	ll ans = t.val(l);
	if (ans > inf / 10) {
		cout << "NO";
		exit(0);
	}
	cout << "YES\n";
	cout << ans << '\n';
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}