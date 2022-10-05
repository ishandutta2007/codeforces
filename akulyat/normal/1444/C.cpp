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

ll n, m, k;
vector<int> g, d;
vector<vector<int>> e;

int all_cool;
vector<bool> cool;
// vector<vector<int>> inc;
vector<vector<int>> in_g;

vector<vector<int>> e2;
vector<int> col2;
ll ans;

bool viv = false;

void read() {
	cin >> n >> m >> k;
	g.resize(n);
	for (auto &i : g)
		cin >> i, i--;

	in_g.resize(k);
	for (int i = 0; i < n; i++)
		in_g[g[i]].push_back(i);

	e.resize(n);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
}

void DFS(int v, int c) {
	if (viv)
		cout << "DFS(" << v << ", " << c << ")" << endl;
	d[v] = c;
	for (auto u : e[v]) {
		if (g[u] == g[v] && d[u] == -1)
			DFS(u, c ^ 1);
		if (d[u] == d[v])
			cool[g[v]] = false;
	}
}

void work() {
	cool.resize(k, true);
	// inc.resize(k);
	d.resize(n, -1);
	int c = 0;
	for (int i = 0; i < n; i++)
		if (d[i] == -1) {
			// inc[g[i]].push_back(c);
			DFS(i, c), c += 2;
		}

 	if (viv) {
 		cout << "d = ";
		for (auto i : d)
			cout << i << ' ';
		cout << endl;
 		cout << "cool = ";
		for (auto i : cool)
			cout << i << ' ';
		cout << endl;
	}

	e2.resize(c);
	for (int i = 0; i < c; i++)
		e2[i].push_back(i ^ 1);
	col2.resize(c, -1);
}

void DFS2(int v, int c, bool &no_cycle) {
	col2[v] = c;
	for (auto u : e2[v]) {
		if (col2[u] == -1) 
			DFS2(u, c ^ 1, no_cycle);
		else
			if (col2[u] == col2[v])
				no_cycle = false;
	}
}

void counter_2(int gr, int gr2, const vector<pii> &edges) {
	for (auto pr : edges) {
		e2[pr.F].push_back(pr.S);
		e2[pr.S].push_back(pr.F);
	}

	if (viv) {
		for (int i = 0; i < e2.size(); i++) {
			cout << "\tfrom " << i << ": ";
			for (auto v : e2[i])
				cout << v << ", ";
			cout << endl;
		}
		cout << "\tcol2 = ";
		for (auto i : col2)
			cout << i << ' ';
		cout << endl;
	}
	// for (auto i : col2)
	// 	assert(i == -1);


	bool no_cycle = true;
	for (auto pr : edges)
		if (col2[pr.F] == -1)
			DFS2(pr.F, 0, no_cycle);

	ans += no_cycle;
	if (viv) {
		cout << "Work " << gr << ' ' << gr2 << " see " << no_cycle << endl;
		cout << endl;
	}

	for (auto pr : edges) {
		col2[pr.F] = -1;
		col2[pr.S] = -1;
		col2[pr.F ^ 1] = -1;
		col2[pr.S ^ 1] = -1;
		e2[pr.F].pop_back();
		e2[pr.S].pop_back();
	}

}

void counter(int gr) {
	unordered_map<int, vector<pii>> mp;
	for (auto v : in_g[gr]) {
		for (auto u : e[v]) {
			if (g[u] > g[v])
				mp[g[u]].push_back({d[v], d[u]});
		}
	}

	int left_cool = all_cool;
	left_cool--;

	for (auto p : mp) {
		int gr2 = p.F;
		if (cool[gr2]) {
			left_cool--;
			counter_2(gr, gr2, p.S);
		}
	}
	if (viv) {
		cout << "Add " << left_cool << " wo edges " << endl;
	}
	ans += left_cool;
}

void count() {
	for (auto i : cool)
		all_cool += i;
	for (int i = 0; i < k; i++)
		if (cool[i]) {			
			counter(i);
			all_cool--;
		}
	// cout << ans / 2 << endl;	
	cout << ans << endl;	
}

void solve() {
	read();
	work();
	count();
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