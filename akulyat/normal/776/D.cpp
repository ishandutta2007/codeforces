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

ll n, m;
vector<ll> v;
vector<vector<ll>> e, on;
vector<vector<pll>> ed;
vector<ll> col;
bool viv = false;

void bad() {
	cout << "NO\n";
	exit(0);
}

void good() {
	cout << "YES\n";
	exit(0);
}

void DFS(int v, int c) {
	col[v] = c;
	for (auto p : ed[v]) {
		int s = p.F;
		if (col[s] == -1)
			DFS(s, c ^ p.S);
		else 
			if (col[s] != c ^ p.S)
				bad();
	}
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	e.resize(m);
	on.resize(n);
	int cnt = 0;
	for (auto &l : e) {
		ll k;
		cin >> k;
		l.resize(k);
		for (auto &i : l) {
			cin >> i, i--;
			on[i].push_back(cnt);
		}
		cnt++;
	}

	ed.resize(m);
	for (int i = 0; i < n; i++) {
		int val = v[i] ^ 1;
		int a = on[i][0];
		int b = on[i][1];
		ed[a].push_back({b, val});
		ed[b].push_back({a, val});
	}
	col.resize(m, -1);
	for (int i = 0; i < m; i++)
		if (col[i] == -1)
			DFS(i, 0);
	good();
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