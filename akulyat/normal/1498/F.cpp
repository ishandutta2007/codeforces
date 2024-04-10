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

ll n, k;
vector<ll> val, ans, d;
vector<vector<int>> e;
vector<vector<ll>> subt;
bool viv = false;



void DFS(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v]) {
		if (d[u] == -1) {
			DFS(u, c + 1);
			for (int j = 0; j < 2 * k; j++) {
				subt[v][j] ^= subt[u][j];
			}
		}
	}
	subt[v][d[v] % (2 * k)] ^= val[v];
	if (viv) {
		cout << "\tsubt[" << v << "] = ";
		for (auto i : subt[v])
			cout << i << ' ';
		cout << endl;
	}
}

void work(int v, vector<ll> mask) {
	if (viv) {
		cout << "work(" << v << ": ";
		for (auto i : mask)
			cout << i << " ";
		cout << ")" << endl;
	}
	ll res = 0;
	for (int j = d[v] + k; j < d[v] + 2 * k; j++)
		res ^= mask[j % (2 * k)];
	ans[v] = (res != 0);

	for (auto u : e[v])
		if (d[u] > d[v]) {
			for (int j = 0; j < 2 * k; j++)
				mask[j] ^= subt[u][j];

			vector<ll> wmask = subt[u];
			for (int j = 0; j < 2 * k; j++)
				wmask[(j + 2 * k + 2) % (2 * k)] ^= mask[j];
			work(u, wmask);

			for (int j = 0; j < 2 * k; j++)
				mask[j] ^= subt[u][j];
		}
}

void solve() {
	cin >> n >> k;
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	val.resize(n);
	for (auto &i : val)
		cin >> i;
	d.resize(n, -1);
	subt.resize(n, vector<ll>(2 * k, 0));
	DFS(0);

	ans.resize(n, -1);
	work(0, subt[0]);
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
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