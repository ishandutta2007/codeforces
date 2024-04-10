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

ll n, q;
vector<ll> v;
string s, t;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
	ll my_null = 0; /// sum
	// ll my_null = inf; /// min
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) {
		return v1 + v2; /// sum
		// return min(v1, v2); /// min
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
		t.resize(2 * s, {my_null, -1});
		cnt_seg();
	}

	void build(vector<ll> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, -1});
		for (int i = 0; i < n; i++)
			t[s + i] = {v[i], 0};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}

	inline void adder(int v, ll val) {
		t[v].F += val * (seg[v].S - seg[v].F); /// sum
		// t[v].F += val; /// min
		t[v].S += val;
	}

	inline void maker(int v, ll val) {
		if (val) {
			t[v].F = (seg[v].S - seg[v].F); /// sum
			t[v].S = t[v].F / 2;
		} else {
			t[v].F = 0; /// sum
			t[v].S = t[v].F / 2;
		}
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
		if (psh == -1)
			return;
		t[v].S = -1;
		maker(2 * v, psh);
		maker(2 * v + 1, psh);
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
		push(v);
		if (l <= tl && tr <= r) 
			return void(adder(v, val));

		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
		upd(v);
	}

	void make(int l, int r, int v, int tl, int tr, ll val) {
		if (r <= tl || tr <= l)
			return;
		push(v);
		if (l <= tl && tr <= r) 
			return void(maker(v, val));

		int tm = tl + tr >> 1;
		make(l, r, 2 * v, tl, tm, val);
		make(l, r, 2 * v + 1, tm, tr, val);
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

	void make(int l, int r, ll t) { make(l, r + 1, 1, 0, s, t);}

	void show() {
		if (!viv)
			return;
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

void bad() {
	cout << "NO\n";
}

void good() {
	cout << "YES\n";
}

void solve() {
	cin >> n >> q;
	cin >> s >> t;

	v.clear();
	for (auto i : t)	
		v.push_back(i == '1');	

	Tree tr;
	tr.build(v);

	vector<pll> qr(q);
	for (auto &p : qr) 
		cin >> p.F >> p.S, p.F--, p.S--;
	reverse(qr.begin(), qr.end());


	tr.show();
	for (auto p : qr) {
		int l = p.F;
		int r = p.S;

		ll len = r + 1 - l;
		ll sum = tr.val(l, r);

		if (viv)
			cout << p.F << ' ' << p.S << ": " << len << ' ' << sum << endl;

		if (sum * 2 == len) {
			return void(bad());
		}

		if (sum * 2 < len)
			tr.make(l, r, 0);
		else
			tr.make(l, r, 1);

		tr.show();
	}

	for (int i = 0; i < n; i++)
		if (tr.val(i, i) != s[i] - '0')
			return void(bad());
	good();
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