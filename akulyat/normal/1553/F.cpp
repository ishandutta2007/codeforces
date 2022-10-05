#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef unsigned long long       ull;
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

const int N = 300 * kk + 100;
const int SZ = 2 * N + 100;;
const int C = 60;

int n;
vector<int> v;
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
		t[v].F += val * (seg[v].S - seg[v].F); /// sum
		// t[v].F += val; /// min
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


	int l, r;
	ll val(int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return my_null;
		// push(v);
		if (l <= tl && tr <= r) 
			return t[v].F;

		int tm = tl + tr >> 1;
		ll v1 = val(2 * v, tl, tm);
		ll v2 = val(2 * v + 1, tm, tr);
		// upd(v);
		return res(v1, v2);
	}

	ll val(int ml, int mr) { 
		mr = min(mr, s - 1);
		l = ml;
		r = mr + 1;
		return val(1, 0, s); }

	void add(int l, int r, ll val) {
		if (l >= s)
			return;
		int v = l + s;
		while (v) {
			t[v].F += val;
			v >>= 1;
		}
	}

	// void add(int v, int tl, int tr, ll val) {
	// 	if (r <= tl || tr <= l)
	// 		return;
	// 	push(v);
	// 	if (l <= tl && tr <= r) 
	// 		return void(adder(v, val));

	// 	int tm = tl + tr >> 1;
	// 	add(2 * v, tl, tm, val);
	// 	add(2 * v + 1, tm, tr, val);
	// 	upd(v);
	// }

	// void add(int ml, int mr, ll t) { 
	// 	mr = min(mr, s - 1);
	// 	l = ml;
	// 	r = mr + 1;
	// 	add(1, 0, s, t); }

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
	// n = 200 * kk;

	v.resize(n);

	for (auto &i : v)
		cin >> i;
	// for (int i = 0; i < n; i++)
	// 	v[i] = i + 1;


	Tree sum;
	Tree cnt;

	sum.build(N);
	cnt.build(N);

	Tree ans_c;
	Tree ans_s;

	ans_s.build(N);
	ans_c.build(N);

	vector<bool> was(N, false);
	vector<ll> vans1(n, 0);
	vector<ll> mp(N + 1, 0);
	for (int i = 0; i < n; i++) {
		int k = v[i];
		mp[k] = (ll)i * k - ans_s.val(0, k);
		// cout << "prev: " << mp[k] << endl;
		int l = 0, r = k - 1;
		ll ins = 0;
		ll ans1 = 0;
		while (l <= N) {
			ll sm = sum.val(l, r);
			ll ct = cnt.val(l, r);
			// ans_c.add(l, r, 1);
			ans_s.add(l, l, k * ins);
			ans_s.add(r + 1, r + 1, -k * ins);
			sm -= ct * k * ins;
			ans1 += sm;

			ins++;
			l += k;
			r += k;
		}

		cnt.add(k, k, 1);
		sum.add(k, k, k);

		vans1[i] = ans1;
		if (ans1 < 0) {
			cout << "AAA" << endl;
			exit(1);
		}
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll add = mp[v[i]];
		if (add < 0) {
			cout << "BAD" << endl;
			exit(1);
		}
		res += add;
		res += vans1[i];
		cout << res << ' ';
	}


	cout << '\n';
}

int main() {
	viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}