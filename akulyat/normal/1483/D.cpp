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

ll n, q, m;
vector<vector<pii>> e;
vector<vector<ll>> W;
vector<vector<pll>> FR;
vector<vector<int>> t;
vector<int> best;
bool viv = false;

void read() {
	cin >> n >> m;
	e.resize(n);
	W.resize(n, vector<ll>(n, inf));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
		W[a][b] = W[b][a] = c;
	}	
	cin >> q;
	t.resize(q);
	best.resize(n, n);
	FR.resize(n, vector<pll>(n, {-inf, 0}));
	for (auto &vec : t) {
		vec.resize(3);
		for (auto &i : vec)
			cin >> i;
		vec[0]--;
		vec[1]--;	
		FR[vec[0]][vec[1]] = {vec[2], vec[1]};
		FR[vec[1]][vec[0]] = {vec[2], vec[0]};
	}
	if (viv) {
		// cout << "SORT :" << endl;
		for (int i = 0; i < n; i++) {
			cout << i << " - ";
			for (auto p : FR[i]) {
				cout << p.F << ' ' << p.S << "; ";
			}
			cout << endl;
		}
		cout << endl;		
	}
}

vector<vector<ll>> d;
bool good[610][610];

void all_d() {
	d.resize(n, vector<ll>(n, inf));
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			d[u][v] = W[u][v];
	for (int i = 0; i < n; i++)
		d[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
	if (viv) {
		cout << "dist" << endl;
		for (auto vec : d) {
			for (auto dd : vec)
				cout << dd << '\t';
			cout << endl;
		}
		cout << endl;
	}
}

void chmod(int v, int cf) {
	for (int i = 0; i < n; i++) {
		for (auto &p : FR[i]) {
			p.F += d[v][p.S] * cf;
		}
		auto pp = FR[i][0];
		for (auto pr : FR[i])
			pp = max(pp, pr);
		best[i] = pp.S;
		// sort(fr[i].rbegin(), fr[i].rend());
	}
	if (cf == -1 && viv) {
		cout << "sort for " << v << ":" << endl;
		for (int i = 0; i < n; i++) {
			cout << i << " - ";
			for (auto p : FR[i]) {
				if (p.F >= -mod)
					cout << p.F << ' ' << p.S << "; ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

set<pii> ans;

void work(int v) {
	chmod(v, -1);
	for (auto p : e[v]) {
		int u = p.F;
		ll len = p.S;
		for (int p = 0; p < n; p++) {
			int t = best[p];
			if (viv)
				cout << "\t" << v << ' ' << u << ' ' << p << ' ' << t << endl;
			if (d[p][u] + len <= FR[p][t].F) {
				good[u][v] = true;
			}	
		}
	}
	chmod(v, 1);
}

void solve() {
	read();
	all_d();
	for (int i = 0; i < n; i++) 
		work(i);

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += good[i][j];
	cout << ans / 2;
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