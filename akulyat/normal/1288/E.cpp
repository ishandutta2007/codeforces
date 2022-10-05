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
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;

vector<ll> vec;

ll ran() {
	return (rand() % ml);
}

struct node {
	ll l = -1, r = -1;
	ll val, prior = ran();
	ll sz = 1;
	bool rev;
};


struct treap {
	ll root = -1;
	vector<node> t;

	treap(ll n) {
		t.resize(n);
		for (ll i = 0; i < n; i++) {
			t[i].val = i + 1;
		}
	}

	int sz(int v) {
		if (v == -1)
			return 0;
		return t[v].sz;
	}

	void set(ll v) {
		if (v == -1)
			return;
		t[v] .rev = t[v].rev ^ true;
	}

	void push(ll v) {
		if (v == -1 || !t[v].rev)
			return;
		swap(t[v].l, t[v].r);
		set(t[v].l);
		set(t[v].r);
		t[v].rev = false;
	}

	void upd(ll v) {
		if (v == -1)
			return;
		t[v].sz = 1;
		t[v].sz += sz(t[v].l);
		t[v].sz += sz(t[v].r);
	}

	void merge(ll &v, ll l, ll r) {
		push(l);
		push(r);
		if (l == -1 || r == -1) 
			return void(v = (l != -1) ? l : r);
		if (t[l].prior > t[r].prior)
			merge(t[l].r, t[l].r, r), v = l;
		else
			merge(t[r].l, l, t[r].l), v = r;		
		upd(v);
	}

	// void split(ll v, ll &l, ll &r, int ind) {
	// 	push(v);
	// 	if (v == -1)
	// 		return void(l = r = -1);
	// 	int lsz = sz(t[v].l);
	// 	if (lsz + 1 <= ind) 
	// 		split(t[v].r, t[v].r, r, ind - lsz - 1), l = v;
	// 	else
	// 		split(t[v].l, l, t[v].l, ind), r = v;
	// 	upd(l);
	// 	upd(r);
	// }

	void split(ll v, ll &l, ll &r, int ind) {
		push(v);
		if (v == -1)
			return void(l = r = -1);
		if (t[v].val < ind) 
			split(t[v].r, t[v].r, r, ind), l = v;
		else
			split(t[v].l, l, t[v].l, ind), r = v;
		upd(l);
		upd(r);
	}

	void add(ll val) {
		t.push_back(node());
		t.back().val = val;
		merge(root, root, t.size() - 1);
	}

	ll del(ll val) {
		ll t1, t2, t3;
		split(root, t1, t2, val);
		split(t2, t2, t3, val + 1);
		ll res = sz(t1);
		merge(root, t1, t3);
		return res;
	}

	void ahead(ll l, ll r) {
		l--;
		ll t1, t2, t3;
		split(root, t1, t2, r);
		push(t1);
		t[t1].rev = true;
		merge(root, t1, t2);


		split(root, t1, t3, r);
		l = r - l;
		split(t1, t1, t2, l);
		if (t1 != -1) {
			push(t1);
			t[t1].rev = true;			
		}
		if (t2 != -1) {
			push(t2);
			t[t2].rev = true;			
		}

		merge(t1, t1, t2);
		merge(root, t1, t3);
	}

	void show(ll v) {		
		push(v);
		if (v == -1)
			return;
		show(t[v].l);
		vec.push_back(t[v].val);
//		cout << t[v].val << ' ';
		show(t[v].r);
	}

	void det(ll v) {
		if (v == -1)
			return;
		det(t[v].l);
		cout << "I'm " << t[v].val << " with kids " << t[v].l << ' ' << t[v].r << " and rev = " << t[v].rev << endl;
		cout << t[v].prior << endl;
		det(t[v].r);
	}
};

 
 
ll n;
vector<ll> m;
bool viv = false;

void solve() {
	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		m.push_back(n - 1 - i);
	for (ll i = 0; i < k; i++) {
		ll a;
		cin >> a;
		a--;
		m.push_back(a);
	}
	treap t(0);
	vector<ll> pl;
	pl.resize(n);

	vector<pll> ans(n);
	for (ll i = 0; i < n; i++) {
		ans[i] = {i + 1, i + 1};
	}

	for (ll i = 0; i < m.size(); i++) {
		ll a = m[i];
		if (i >= n) {
			ll lans = t.del(pl[a]);
			lans = n - lans;
			ans[a].S = max(ans[a].S, lans);
//			cout << "ans for " << a + 1 << ' ' << lans << endl;
			ans[a].F = 1; 
		}
		pl[a] = i;
		t.add(pl[a]);
	}

	t.show(t.root);

	map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
		mp[pl[i]] = i;


	reverse(vec.begin(), vec.end());
	for (auto &i : vec)
		i = mp[i];

	for (ll i = 0; i < n; i++) {
		ans[vec[i]].S = max(ans[vec[i]].S, i + 1);
	}

	for (auto p : ans) {
		cout << p.F << ' ';
		cout << p.S << '\n';
	}
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
    	solve();


    return 0;
}