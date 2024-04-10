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
	ll my_null = mod; /// min
	vector<pii> t;
	vector<pii> seg;

	inline int res(int v1, int v2) {
		// return v1 + v2; /// sum
		return min(v1, v2); /// min
	}

	void build(ll sz) {
		n = sz;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, 0});
		// cnt_seg();
	}

	inline void adder(int v, int val) {
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



	int val(int l, int r, int v, int tl, int tr) {
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

	int val(int l, int r) { return val(l, r + 1, 1, 0, s); }

	int val(int pl) { return val(pl, pl + 1, 1, 0, s); }



	void add(int l, int r, int v, int tl, int tr, int val) {
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

	void add(int v, int val) {
		v += s;
		t[v].F += val;
		v >>= 1;
		while (v)
			upd(v), v >>= 1;
	}

	void add(int l, int r, int t) { add(l, r + 1, 1, 0, s, t); }

	void make(int pl, int value) {
		int cur = val(pl);
		if (viv)
			cout << cur << " to " << value << endl;
		if (value < cur)
			add(pl, pl, value - cur);	
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

int n, k;
vector<int> v;
map<int, int> mp;
Tree t[101];

void init() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v) 
		cin >> i, i--;

	for (int i = 0; i <= k; i++) {
		t[i].build(n + 1);
		t[i].make(0, 0);
	}	
}

void work(int ind) {
	int val = v[ind];
	int lst = mp[val];
	lst--;
	mp[val] = ind + 1;
	for (int i = 0; i <= k; i++) {
		t[i].add(0, lst, ind - lst);
	}
	for (int i = 1; i <= k; i++) {
		int ans1 = t[i - 1].val(0, lst);
		int ans2 = t[i - 1].val(lst + 1, ind);
		t[i].make(ind + 1, min(ans1, ans2));
	}
}

void solve() {
	init();
	for (int i = 0; i < n; i++)
		work(i);
	cout << t[k].val(n) << '\n';
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