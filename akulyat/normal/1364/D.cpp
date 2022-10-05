#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n, m, k;
vector<vector<ll>> e;
vector<ll> d, c;
bool viv = false;

void DFS(ll v, ll cl, vector<ll> &p) {
	d[v] = cl;
	p.push_back(v);
	for (auto u : e[v]) {
		if (d[u] == -1) {
			DFS(u, cl + 1, p);
		} else {
			if (c.empty() && d[u] + 1 < d[v]) {
				auto pp = p;
				if (viv)
					cout << "Want " << v << ' ' << u << endl;
				vector<ll> cc;
				while(pp.back() != u)
					cc.push_back(pp.back()), pp.pop_back();
				cc.push_back(u);
				c = cc;
			}
		}
	}
	p.pop_back();
}

void work(vector<ll> c) {
	if (viv) {
		cout << "Work: ";
		for (auto i : c) 
			cout << i << ' ';
		cout << endl;
	}
	n = c.size();
	unordered_map<ll, ll> h;
	for (int i = 0; i < n; i++)
		h[c[i]] = i;

	for (int i = 0; i < n; i++) 
		c.push_back(c[i]);

	for (int i = 0; i < n; i++) {
		for (auto u : e[c[i]]) 
			if (h.count(u) && abs(h[u] - h[c[i]]) != 1 && abs(h[u] - h[c[i]]) != n - 1) {
				if (viv) {
					cout << "Edge: " << c[i] << ' ' << u << endl;
				}


				int j = i;
				while (c[j] != u)
					j++;

				vector<ll> nc;
				if (j - i < i + n - j) {
					for (int k = i; k <= j; k++)
						nc.push_back(c[k]);
				} else {
					for (int k = j; k <= n + i; k++)
						nc.push_back(c[k]);					
				}
				work(nc);
				return;
			}
	}
	for (int i = 0; i < n; i++)
		c.pop_back();
	if (c.size() <= k) {
		cout << 2 << '\n';
		cout << c.size() << '\n';
		for (auto i : c)
			cout << i + 1 << ' ';
		cout << '\n';
		return;
	}
	cout << 1 << '\n';
	vector<ll> ans;
	for (int i = 0; i < n - 1; i += 2) {
		ans.push_back(c[i] + 1);
	}
	while (ans.size() > (k + 1) / 2)
		ans.pop_back();
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}

void solve() {
	cin >> n >> m >> k;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d.resize(n, -1);
	vector<ll> p;
	DFS(0, 0, p);
	if (viv) {
		cout << "DFS c: ";
		for (auto i : c)
			cout << i << ' ';
		cout << endl;
	}
	if (c.empty()) {
		vector<ll> a, b;
		for (int i = 0; i < n; i++) {
			if (d[i] & 1)
				a.push_back(i);
			else
				b.push_back(i);
		}
		if (a.size() < b.size())
			swap(a, b);
		cout << 1 << '\n';
		while (a.size() > (k + 1) / 2)
			a.pop_back();
		for (auto i : a)
			cout << i + 1 << ' ';
		cout << '\n';
		return;
	}
	work(c);
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}