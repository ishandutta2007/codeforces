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

ll n, qr;
vector<int> v, q, tms, pref;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
	// ll my_null = 0; /// sum
	ll my_null = mod; /// min
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
			int tms = seg[i].F + seg[i].S >> 1;
			seg[2 * i] = {seg[i].F, tms};
			seg[2 * i + 1] = {tms, seg[i].S};
		}
	}

	void build(ll sz) {
		n = sz;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, 0});
		cnt_seg();
	}

	void build(vector<int> v) {
		n = v.size();
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, 0});
		for (int i = 0; i < n; i++) {
			t[s + i] = {i - v[i], 0};
			if (t[s + i].F < 0)
				t[s + i].F = mod;
		}
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

		int tms = tl + tr >> 1;
		ll v1 = val(l, r, 2 * v, tl, tms);
		ll v2 = val(l, r, 2 * v + 1, tms, tr);
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

		int tms = tl + tr >> 1;
		add(l, r, 2 * v, tl, tms, val);
		add(l, r, 2 * v + 1, tms, tr, val);
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

	int get_zero(int v, int l, int r) {
		push(v);
		if (t[v].F != 0)
			return -1;
		if (l + 1 == r)
			return l;
		int m = l + r >> 1;
		int pr = get_zero(2 * v + 1, m, r);
		if (pr != -1)
			return pr;
		int pl = get_zero(2 * v + 0, l, m);
		return pl;
	}

	int get_zero() {
		return get_zero(1, 0, s);
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

int work(vector<int> v) {
	if (viv) {
		cout << "Work: ";
		for (auto i : v)
			cout << '\t' << i;
		cout << endl;
	}
	for (int i = (int)v.size() - 1; i >= 0; i--)
		if (v[i] == i) {
			vector<int> fv;
			for (int j = 0; j < v.size(); j++) 
				if (j != i) 
					fv.push_back(v[j]);
			return work(fv);
		}
	return v.size();
}

void build() {
	Tree t;
	t.build(v);
	if (viv)
		t.show();
	int pl = t.get_zero();
	while (pl != -1) {
		if (viv)
			cout << "Last zero at " << pl << endl;
		q.push_back(pl);
		t.add(pl, t.s, -1);
		t.add(pl, pl, mod);
		pl = t.get_zero();
	}
	tms.resize(n, q.size());
	for (int i = 0; i < q.size(); i++)
		tms[q[i]] = i;
	pref.resize(n + 1, q.size());
	for (int i = 0; i < n; i++)
		pref[i + 1] = min(pref[i], tms[i]);

	if (viv) {
		for (auto i : q)
			 cout << i << ' ';
		cout << endl;
	}
}

struct node {
	int sum = 0;
	int l = -1, r = -1;

	node() {}
};

struct PerTree{
	vector<node> t;
	vector<int> root;
	int s = 1;

	void build(int n) {
		while (s < n)
			s <<= 1;
		t.resize(2 * s);
		for (int i = 0; i < s; i++) {
			t[i].l = 2 * i + 0;
			t[i].r = 2 * i + 1;
		}
		root.push_back(0);
	}

	int sum(int v) {
		if (v == -1)
			return 0;
		return t[v].sum;
	}

	void upd(int v) {
		t[v].sum = sum(t[v].l) + sum(t[v].r);
		if (viv)
			cout << "\tsum at " << v << " is " << t[v].sum << endl;
	}

	void add(int v, int l, int r, int pl) {
		if (viv)
			cout << "Add " << v << ' ' << l << ' ' << r << endl;
		int num = t.size();		
		t.push_back({});
		if (l + 1 == r) {
			t[num].sum = 1;
			return;
		}
		int m = l + r >> 1;
		if (pl < m) {
			t[num].r = t[v].r;
			t[num].l = t.size();
			add(t[v].l, l, m, pl);
			upd(num);
		} else {
			t[num].l = t[v].l;
			t[num].r = t.size();
			add(t[v].r, m, r, pl);			
			upd(num);
		}
	}

	void add(int pl) {
		if (viv)
			cout << "Add " << pl << endl;
		root.push_back(t.size());
		add(root[(int)root.size() - 2], 0, s, pl);
	}

	int sum(int l, int r, int v, int tl, int tr) {
		if (r <= tl || tr <= l)
			return 0;
		if (l <= tl && tr <= r) {
			return t[v].sum;
		}
		int tm = tl + tr >> 1;
		int res = 0;
		res += sum(l, r, t[v].l, tl, tm);
		res += sum(l, r, t[v].r, tm, tr);
		return res;
	}

	int sum(int root_n, int r) {
		if (viv)
			cout << "Ask sum after " << root_n << " with <= " << r << endl; 
		int v = root[root_n];
		return sum(0, r + 1, v, 0, s);
	}
} pt;

void prepare() {
	pt.build(n);
	if (viv) {
		cout << "Roots: ";
		for (auto v : pt.root)
			cout << v << ' ';
		cout << endl;
	}
	for (auto i : q) {
		pt.add(i);
		if (viv) {
			cout << "Roots: ";
			for (auto v : pt.root)
				cout << v << ' ';
			cout << endl;
			cout << "Sums: ";
			for (int i = 0; i < pt.root.size(); i++)
				cout << pt.sum(i, pt.s) << ' ';
			cout << endl;
		}
	}
}

void solver(vector<int> &v) {
	int sl, sr;
	cin >> sl >> sr;
	auto fv = v;
	for (int i = 0; i < sl; i++)
		fv[i] = v.size() + 1;
	for (int i = 0; i < sr; i++)
		fv[fv.size() - 1 - i] = v.size() + 1;
	int lft = work(fv);
	cout << fv.size() - lft << '\n';
}

void solver2() {
	int sl, sr;
	cin >> sl >> sr;
	int pr = pref[sl];
	int mx = n - 1 - sr;
	int res = pt.sum(pr, mx);
	cout << res << '\n';
	if (viv)
		cout << endl;
}

void solve() {
	cin >> n >> qr;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	build();
	prepare();
	while (qr--)
		solver2();

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