#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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

ll n, m, a, b, c;
bool viv = false;
vector<ll> v;
vector<vector<ll>> e;

vector<ll> BFS(ll sv) {
	vector<ll> d(n, inf);
	d[sv] = 0;
	vector<ll> nx;
	nx.push_back(sv);
	ll st = 0;
	while (st != nx.size()) {
		ll v = nx[st];
		st++;
		for (auto s : e[v])
			if (d[s] > d[v] + 1) {
				d[s] = d[v] + 1;
				nx.push_back(s);
			}
	}
	if (viv) {
		for (auto i : d)
			cout << i << ' ';
		cout << endl;
	}

	return d;
}

void solve() {
	cin >> n >> m >> a >> b >> c;
	a--, b--, c--;
	e.clear();
	e.resize(n);
	v.clear();
	v.resize(m);
	for (auto &i : v)
		cin >> i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	auto pa = BFS(a);
	auto pb = BFS(b);
	auto pc = BFS(c);

	vector<ll> p;
	p.push_back(0);
	sort(v.begin(), v.end());
	while (v.size() < 3 * (n + m))
		v.push_back(10 * mod);
	for (auto i : v)
		p.push_back(p.back() + i);

	ll ans = inf;
	for (int i = 0; i < n; i++) {
		ll da = pa[i];
		ll db = pb[i];
		ll dc = pc[i];
		ll lres = p[da + db + dc];
		lres += p[db];
		ans = min(lres, ans);
	}
	cout << ans << '\n';
	if (viv)
		cout << endl;
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}