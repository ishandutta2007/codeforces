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
 
ll n;
vector<ll> p, v, pl;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
	ll my_null = 0; // sum
	vector<ll> mn;
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) { // sum
		return v1 + v2;
	}

	inline ll res_mn(ll v1, ll v2) { // sum
		return min(v1, v2);
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
		t.resize(2 * s, {my_null, my_null});
		cnt_seg();
	}

	void build(vector<ll> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, my_null});
		mn.resize(2 * s, my_null);
		for (int i = 0; i < n; i++)
			t[s + i] = {v[i], my_null},
			mn[s + i] = v[i];
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}



	void upd(int v) {
		if (v >= s)
			return;
		t[v].F = 0;
		mn[v] = res_mn(mn[2 * v], mn[2 * v + 1]);
	}

	void push(int v) {
		if (v >= s)
			return;
		ll p = t[v].S;
		if (p == my_null)
			return;
		t[v].S = my_null;
		t[2 * v].S += p;
		t[2 * v + 1].S += p;
		t[2 * v].F = 0;
		t[2 * v + 1].F = 0;
		mn[2 * v] += p;
		mn[2 * v + 1] += p;
	}

	void tree_add(ll v, ll val) { // sum
//		t[v].F += val * (seg[v].S - seg[v].F);
		mn[v] += val;
		t[v].S = res(t[v].S, val);
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

	ll val_mn(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return inf;
		push(v);
		if (l <= tl && tr <= r) 
			return mn[v];
		int tm = tl + tr >> 1;
		ll v1 = val_mn(l, r, 2 * v, tl, tm);
		ll v2 = val_mn(l, r, 2 * v + 1, tm, tr);
		upd(v);
		return res_mn(v1, v2);
	}

	void add(int l, int r, int v, int tl, int tr, ll val) {
		if (r <= tl || tr <= l)
			return;
		// if (viv)
		// 	cout << "         Add " << val << " on " << tl << ' ' << tr << endl;
		push(v);
		if (l <= tl && tr <= r) {
			tree_add(v, val);
			return;
		}
		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
		upd(v);
	}



	ll val(int l, int r) {
		return val(l, r + 1, 1, 0, s);
	}

	ll val_mn(int l, int r) {
		return val_mn(l, r + 1, 1, 0, s);
	}

	void add(int v, ll val) {
		v += s;
		t[v].F = 0;
		mn[v] += val;
		v >>= 1;
		while (v)
			upd(v), v >>= 1;
	}

	void add(int l, int r, ll t) {
		add(l, r + 1, 1, 0, s, t);
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};


void solve() {
	cin >> n;
	p.resize(n);
	pl.resize(n);
	v.resize(n);

	for (auto &i : p)
		cin >> i, i--;
	for (ll i = 0; i < n; i++)
		pl[p[i]] = i;
	for (ll i = 0; i < n; i++)
		cin >> v[p[i]];
	vector<ll> sums;
	sums.push_back(0);
	for (ll i = 0; i < n; i++)
		sums.push_back(sums.back() + v[p[i]]);


	Tree t;
	t.build(sums);

	ll sum = 0;
	ll ans = inf;
	for (ll i = 0; i < n + 1; i++) {
		ll lans = sum + t.val_mn(1, n - 1);
		if (viv) {
			cout << "With " << i << " ans is " << lans << " by " << t.val_mn(1, n - 1) << endl;
			for (ll i = 0; i <= n; i++) 
				cout << t.val_mn(i, i) << ' ';
			cout << endl;
		}
		ans = min(ans, lans);
		if (i < n) {
			t.add(pl[i] + 1, n, -2 * v[i]);
			sum += v[i];
		}
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