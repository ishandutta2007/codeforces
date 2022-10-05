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

ll n;
vector<pll> v;
vector<ll> dp;
vector<ll> p;
bool viv = false;


struct Tree {
	int s = 1;
	int n = 0;
	// ll my_null = 0; /// sum
	ll my_null = inf; /// min
	vector<pair<pll, ll>> t;
	vector<pll> seg;

	inline pll res(pll v1, pll v2) {
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
		t.resize(2 * s, {{my_null, 0}, 0});
		for (int i = 0; i < n; i++)
			t[s + i].F.S = i;
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}

	void build(vector<ll> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {{my_null, -1}, 0});
		for (int i = 0; i < n; i++)
			t[s + i] = {{v[i], i}, 0};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}

	inline void adder(int v, ll val) {
		// t[v].F += val * (seg[v].S - seg[v].F); /// sum
		t[v].F.F += val; /// min
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



	pll val(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return {my_null, -1};
		push(v);
		if (l <= tl && tr <= r) 
			return t[v].F;

		int tm = tl + tr >> 1;
		auto v1 = val(l, r, 2 * v, tl, tm);
		auto v2 = val(l, r, 2 * v + 1, tm, tr);
		upd(v);
		return res(v1, v2);
	}

	pll val(int l, int r) { return val(l, r + 1, 1, 0, s); }

	pll val(int pl) { return val(pl, pl + 1, 1, 0, s); }



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


	void add(int l, int r, ll t) { add(l, r + 1, 1, 0, s, t); }

	void add(int l, ll t) {
		add(l, l, t);
	}

	void make(int l, ll t) {
		add(l, l, t - val(l).F);
	}

	void show() {
		if (!viv)
			return;
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F.F << ' ' << t[i].F.S << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

ll sum(int l, int r) {
	return p[r + 1] - p[l];
}

void ch(int now, int lst) {
	if (viv)	
		cout << "\tcheck(" << now << ", " << lst << ")" << endl;
	dp[now] = min(dp[now], dp[lst] + sum(lst + 1, now - 1) + max(v[now].S, v[lst].F - v[now].F));
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;
	sort(v.rbegin(), v.rend()); 


	p.assign(1, 0);
	for (int i = 0; i < n; i++)
		p.push_back(p.back() + v[i].S);

	dp.assign(n, inf);
	vector<int> pl1(n), pl2(n);
	pl1[0] = pl2[0] = dp[0] = v[0].S;

	Tree t1, t2;
	t1.build(n);
	t2.build(n);
	t1.make(0, dp[0]);
	t2.make(0, dp[0]);
	t1.show();
	t2.show();

	for (int i = 1; i < n; i++) {

		int l = -1;
		int r = i;
		while (l + 1 < r) {
			int m = l + r >> 1;
			if (v[m].F - v[i].F > v[i].S) 
				l = m;
			else
				r = m;
		}

		// int pl01 = t1.val(l, i - 1).S;
		// int pl02 = t2.val(0, i - 1).S;

		int pl01 = t1.val(0, l).S;
		int pl02 = t2.val(r, i - 1).S;

		if (pl01 != -1)
			ch(i, pl01);
		if (pl02 != -1)
			ch(i, pl02);

		pl1[i] = dp[i] - (dp[i - 1] - pl1[i - 1]) - (v[i - 1].F - v[i].F) - v[i].S;
		pl2[i] = dp[i] - (dp[i - 1] - pl2[i - 1])- v[i].S;

		t1.make(i, pl1[i]);
		t2.make(i, pl2[i]);

		t1.show();
		t2.show();
	}

	if (viv) {
		for (auto i : dp)
			cout << i << ' ';
		cout << endl;
	}


	cout << dp.back() << '\n';
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