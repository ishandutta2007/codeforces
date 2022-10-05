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

bool viv = false;


struct Tree {
	int s = 1;
	int n = 0;
	// ll my_null = 0; /// sum
	ll my_null = inf; /// min
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) {
		// return v1 + v2; /// sum
		return min(v1, v2); /// min
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
		t.resize(2 * s, {0, 0});
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
		if (r <= tl || tr <= l)
			return my_null;
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
		if (viv)
			cout << "add " << val << " on [" << tl << ", " << tr << "] with aim [" << l << ", " << r << "] " << endl;
		push(v);
		if (l <= tl && tr <= r) {
			if (viv)
				cout << "\t\tADD" << endl;
			return void(adder(v, val));
		}

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

	int get_ans(int v, int tl, int tr) {
		push(v);
		if (viv)
			cout << "on " << v << " [" << tl << ", " << tr << "] see " << t[v].F << endl;
		if (t[v].F >= 0)
			return -1;
		if (tl + 1 == tr)
			return tl;
		int tm = tl + tr >> 1;
		int ansr = get_ans(2 * v + 1, tm, tr);
		if (ansr != -1)
			return ansr;
		int ansl = get_ans(2 * v + 0, tl, tm);
		return ansl;
	}

	int answer() {
		return get_ans(1, 0, s);
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

int n, m;
vector<int> a, b;
Tree t;

void read() {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;
}

void build() {
	t.build(ml + 100);
	for (auto i : a)
		t.add(0, i, -1);
	for (auto i : b)
		t.add(0, i, 1);
}

void work() {
	int tp;
	cin >> tp;
	if (tp == 1) {
		int pl, val;
		cin >> pl >> val;
		pl--;
		t.add(0, a[pl], 1);
		a[pl] = val;
		t.add(0, a[pl], -1);
	}
	if (tp == 2) {
		int pl, val;
		cin >> pl >> val;
		pl--;
		t.add(0, b[pl], -1);
		b[pl] = val;
		t.add(0, b[pl], 1);
	}
	int ans = t.answer();
	cout << ans << '\n';
}

void solve() {
	read();
	build();
	int q;
	cin >> q;
	while (q--)
		work();

}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}