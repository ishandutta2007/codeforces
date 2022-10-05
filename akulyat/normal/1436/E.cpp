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
vector<ll> v;
vector<vector<ll>> pl;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
	// ll my_null = 0; /// sum
	ll my_null = -mod; /// min
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) {
		// return v1 + v2; /// sum
		return max(v1, v2); /// min
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
		vector<ll> v(sz, 0);
		build(v);
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

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	pl.resize(n);
	for (int i = 0; i < n; i++)
		pl[v[i]].push_back(i);
	for (int i = 0; i < n; i++)
		pl[i].push_back(n);
	for (int i = 0; i < n; i++) 
		reverse(pl[i].begin(), pl[i].end());
	Tree t;
	t.build(n);
	for (int i = 0; i < n; i++) 
		t.add(i, i, pl[i].back());
	vector<bool> bad(n + 2, false);

	if (t.val(0, n - 1) < n)
		bad[n] = true;

	if (v[0] != 0)
		bad[0] = true;
	for (int i = 1; i < n; i++) {
		int nxt = pl[i][pl[i].size() - 1];
		if (viv)
			cout << i << ' ' << nxt << ": " << t.val(0, i - 1) << endl;
		if (t.val(0, i - 1) < nxt)
			bad[i] = true;
	}


	for (int i = 0; i < n; i++) {
		int who = v[i];
		int nxt = pl[who][pl[who].size() - 2];
		if (who == 0) {
			if (nxt != i + 1)
				bad[who] = true;
		} else {
			if (viv)
				cout << who << ' ' << nxt << ": " << t.val(0, who - 1) << endl;
			if (t.val(0, who - 1) < nxt)
				bad[who] = true;
		}
		t.add(who, who, -pl[who].back());
		pl[who].pop_back();
		t.add(who, who, pl[who].back());
	}

	bad[0] = false;
	for (auto i : v)
		if (i)
			bad[0] = true;

	int ans = 0;
	while (bad[ans])
		ans++;

	cout << ans + 1 << '\n';
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