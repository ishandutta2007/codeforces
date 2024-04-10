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
 
int n;
ll ans;
vector<vector<ll>> reb;
vector<int> col, p, q, sz;
vector<vector<int>> pp;
ll dp[3 * kk + 10][3 * kk + 10];
bool viv = false;

void DFS(ll v, ll c) {
	col[v] = c;
	for (auto s : reb[v]) 
		if (col[s] == -1)
			DFS(s, c + 1), p[s] = v;
	q.push_back(v);
}

void counter(ll v) {
	for (auto s : reb[v])
		if (col[s] > col[v])
			sz[v] += sz[s];
}

void prepare() {
	pp.resize(15);
	for (auto &l : pp)
		l.resize(n);
	pp[0] = p;
	for (int lev = 1; lev < 15; lev++) {
		for (int v = 0; v < n; v++)
			pp[lev][v] = pp[lev - 1][pp[lev - 1][v]];
	}
}

int LA(ll v, ll up) {
	for (ll i = 0; i < 15; i++) {
		if (up & 1)
			v = pp[i][v];
		up >>= 1;
	}
	return v;
}

int LCA(ll a, ll b) {
	if (col[a] > col[b])
		a = LA(a, col[a] - col[b]);
	if (col[a] < col[b])
		b = LA(b, col[b] - col[a]);
	if (a == b)
		return a;
	for (ll i = 14; i >= 0; i--) {
		if (pp[i][a] != pp[i][b])
			a = pp[i][a], b = pp[i][b];
	}
	return p[a];
} 

int dist(ll a, ll b) {
	return col[a] + col[b] - 2 * col[LCA(a, b)];
}

ll what(ll v1, ll v2) {
	if (v1 < v2)
		swap(v1, v2);
	return dp[v1][v2];
}

void check_par(ll v1, ll v2) {
	int pv2 = p[v2];
	int pv1 = LA(v2, dist(v1, v2) - 1);

	ll lans = 0;
	lans += (n - sz[pv1]) * sz[v2];
	lans += max(what(v1, pv2), what(pv1, v2));

	if (v1 < v2)
		swap(v1, v2);
	dp[v1][v2] = lans;
	ans = max(ans, lans);
}

void check(ll v1, ll v2) {
	if (col[v1] > col[v2])
		swap(v1, v2);
	if (LCA(v1, v2) == v1) {
		check_par(v1, v2);
		return;
	}

	int pv1 = p[v1];
	int pv2 = p[v2];

	ll lans = 0;
	lans += sz[v1] * sz[v2];
	lans += max(what(v1, pv2), what(pv1, v2));

	if (v1 < v2)
		swap(v1, v2);
	dp[v1][v2] = lans;
	ans = max(ans, lans);
}

void solve() {
	cin >> n;
	reb.resize(n);
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		reb[a].push_back(b);
		reb[b].push_back(a);
	}
	col.resize(n, -1);
	p.resize(n, 0);
	sz.resize(n, 1);
	DFS(0, 0);
	prepare();
	for (auto i : q)
		counter(i);

	vector<pair<int, pair<int, int>>> all;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i != j)
				all.push_back({dist(i, j), {i, j}});
	}
	sort(all.begin(), all.end());

	for (auto it : all) {
		auto pr = it.S;
		check(pr.F, pr.S);
	}

	cout << ans << endl;
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