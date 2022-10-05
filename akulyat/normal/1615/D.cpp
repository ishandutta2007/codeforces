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
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


struct edge {
	int u, v, w;
};

bool viv = false;
int n, m;
vector<vector<pii>> e; 
vector<edge> ed; 
vector<int> col;

int cnt(int w) {
	int val = 0;
	while (w) {
		val ^= (w & 1);
		w >>= 1;		
	}
	return val;
}

bool DFS(int v, int c = 0) {
	if (viv)
		cout << "DFS(" << v << ", " << c << ")" << endl;
	if (col[v] != -1) {
		if (col[v] != c)
			return false;
		return true;
	}
	col[v] = c;
	for (auto [u, w]: e[v]) {
		if (!DFS(u, c ^ w))
			return false;
	}
	return true;
} 

void solve() {
	cin >> n >> m;
	e.assign(n, {});
	ed.clear();
	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		if (w != -1) {
			e[a].push_back({b, cnt(w)});
			e[b].push_back({a, cnt(w)});
			if (viv)
				cout << "see " << a << ' ' << b << ' ' << cnt(w) << endl;
		}
		ed.push_back({a, b, w});
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;		
		a--, b--;
		e[a].push_back({b, w});
		e[b].push_back({a, w});
		if (viv)
			cout << "see " << a << ' ' << b << ' ' << cnt(w) << endl;
	}

	bool nice = true;
	col.assign(n, -1);
	for (int i = 0; i < n; i++)
		if (col[i] == -1)
			nice = nice & DFS(i);
	if (!nice) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto [u, v, w] : ed) {
		if (w == -1)
			w = (col[u] != col[v]);
		cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--) {
		solve();
		if (viv)
			cout << endl;
	}

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}