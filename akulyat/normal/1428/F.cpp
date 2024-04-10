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

ll n, k, ans;
vector<ll> v;
vector<pll> seg;
vector<ll> segl;
string s;
bool viv = false;
bool tviv = false;

struct Tree {
	int s = 1;
	int n = 0;
	ll my_null = 0; /// sum
	// ll my_null = inf; /// min
	vector<pll> t;
	vector<pll> seg;

	inline ll res(ll v1, ll v2) {
		return v1 + v2; /// sum
		// return min(v1, v2); /// min
	}

	// void cnt_seg() {
	// 	seg.resize(2 * s);
	// 	seg[1] = {0, s};
	// 	for (int i = 1; i < s; i++) {
	// 		int tm = seg[i].F + seg[i].S >> 1;
	// 		seg[2 * i] = {seg[i].F, tm};
	// 		seg[2 * i + 1] = {tm, seg[i].S};
	// 	}
	// }

	Tree(ll sz) {
		n = sz;
		s = 1;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {1, 0});
	}

	void build(ll sz) {
		n = sz;
		while (s < n)	
			s <<= 1;
		t.resize(2 * s, {my_null, 0});
	}


	void push(int v) {
		if (v >= s)
			return;
		if (t[v].F == 0)
			return;
		t[2 * v + 0] = t[v];
		t[2 * v + 1] = t[v];
	}



	// ll val(int l, int r, int v, int tl, int tr) {
	// 	if (r <= tl || tr <= l)
	// 		return my_null;
	// 	push(v);
	// 	if (l <= tl && tr <= r) 
	// 		return t[v].F;

	// 	int tm = tl + tr >> 1;
	// 	ll v1 = val(l, r, 2 * v, tl, tm);
	// 	ll v2 = val(l, r, 2 * v + 1, tm, tr);
	// 	upd(v);
	// 	return res(v1, v2);
	// }

	// ll val(int l, int r) { return val(l, r + 1, 1, 0, s); }

	// ll val(int pl) { return val(pl, pl + 1, 1, 0, s); }



	void add(int l, int r, int v, int tl, int tr, ll val) {
		if (viv && tviv) {
			cout << "add(" << l << ' ' << r << ' ' << v << ' ' << tl << ' ' << tr << ' ' << val << ")" << endl;
		}
		if (r <= tl || tr <= l)
			return;
		push(v);
		if (l <= tl && tr <= r)  {
			t[v].F = 1;
			t[v].S = val;
			return;
		}

		t[v].F = 0;
		int tm = tl + tr >> 1;
		add(l, r, 2 * v, tl, tm, val);
		add(l, r, 2 * v + 1, tm, tr, val);
		// upd(v);
	}

	void add(int l, int r, ll t) { add(l, r + 1, 1, 0, s, t); }

	int get(int l, int r, int v, int tl, int tr) {
		if (viv && tviv) {
			cout << "get(" << l << ' ' << r << " : " << v << ' ' << tl << ' ' << tr << ")" << endl;
		}
		if (t[v].F == 1) {
			return t[v].S;
		}
		int tm = tl + tr >> 1;
		if (r <= tm)
			return get(l, r, 2 * v, tl, tm);
		else
			return get(l, r, 2 * v + 1, tm, tr);
	}

	int get(int pl) {
		return get(pl, pl + 1, 1, 0, s);
	}

	void show() {
		for (ll i = 1; i < 2 * s ; i++) {
			cout << '\t' << '{' << t[i].F << ' ' << t[i].S << "} ";
			if ((i & (i + 1)) == 0)
				cout << endl;
		}
	}
};

void stpd() {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int mx = 0;
			int cnt = 0;
			for (int u = i; u <= j; u++) {
				if (s[u] == '1')
					cnt++;
				else
					cnt = 0;
				mx = max(mx, cnt);
			}
			ans += mx;
		}
	}
	cout << "stpd = " << ans << endl;
}

void solve() {
	cin >> n;
	cin >> s;

	s += '0';
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			cnt = 0;
		else {
			cnt++;
			if (s[i + 1] == '0') {
				seg.push_back({i + 1 - cnt, i + 1});
				segl.push_back(cnt);				
			}
		}
	}
	if (viv) {
		for (auto p : seg)
			cout << p.F << ' ' << p.S << endl;
	}
	k = seg.size();
	vector<int> pref, suf;	


	Tree t1(n + 1);
	for (int i = 0; i < k; i++) {
		ll len = segl[i];
		ll prev = t1.get(len) - 1;
		pref.push_back(prev);

		t1.add(0, len, i + 1);
	}

	Tree t2(n + 1);
	for (int i = k - 1; i >= 0; i--) {
		ll len = segl[i];
		ll nxt = t2.get(len + 1) - 1;
		suf.push_back(nxt);

		t2.add(0, len, i + 1);
	}
	reverse(suf.begin(), suf.end());

	if (viv) {
		t1.show();
		t2.show();
	}

	for (int i = 0; i < k; i++) {
		ll len = segl[i];
		ll my_l = seg[i].F;
		ll my_r = seg[i].S - 1;
		ll mini_l = 0;
		ll maxi_r = n - 1;
		if (pref[i] != -1) {
			ll pl = pref[i];
			mini_l = seg[pl].S - (len - 1);
		}
		if (suf[i] != -1) {
			ll pl = suf[i];
			maxi_r = seg[pl].F - 1 +  (len);
		}
		ll lans = (my_l - mini_l + 1) * (maxi_r - my_r + 1);
		lans *= len;
		if (viv) {
			cout << "i : " << my_l << ' ' << my_r << " | " << mini_l << ' ' << maxi_r << endl;
			cout << "\t\t add " << lans << endl;
		}
		ans += lans;
	}
	if (viv)
		cout << ans << endl;


	Tree t3(n + 1);
	for (int i = 0; i < k; i++) {
		ll len = segl[i];
		ll my_l = seg[i].F;
		ll my_r = seg[i].S - 1;
		for (int r = my_l; r < my_r; r++) {
			ll mini_l = 0;
			ll l_len = r - my_l + 1;
			ll prev = t3.get(l_len) - 1;
			if (prev != -1) {
				mini_l = seg[prev].S - (l_len - 1);				
			}
			ll lans = (my_l - mini_l + 1);
			lans *= l_len;
			ans += lans;
			if (viv) {
				cout << "by " << my_l << ' ' << r << " add " << lans << endl;
			}
		}
		t3.add(0, len, i + 1);
	}

	Tree t4(n + 1);
	for (int i = k - 1; i >= 0; i--) {
		ll len = segl[i];
		ll my_l = seg[i].F;
		ll my_r = seg[i].S - 1;
		for (int l = my_r; l > my_l; l--) {
			ll maxi_r = n - 1;
			ll l_len = (my_r - l) + 1;
			ll nxt = t4.get(l_len + 1) - 1;
			if (nxt != -1) {
				maxi_r = seg[nxt].F - 1 + (l_len);				
			}
			ll lans = (maxi_r - my_r + 1);
			lans *= l_len;
			ans += lans;
			if (viv) {
				cout << "by " << l << ' ' << my_r << " add " << lans << endl;
			}
		}
		t4.add(0, len, i + 1);
	}

	for (int i = 0; i < k; i++) {
		ll len = segl[i];
		if (len >= 3) {
			len -= 2;
			for (ll l = 1; l <= len; l++) {
				ll lans = ((l) * (l + 1)) / 2;		
				ans += lans;
				if (viv)
					cout << "add " << lans << " inside " << l << endl;
			}
		}
	}
	if (viv) {
		stpd();
	}
	cout << ans << endl;
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