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


ll n, q;
vector<vector<ll>> e, pp;
vector<ll> v, d, p;
bool viv = false;

void prepare() {
	pp.push_back(p);
	for (int i = 1; i < 21; i++) {
		pp.push_back({});
		for (int v = 0; v < n; v++)
			pp[i].push_back(pp[i - 1][pp[i - 1][v]]);
	}
}

ll LA(ll v, ll lv) {
	for (int i = 0; i < 20; i++) {
		if (lv & 1)
			v = pp[i][v];
		lv >>= 1;
	}
	return v;
}

ll LCA(ll v1, ll v2) {
	if (d[v1] > d[v2])
		v1 = LA(v1, d[v1] - d[v2]);
	if (d[v2] > d[v1])
		v2 = LA(v2, d[v2] - d[v1]);
	if (v1 == v2)
		return v1;
	return -1;
}

void qr() {
	ll k;
	cin >> k;
	v.clear();
	v.resize(k);
	for (auto &i : v)
		cin >> i, i--, i = p[i];

	ll deep = v[0];
	for (auto vr : v)
		if (d[deep] < d[vr])
			deep = vr;

//	viv = true;
	if (viv) {
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
		cout << deep << endl;
		cout << endl;
	}

	for (auto vr : v)
		if (LCA(deep, vr) != vr) {
			if (viv)
				cout << deep << ' ' << vr << ' ' << LCA(deep, vr) << endl;
			cout << "NO\n";
			return;
		}

	cout << "YES\n";
}

void DFS(ll v, ll c) {
	d[v] = c;
	for (auto s : e[v])
		if (d[s] == -1)
			DFS(s, c + 1), p[s] = v;
}

void solve() {
	cin >> n >> q;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	p.resize(n, 0);
	d.resize(n, -1);
	DFS(0, 0);
	prepare();

	while (q--)
		qr();
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}