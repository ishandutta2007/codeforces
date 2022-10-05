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

int n;
vector<int> p, sz, f, q;
vector<vector<int>> e;
set<int> sf;
vector<bool> U;
vector<unordered_set<int>> ERASED;
bool viv = false;

void bad() {
	cout << "NO\n";
	exit(0);
}

inline bool ex(int u, int v) {
	return ERASED[u].find(v) == ERASED[u].end();
}

void DFS(int v, vector<int> &used) {
	used.push_back(v);
	U[v] = true;
	for (auto u : e[v]) {
		if (ex(u, v) && !U[u])
			DFS(u, used), p[u] = v;
	}
	q.push_back(v);
}

void cnt(int v) {
	sz[v] = 1;
	for (auto u : e[v])
		if (ex(u, v))
			sz[v] += sz[u];
}

void ER(int v) {	
	int u = p[v];
	ERASED[u].insert(v);
	ERASED[v].insert(u);
}

void work(int v, int st) {
	if (st <= 2)
		return;
	vector<int> used;
	q.clear();
	DFS(v, used);
	for (auto ver : used)
		U[ver] = false;
	for (auto i : used)
		sz[i] = 0;
	for (auto i : q)
		cnt(i);
	for (auto u : used) {
		if (sz[u] == f[st - 1]) {
			ER(u);
			work(u, st - 1);
			work(v, st - 2);
			return;
		}
		if (sz[u] == f[st - 2]) {
			ER(u);
			work(u, st - 2);
			work(v, st - 1);
			return;
		}
	}
	bad();
}

void solve() {
	f.resize(30);
	f[0] = f[1] = 1;
	for (int i = 2; i < f.size(); i++)
		f[i] = f[i - 1] + f[i - 2];
	for (auto i : f)
		sf.insert(i);

	cin >> n;
	e.resize(n);
	ERASED.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}	

	int st = 1;
	while (f[st] < n)
		st++;
	if (f[st] != n)
		bad();

	sz.resize(n, 0);
	p.resize(n, 0);
	U.resize(n, false);
	work(0, st);
	cout << "YES\n";
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