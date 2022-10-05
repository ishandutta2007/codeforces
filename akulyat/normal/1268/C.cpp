#include <bits/stdc++.h>

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


ll n, i, j;
vector<ll> m, pl;
bool viv = false;

struct Tree {
	int s = 1;
	int n = 0;
	int my_null = 0; // sum
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) { // sum
		return v1 + v2;
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
		for (int i = 0; i < n; i++)
			t[s + i] = {v[i], my_null};
		for (int i = s - 1; i > 0; i--)
			upd(i);
		cnt_seg();
	}



	void upd(int v) {
		if (v >= s)
			return;
		t[v].F = res(t[2 * v].F, t[2 * v + 1].F);
	}

	void push(int v) {
		if (v >= s)
			return;
		ll p = t[v].S;
		if (p == my_null)
			return;
		t[v].S = my_null;
		t[2 * v].S = p;
		t[2 * v + 1].S = p;
		t[2 * v].F = res(t[2 * v].F, p);
		t[2 * v + 1].F = res(t[2 * v + 1].F, p);
	}

	void tree_add(ll v, ll val) { // sum
		t[v].F += val * (seg[v].S - seg[v].F);
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

	void add(int l, int r, int v, int tl, int tr, ll val) {
		if (r < tl || tr < l)
			return;
		push(v);
		if (l <= tl && tr <= r) {
			tree_add(v, val);
			return;
		}
		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
	}



	ll val(int l, int r) {
		return val(l, r + 1, 1, 0, s);
	}

	void add(int v, ll val) {
		v += s;
		while (v)
			t[v].F = res(t[v].F, val), v >>= 1;
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

ll summ(ll l, ll r) {
	ll res = ((r - l + 1) * (l + r)) / 2;
	if (viv)
		cout << "Sum on " << l << ' ' << r << " is " << res << endl;
	return res;
}

void solve() {
	cin >> n;
	m.resize(n);
	for (auto &i : m)
		cin >> i, i--;

	pl.resize(n);
	for (ll i = 0; i < n; i++) {
		pl[m[i]] = i;	
	}

	Tree t, sm;
	t.build(n);
	sm.build(n);

	ll ans = 0;
	set<ll> p;
	ll mid = 0;

	for (ll i = 0; i < n; i++) {
		ll tran = t.val(pl[i], n-1);
		ans += tran;
		ll lans = ans;

		p.insert(pl[i]);
		if (p.size() == 1)
			mid = pl[i];
		if (i & 1) {
			if (pl[i] < mid) {
				auto z = p.find(mid);
				z--;
				mid = *z;
			}
		} else {
			if (pl[i] > mid)  {
				auto z = p.find(mid);
				z++;
				mid = *z;				
			}
		}
		sm.add(pl[i], pl[i]);		

		ll aft = (i + 1) / 2;
		ll bef = i - aft;

		ll hb = sm.val(0, mid - 1);
		ll wb = summ(mid - bef, mid - 1);
		ll ha = sm.val(mid + 1, n - 1);
		ll wa = summ(mid + 1, mid + aft);

		if (viv) {
			cout << "My mid is " << mid << endl;
			cout << hb << ' ' << wb << ' ' << ha << ' ' << wa << endl;
			cout << aft << ' ' << bef << endl;
			cout << i << ": " << (i + 1) / 2 << ' ' << i - (i + 1) / 2 << endl;
		}
		lans += wb - hb;
		lans += ha - wa;

		if (viv) 
			cout << "         Ans = ";
		cout << lans << ' ';

		if (viv)
			cout << endl;
		t.add(pl[i], 1);		
	}
}

int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while(t--)
    	solve();






    return 0;
}