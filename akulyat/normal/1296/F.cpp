#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
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
 
ll n, m, k;
vector<ll> col, p, ans;
vector<pll> e;
vector<vector<ll>> reb;
vector<pair<pll, ll>> qr;
bool viv = false;

void DFS(ll v, ll c) {
	col[v] = c;
	for (auto s : reb[v])
		if (col[s] == -1) {
			p[s] = v;
			DFS(s, c + 1);
		}
}

ll LCA(ll v1, ll v2) {
	while (col[v1] > col[v2])
		v1 = p[v1];
	while (col[v1] < col[v2])
		v2 = p[v2];
	while (v1 != v2)
		v1 = p[v1], v2 = p[v2];
	return v1;
}

void add(ll k, ll pr, ll nc) {
	while (k != pr)
		ans[k] = max(ans[k], nc), k = p[k];
}

bool check(pair<pll, ll> qr) {
	ll v1 = qr.F.F;
	ll v2 = qr.F.S;
	ll l = LCA(v1, v2);
	ll res = inf;
	while (v1 != l) {
		res = min(ans[v1], res);
		v1 = p[v1];
	}
	while (v2 != l) {
		res = min(ans[v2], res);
		v2 = p[v2];
	}
	if (res == qr.S)
		return true;
	return false;
}

void present(ll a, ll b) {
	if (p[b] == a)
		swap(a, b);
	cout << ans[a] << ' ';
}

void solve() {
	ll n;
	cin >> n;
	reb.resize(n);	
	for (ll i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		reb[a].push_back(b);
		reb[b].push_back(a);
		e.push_back({a, b});
	}
	col.resize(n, -1);
	p.resize(n, 0);
	DFS(0, 0);
	ll q;
	cin >> q;
	ans.resize(n, 1);
	for (ll i = 0; i < q; i++) {
		ll a, b, nc;
		cin >> a >> b >> nc;
		a--, b--;
		qr.push_back({{a, b}, nc});
		ll l = LCA(a, b);
		add(a, l, nc);
		add(b, l, nc);
	}

	bool good = true;
	for (auto i: qr)
		if (!check(i))
			good = false;
	if (good) {
		for (auto i : e)
			present(i.F, i.S);
	}
	else
		cout << "-1";
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}