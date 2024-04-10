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
			cout << '\t' << '{' << t[i].F << "   " << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

int n, m, q;
vector<int> val;
vector<int> ver_by_val;
vector<vector<int>> e;
vector<pii> all;
vector<pii> qr;
bool viv = false;

vector<int> p;
vector<vector<int>> kids;
int nxt;
vector<int> spliter;

vector<int> value_st;
Tree st;

set<pii> seg;

void read() {
	cin >> n >> m >> q;
	val.resize(n);
	ver_by_val.resize(n);
	for (auto &i : val)
		cin >> i, i--;
	for (int i = 0; i < n; i++)
		ver_by_val[val[i]] = i;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
		all.push_back({a, b});
	}

	qr.resize(q);
	set<int> left;
	for (int i = 0; i < m; i++)
		left.insert(i);
	for (auto &p : qr) {
		cin >> p.F >> p.S;
		p.F--;
		p.S--;
		if (p.F)
			left.erase(p.S);
	}
	for (auto ed : left)
		qr.push_back({1, ed});
	q = qr.size();	
}

int pr(int v) {
	if (p[v] == v)
		return v;
	return p[v] = pr(p[v]);
}

bool unit(int v, int u) {
	v = pr(v);
	u = pr(u);
	if (v == u)
		return false;
	int s = nxt++;
	kids[s].push_back(v);
	kids[s].push_back(u);
	p[v] = s;
	p[u] = s;
	return true;
}

void prepare() {
	p.resize(2 * n - 1);
	kids.resize(2 * n - 1);
	for (int i = 0; i < p.size(); i++)
		p[i] = i;
	nxt = n;
	vector<ll> ord;
	for (auto p : qr)
		if (p.F)
			ord.push_back(p.S);
	reverse(ord.begin(), ord.end());
	for (auto num : ord) {
		int v = all[num].F;
		int u = all[num].S;
		if (unit(v, u))
			spliter.push_back(nxt - 1);
		else
			spliter.push_back(-1);
	}
	if (viv) {
		for (int i = 0; i < nxt; i++) {
			cout << "kids[" << i << "] = ";
			for (auto v : kids[i])
				cout << v << ' ';
			cout << endl;
		}
		cout << "Spliter = ";
		for (auto i : spliter)
			cout << i << ' ';
		cout << endl;
	}
}

vector<int> tin, tout;
int t = 0;

void DFS(int v) {
	int my_val = -mod;
	if (v < n)
		my_val = val[v];
	value_st[t] = my_val;
	tin[v] = t++;

	for (auto u : kids[v])
		if (tin[u] == -1) 
			DFS(u);

	value_st[t] = my_val;
	tout[v] = t++;
}

void build() {
	tin.resize(nxt, -1);
	tout.resize(nxt, -1);
	value_st.resize(2 * nxt);
	for (int i = nxt - 1; i >= 0; i--) {
		if (tin[i] == -1) {
			DFS(i);
			seg.insert({tin[i], tout[i]});
		}
	}
	st.build(value_st);

	if (viv) {
		for (int i = 0; i < nxt; i++) {
			cout << "seg[" << i << "] = " << tin[i] << ' ' << tout[i] << endl;
		}
	}
}

bool out_seg(int p, pii seg) {
	if (p < seg.F || seg.S < p)
		return true;
	return false;
}

void work() {
	if (viv)
		st.show();
	for (auto p : qr) {
		if (p.F) {
			int s = spliter.back();
			spliter.pop_back();
			if (s != -1) {
				int v = kids[s][0];
				int u = kids[s][1];
				if (viv) {
					cout << "split vertex " << s << " on " << v << " and " << u << endl;
				}
				seg.erase({tin[s], tout[s]});
				seg.insert({tin[v], tout[v]});
				seg.insert({tin[u], tout[u]});

				if (viv) {
					for (auto p : seg)
						cout << '{' << p.F << ", " << p.S << "}, ";
					cout << endl;
				}
			}
		} else {
			int v = p.S;
			int pl = tin[v];
			if (viv)
				cout << "find for " << v << " include " << tin[v] << endl;
			auto z = seg.lower_bound({pl, pl});
			while (out_seg(pl, *z))
				z--;

			auto pr = *z;
			int l = pr.F;
			int r = pr.S;
			auto ans = st.val(l, r);
			if (ans >= 0) {
				cout << ans + 1 << '\n';

				v = ver_by_val[ans];
				st.add(tin[v], tin[v], -mod);
				st.add(tout[v], tout[v], -mod);
				if (viv)
					st.show();
			} else {
				cout << "0\n";
			}
		}
	}
}

void solve() {
	read();
	prepare();
	build();
	work();
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