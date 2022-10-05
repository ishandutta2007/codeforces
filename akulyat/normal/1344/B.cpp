#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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

ll n, m;
bool viv = false;
vector<vector<ll>> f;
vector<vector<ll>> e;
vector<ll> col;

void check(ll v, ll u) {
	if (!f[v / m][v % m])
		return;
	if (!f[u / m][u % m])
		return;
	e[v].push_back(u);
	e[u].push_back(v);
}


void DFS(ll v, ll c) {
	col[v] = c;
	for (auto s : e[v])
		if (col[s] == -1)
			DFS(s, c + 1);
}

void bad() {
	cout << "-1";
	exit(0);
}

void check1() {
	vector<ll> a, b;
	for (int i = 0; i < n; i++) {
		ll c = 0;
		for (int j = 0; j < m; j++) {
			if (f[i][j] && (j == 0 || !f[i][j - 1]))
				c++;
		}
		if (c > 1)
			bad();
		if (c == 0)
			a.push_back(i);
	}
	for (int j = 0; j < m; j++) {
		ll c = 0;
		for (int i = 0; i < n; i++) {
			if (f[i][j] && (i == 0 || !f[i - 1][j]))
				c++;
		}
		if (c > 1)
			bad();
		if (c == 0)
			b.push_back(j);
	}
	if ((a.size() > 0) ^ (b.size() > 0))
		bad();
}

void solve() {
	cin >> n >> m;
	f.resize(n);
	e.resize(n * m);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			f[i].push_back((s[j] == '#'));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)  {
			if (j < m - 1)
				check(i * m + j, i * m + j + 1);
			if (i < n - 1)
				check(i * m + j, i * m + j + m);
		}
	}

	ll ans = 0;
	col.resize(n * m, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[i][j] && col[i * m + j] == -1)
				DFS(i * m + j, 0), ans++;
		}		
	}

	check1();
	cout << ans << endl;
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