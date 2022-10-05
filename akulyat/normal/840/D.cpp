#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

using namespace std;

#define F first
#define S second
typedef int   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = mod; 
const ll join = 5;
vector<vector<ll>> s;

ll n, q;
vector<ll> v, sl;
bool viv = false;

inline bool check(ll val, ll l, ll r, ll k);

struct Tree {
	ll n, s = 1;
	vector<vector<ll>> t;
	vector<pll> seg;
	Tree() {}

	void upd(ll v) {
		int l = 2 * v;
		int r = l + 1;
		seg[v].F = seg[l].F;
		seg[v].S = seg[r].S;
		int len = seg[v].S - seg[v].F;
		unordered_set<ll> add;
		for (auto i : t[l])	
			if (check(i, seg[v].F, seg[v].S - 1, 5))
				add.insert(i);
		for (auto i : t[r])	
			if (check(i, seg[v].F, seg[v].S - 1, 5))
				add.insert(i);
		for (auto i : add)
			t[v].push_back(i);
	}

	void build(vector<ll> v) {
		n = v.size();
		while (s < n)
			s <<= 1;
		t.resize(2 * s);
		seg.resize(2 * s);
		for (int i = 0; i < n; i++) {
			t[s + i].push_back(v[i]);
			seg[s + i] = {i, i + 1};
		}
		for (int i = n; i < s; i++) 
			seg[s + i] = {i, i + 1};
        if (viv)
            cout << "D" << endl;
		for (int i = s - 1; i > 0; i--) {
			upd(i);
		}
        if (viv)
            cout << "D" << endl;
	}

	ll split(ll l, ll r, ll v, ll tl, ll tr) {
		if (r <= tl || tr <= l)
			return mod;
		if (l <= tl && tr <= r) {
		    sl.push_back(v);
			return v;
		}
		ll tm = tl + tr >> 1;
		int sl1 = split(l, r, 2 * v, tl, tm);
		int sl2 = split(l, r, 2 * v + 1, tm, tr);
		return min(sl1, sl2);
	}

	ll split(ll l, ll r) {
		sl.clear();
		return split(l, r + 1, 1, 0, s);
	}
} t;

inline bool check(ll val, ll l, ll r, ll k) {
	ll cnt = 0;
	cnt += lower_bound(s[val].begin(), s[val].end(), r + 1) - s[val].begin();
	cnt -= lower_bound(s[val].begin(), s[val].end(), l) - s[val].begin();
	if (viv)
    	cout << "cnt = " << cnt << endl;
	if (cnt * k > r - l + 1)
		return true;
	return false;
}

void ask() {
	ll l, r, k;
	cin >> l >> r >> k;
	l--, r--;

	t.split(l, r);

	unordered_set<ll> to_check;	
	for (auto v : sl)
		for (auto p : t.t[v]) 
			to_check.insert(p);
	ll ans = mod;
	for (auto v : to_check)
		if (check(v, l, r, k))
			ans = min(ans, v);
	if (ans == mod)
		ans = -2;

	cout << ans + 1 << '\n';
}

void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	s.resize(n);
	for (int i = 0; i < n; i++) {
		s[v[i]].push_back(i);
	}
	if (viv)
    	cout << "B" << endl;
	t.build(v);
	if (viv)
    	cout << "B" << endl;
	while (q--)
		ask();
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}