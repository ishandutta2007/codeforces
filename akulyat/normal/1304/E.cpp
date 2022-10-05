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
 
ll n;
vector<ll> col, p;
vector<vector<ll>> pp;
vector<vector<ll>> reb;
bool viv = false;

void DFS(ll v, ll c) {
	col[v] = c;
	for (auto s : reb[v])
		if (col[s] == -1)
			DFS(s, c + 1), p[s] = v;
}

void prepare() {
	pp.resize(20);
	pp[0] = p;
	for (ll lev = 1; lev < 20; lev++) {
		pp[lev].resize(n);
		for (ll i = 0; i < n; i++)
			pp[lev][i] = pp[lev - 1][pp[lev - 1][i]];
	}
}

ll LA(ll v1, ll ups) {
	for (ll i = 0; i < 20; i++) {
		if (ups & 1)
			v1 = pp[i][v1];
		ups >>= 1;
	}
	return v1;
}	

ll LCA(ll v1, ll v2) {
	if (col[v1] < col[v2])
		v2 = LA(v2, col[v2] - col[v1]);
	if (col[v1] > col[v2])
		v1 = LA(v1, col[v1] - col[v2]);
	if (v1 == v2)
		return v1;

	for (ll i = 19; i >= 0; i--) 
		if (pp[i][v1] != pp[i][v2])
			v1 = pp[i][v1], v2 = pp[i][v2];

	v1 = p[v1];
	return v1;
}

ll dist(ll v1, ll v2) {
	ll l = LCA(v1, v2);
	ll res = col[v1] + col[v2] - 2 * col[l];
	return res;
}

bool able(ll dist, ll k) {
	if (dist > k)
		return false;
	if (abs(dist - k) & 1)
		return false;
	return true;
}

bool work() {
	ll x, y, a, b, k;
	cin >> x >> y >> a >> b >> k;
	x--, y--, a--, b--;


	if (able(dist(a, b), k))
		return true;
	if (able(dist(a, x) + dist(b, y) + 1, k))
		return true;
	if (able(dist(a, y) + dist(b, x) + 1, k))
		return true;
	return false;
}

void solve() {
	cin >> n;
	reb.resize(n);
	for (ll i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		reb[a].push_back(b);
		reb[b].push_back(a);
	}
	col.resize(n, -1);
	p.resize(n, 0);
	DFS(0, 0);
	prepare();


	ll q;
	cin >> q;
	while (q--) {
		if (work())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
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