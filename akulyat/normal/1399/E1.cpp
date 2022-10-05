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
			DFS(s.F, c + 1, sum + s.S), kids++;
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

ll get(ll w, ll sz) {
	return -(w - w / 2) * sz;
}

void solve() {
	cin >> n >> S;
	ans = 0;
	e.clear();
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
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

	multiset<pair<ll, pll>> ss;
	for (int v = 0; v < n; v++) {
		for (auto p : e[v]) {
			auto s = p.F;
			if (col[s] > col[v]) {
				ss.insert({get(p.S, sz[s]), {p.S, sz[s]}});
				if (viv)
					cout << "Edge: " << p.S << ' ' << sz[s] << endl;
			}
		}
	}
	ll res = 0;
	if (viv)			
		cout << "Start: " << ans << ' ' << S << endl;
	while (ans > S) {
		if (viv)
			cout << "See " << ans << endl;		
		auto p = *ss.begin();
		if (viv)
			cout << "Use: " << p.F << ": " << p.S.F << ' ' << p.S.S << endl;

		ss.erase(ss.begin());
		ans += p.F;
		ss.insert({get(p.S.F / 2, p.S.S), {p.S.F / 2, p.S.S}});
		res++;
	}
	if (viv)
		cout << "\t\t_____ ";
	cout << res << '\n';
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