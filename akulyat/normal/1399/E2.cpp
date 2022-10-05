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

ll n, S, ans;
vector<ll> v, col, sz, q;
vector<vector<pll>> e;
bool viv = false;

void DFS(ll v, ll c = 0, ll sum = 0) {
	if (viv)
		cout << v << ' ' << c << ' ' << sum << endl;
	col[v] = c;
	int kids = 0;
	for (auto s : e[v])
		if (col[s.F] == -1)
			DFS(s.F, c + 1, sum + abs(s.S)), kids++;
	if (kids == 0)
		ans += sum;
	q.push_back(v);
}

void work() {
	if (viv) {
		cout << "Work: ";
		for (auto i : q)
			cout << i << ' ';
		cout << endl;
	}
	for (auto v : q) {
		ll lsz = 0;
		for (auto p : e[v]) {
			auto s = p.F;
			if (col[s] > col[v]) 
				lsz += sz[s];
		}
		if (lsz == 0)
			lsz = 1;
		sz[v] = lsz;		
	}
}

pll get(ll w, ll sz) {
	ll v1 = -(abs(w) - abs(w) / 2) * sz;
	if (w < 0)
		v1 += -(abs(w) / 2 - (abs(w) / 2) / 2) * sz;
	ll v2 = -(abs(w) - abs(w) / 2) * sz;
	return {v1, v2};
}

void solve() {
	cin >> n >> S;
	ans = 0;
	e.clear();
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		ll c, d;
		cin >> a >> b >> c >> d;
		d *= 2;
		d -= 3;
		c *= d;
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	col.clear();
	col.resize(n, -1);
	sz.clear();
	sz.resize(n, -1);
	q.clear();	
	DFS(0);
	work();	

	vector<ll> one, two;
	for (int v = 0; v < n; v++) {
		for (auto p : e[v]) {
			auto s = p.F;
			if (col[s] > col[v]) {
				if (p.S > 0) {
					auto z = abs(p.S);
					while (z)
						two.push_back((z - z / 2) * sz[s]), z /= 2;
				} else {
					auto z = abs(p.S);
					while (z)
						one.push_back((z - z / 2) * sz[s]), z /= 2;
				}
			}
		}
	}
	ll need = ans - S;
	sort(one.rbegin(), one.rend());
	sort(two.rbegin(), two.rend());
	vector<ll> po(1, 0), pt(1, 0);
	for (auto i : one)
		po.push_back(po.back() + i);
	for (auto i : two)
		pt.push_back(pt.back() + i);

	ll ans = inf;
	for (int i = 0; i <= one.size(); i++) {
		ll have = po[i];
		ll sneed = need - have;
		auto p = lower_bound(pt.begin(), pt.end(), sneed) - pt.begin();
		ll lans = i + 2 * p;
		if (p <= two.size())
			ans = min(ans, lans);
	}
	cout << ans << '\n';
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