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
const long long inf = ml * ml * ml + 7;
 
ll n, st, ans;
vector<ll> m;
vector<vector<ll>> who, tp;
vector<unordered_set<ll>> kids;
bool viv = false;
string s;

vector<ll> p, sz;
vector<ll> col;


void build() {
	p.resize(st);
	tp.resize(st);
	sz.resize(st, 1);
	kids.resize(st);
	for (ll i = 0; i < st; i++) {
		p[i] = i;
		tp[i].resize(4, 0);
		kids[i].insert(i);
		tp[i][0] = 1;
	}
	col.resize(st, 0);
}

ll par(ll v) {
	if (p[v] != v)
		return p[v] = par(p[v]);
	return v;
}

void make(ll v, ll t) {
	if (col[v] > 1)
		return;

	ll vp = par(v);
	ans -= min(tp[vp][0], tp[vp][1]);
	ll c = col[v] ^ (t ^ 1);

	vector<ll> cnt(4, 0);

	for (auto v : kids[vp]) {
		if (col[v] == c)
			col[v] = 2;
		else
			col[v] = 3;
		cnt[col[v]]++;
	}
	tp[vp] = cnt;
	ans += tp[vp][3];
}

void connect(ll v1, ll v2, ll t) {
	ll vp1 = par(v1);
	ll vp2 = par(v2);
	if (vp1 == vp2)
		return;
	if (sz[vp1] < sz[vp2]) 
		swap(vp1, vp2), swap(v1, v2);

	ans -= tp[vp1][3];
	ans -= tp[vp2][3];
	ans -= min(tp[vp1][0], tp[vp1][1]);
	ans -= min(tp[vp2][0], tp[vp2][1]);

	if (tp[vp1][2] || tp[vp1][3]) {
		ll c = col[v1];
		if (!t)
			c ^= 1;
		vector<ll> will(4, 0);
		will[col[v2]] = c;
		will[col[v2] ^ 1] = c ^ 1;
		auto cnt = tp[vp1];
		for (auto i : kids[vp2])  {			
			col[i] = will[col[i]];
			cnt[col[i]]++;
		}
		tp[vp1] = cnt;
	} else {
		if (tp[vp2][2] || tp[vp2][3]) {
			ll c = col[v2];
			if (!t)
				c ^= 1;
			vector<ll> will(4, 0);
			will[col[v1]] = c;
			will[col[v1] ^ 1] = c ^ 1;
			auto cnt = tp[vp2];
			for (auto i : kids[vp1]) {
				col[i] = will[col[i]];
				cnt[col[i]]++;
			}
			tp[vp1] = cnt;
		} else {
			ll c = col[v1];
			if (t == 0)
				c ^= 1;
			vector<ll> will(4, 0);

			will[col[v2]] = c;
			will[col[v2] ^ 1] = c ^ 1;
			auto cnt = tp[vp1];
			for (auto i : kids[vp2])  {			
				col[i] = will[col[i]];
				cnt[col[i]]++;
			}
			tp[vp1] = cnt;
		}
	}
	ans += tp[vp1][3];
	ans += min(tp[vp1][0], tp[vp1][1]);
	sz[vp1] += sz[vp2];
	sz[vp2] = 0;
	p[vp2] = vp1;
	for (auto v : kids[vp2])
		kids[vp1].insert(v);

	kids[vp2].clear();
}

void solve() {
	cin >> n >> st;
	cin >> s;
	who.resize(n);
	for (ll i = 0; i < st; i++) {
		ll k;
		cin >> k;
		for (ll j = 0; j < k; j++) {
			ll a;
			cin >> a;
			a--;
			who[a].push_back(i);
		}
	}
	build();

	for (ll i = 0; i < n; i++) {
		if (who[i].size() == 1) {
			make(who[i][0], s[i] - '0');
		}
		if (who[i].size() == 2) {
			connect(who[i][0], who[i][1], s[i] - '0');
		}
		cout << ans << '\n';
	}
 
}


int main() {
  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}