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

ll n;
vector<vector<ll>> a, b;
vector<vector<pll>> e;
vector<ll> d;
bool viv = false;

bool DFS(int v, int c) {
	d[v] = c;
	// cout << "make " << v << ' ' << c << endl;
	for (auto p : e[v]) {
		int u = p.F;
		if (d[u] == -1)
			DFS(u, c ^ p.S);
		if (d[u] != d[v] ^ p.S)
			return false;
	}
	return true;
}

void solve() {
	cin >> n;
	a.assign(n, vector<ll>(n, 0));
	b.assign(n, vector<ll>(n, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			a[i][j] = (s[j] == '1');
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			b[i][j] = (s[j] == '1');
	}

	vector<ll> r(n, 0), c(n, 0);
	for (int i = 0; i < n; i++)
		if (a[0][i] != b[0][i])
			c[i] = 1;
	for (int i = 0; i < n; i++)
		if (a[i][0] != b[i][0])
			r[i] = c[0] ^ 1;
		else
			r[i] = c[0];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			a[i][j] ^= r[i];
			a[i][j] ^= c[j];
		}
	if (a == b)	
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}