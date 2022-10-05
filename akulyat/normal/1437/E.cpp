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

ll n, k;
vector<ll> v, pl;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
	// ll my_null = 0; /// sum
	ll my_null = -inf; /// min
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
		vector<ll> vec;
		vec.resize(sz, 0);
		build(vec);
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

void bad() {
	cout << -1 << endl;
	exit(0);
}

ll get_up(vector<ll> vec) {
	if (viv) {
		cout << "get_up: ";
		for (auto i : vec)
			cout << i << ' ';
		cout << endl;
	}
	set<ll> all;
	map<ll, ll> num;
	for (auto i : vec)
		all.insert(i);
	ll cnt = 0;
	for (auto i : all)
		num[i] = cnt++;
	for (auto &i : vec)
		i = num[i];
	Tree t;
	t.build(vec.size());

	for (int i = 0; i < vec.size(); i++) {
		t.add(vec[i], vec[i], -t.val(vec[i], vec[i]) + t.val(0, vec[i]) + 1);		
	}
	ll ans = t.val(0, vec.size() - 1);
	if (viv) {
		cout << "See = " << ans << endl;
	}
	return ans;
}

ll need(vector<ll> vec) {
	if (vec.empty())
		return 0;
	ll max_up = get_up(vec);
	return (ll)vec.size() - max_up;
}

void solve() {
	cin >> n;
	cin >> k;
	v.resize(n + 2);
	v[0] = -10 * mod;
	v[n + 1] = 10 * mod;	
	for (int i = 0; i < n; i++)
		cin >> v[i + 1];
	n += 2; 
	for (int i = 0; i < n; i++)
		v[i] -= i;

	pl.resize(k + 2);
	pl[0] = 0;
	pl[k + 1] = n - 1;	
	for (int i = 0; i < k; i++)
		cin >> pl[i + 1];
	k += 2;

	if (viv) {
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}

	for (int i = 1; i < k; i++)
		if (v[pl[i - 1]] > v[pl[i]])
			bad();		
	ll ans = 0;
	for (int i = 1; i < k; i++) {
		int l = pl[i - 1];
		int r = pl[i];
		ll a = v[l];
		ll b = v[r];
		ll lans = 0;
		vector<ll> vec;
		for (int j = l + 1; j < r; j++)
			if (v[j] < a || v[j] > b)
				lans++;
			else
				vec.push_back(v[j]);
		if (viv) {
			cout << l << ' ' << r << ": ";
			cout << lans << " -> ";
		}
		lans += need(vec);
		if (viv)	
			cout << lans << endl;
		ans += lans;
	}
	cout << ans << '\n';
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