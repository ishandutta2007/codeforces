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



ll n, ans, u;
vector<ll> p, q, a, where;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
//	ll my_null = 0; /// sum
	ll my_null = inf; /// min
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) {
//		return v1 + v2; /// sum
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
//		t[v].F += val * (seg[v].S - seg[v].F); /// sum
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

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

Tree bomb, used;

void prepare() {
	vector<ll> vv;
	vv.resize(n);
	bomb.build(vv);
	used.build(n);
}

bool bad(ll ans) {
	if (viv)
		cout << "Bad " << ans << endl;
	bomb.add(0, where[ans], -1);
	if (viv) {
		cout << "Mini " << bomb.val(0, n - 1) << endl;
		for (auto i : bomb.t)
			cout << i.F << ' ';
		cout << endl;
	}
	if (bomb.val(0, n - 1) >= 0) {
		return true;
	}
	bomb.add(0, where[ans], 1);
	return false;
}

void add(ll pl) {
	bomb.add(0, pl, 1);
}

void check() {
	while (ans > 0 && bad(ans)) {
		ans--;
	}
}

void solve() {
	cin >> n;
	p.resize(n);
	q.resize(n);
	for (auto &i : p)
		cin >> i, i--;
	for (auto &i : q)
		cin >> i, i--;
	where.resize(n);
	for (int i = 0; i < n; i++)
		where[p[i]] = i;

	prepare();
	ans = n - 1;
	a.push_back(ans);

	for (auto i : q) {
		if (viv) {
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "New\n\n";
		}
		add(i);
		check();
		a.push_back(ans);
	}
	a.pop_back();

	for (auto i : a)
		cout << i + 1 << ' ';
	cout << endl;
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}