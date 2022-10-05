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

ll n, ans;
vector<ll> v;
vector<vector<ll>> pl;
set<ll> ban;
bool viv = false;


struct Tree {
	int s = 1;
	int n = 0;
	ll my_null = mod; /// sum
	// ll my_null = inf; /// min
	vector<pair<pll, ll>> t;
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

	// void build(ll sz) {
	// 	n = sz;
	// 	while (s < n)	
	// 		s <<= 1;
	// 	t.resize(2 * s, {my_null, 0});
	// 	cnt_seg();
	// }

	void build(ll _n) {
		n = _n;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {{my_null, 1}, 0});
		for (int i = 0; i < n; i++)
			t[s + i] = {{0, 1}, 0};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}

	inline void adder(int v, ll val) {
		t[v].F.F += val; /// sum
		// t[v].F += val; /// min
		t[v].S += val;
	}


	void upd(int v) {
		if (v >= s)
			return;
		if (t[2 * v].F.F < t[2 * v + 1].F.F)
			t[v].F = t[2 * v].F;
		if (t[2 * v].F.F > t[2 * v + 1].F.F)
			t[v].F = t[2 * v + 1].F;
		if (t[2 * v].F.F == t[2 * v + 1].F.F)
			t[v].F = {t[2 * v].F.F, t[2 * v].F.S + t[2 * v + 1].F.S};
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
			return 0;
		push(v);
		if (l <= tl && tr <= r) 
			return (t[v].F.F == 0) ? t[v].F.S : 0;

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

	// void add(int v, ll val) {
	// 	v += s;
	// 	t[v].F += val;
	// 	v >>= 1;
	// 	while (v)
	// 		upd(v), v >>= 1;
	// }

	void add(int l, int r, ll t) { add(l, r + 1, 1, 0, s, t); }

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << "{{" << t[i].F.F << ' ' << t[i].F.S << "}, " << t[i].S << "}";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
} t;

void prepare() {
	for (int i = 0; i < n; i++) {
		if (pl[i].size()) {
			if (viv)
				cout << "Build " << i << " value" << endl;
			ll r = pl[i].back();
			ll l = -1;
			if (pl[i].size() >= 3)
				l = pl[i][pl[i].size() - 3];
			t.add(l + 1, r, 1);

			if (pl[i].size() >= 4) {
				ban.insert(pl[i][pl[i].size() - 4]);
			}
		}
	}
}

void del(ll r) {
	ll val = v[r];
	if (pl[val].size()) {
		ll r = pl[val].back();
		ll l = -1;
		if (pl[val].size() >= 3)
			l = pl[val][pl[val].size() - 3];
		t.add(l + 1, r, -1);

		if (pl[val].size() >= 4) {
			ban.erase(pl[val][pl[val].size() - 4]);
		}
	}
	pl[val].pop_back();
	if (pl[val].size()) {
		ll r = pl[val].back();
		ll l = -1;
		if (pl[val].size() >= 3)
			l = pl[val][pl[val].size() - 3];
		t.add(l + 1, r, 1);

		if (pl[val].size() >= 4) {
			ban.insert(pl[val][pl[val].size() - 4]);
		}
	}
}

void work(ll r) {
	ll l = -1;
	if (ban.size()) {
		auto z = ban.rbegin();
		l = *z;
	}
	ll lans = t.val(l + 1, r);
	if (viv)
		cout << "with r = " << r << " have: " << lans << endl;
	ans += lans;
}

void solve() {
	cin >> n;
	t.build(n);
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	pl.resize(n);

	for (int i = 0; i < n; i++) {
		pl[v[i]].push_back(i);
	}

	prepare();
	if (viv) {
		for (auto i : ban)
			cout << i << ' ';
		cout << endl;
		t.show();
	}

	for (int r = n - 1; r >= 0; r--) {
		work(r);
		del(r);
	}
	if (viv)
		cout << "ANS = ";
	cout << ans << '\n';
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