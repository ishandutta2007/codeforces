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

ll n, m, t;
bool viv = false;
vector<ll> v, tin, tout;
vector<vector<ll>> e, re;
vector<pll> tos;
vector<pair<bool, bool>> can;

void DFS(ll v) {
	tin[v] = t;
	t++;
	for (auto s : e[v])
		if (tin[s] == -1)
			DFS(s);
	tout[v] = t;
	t++;
}

void DFS1(ll v) {
	can[v].F = false;
	for (auto s : e[v])
		if (can[s].F)
			DFS1(s);
}

void DFS2(ll v) {
	can[v].S = false;
	for (auto s : re[v])
		if (can[s].S)
			DFS2(s);
}



void bad() {
	cout << -1 << endl;
	exit(0);
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	re.resize(n);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);	
		re[b].push_back(a);	
	}
	tin.resize(n, -1);
	tout.resize(n, -1);
	t = 0;
	for (int i = 0; i < n; i++)
		if (tin[i] == -1)
			DFS(i);
	if (viv)
		cout << 1 << endl;

	for (int i = 0; i < n; i++)
		tos.push_back({tout[i], i});
	sort(tos.begin(), tos.end());

	if (viv)
		cout << 1 << endl;
	
	for (int i = 0; i < n; i++) {
		for (auto s : e[i])
			if (tout[s] > tout[i])
				bad();
	}	
	can.resize(n, {true, true});

	if (viv)
		cout << 1 << endl;

	ll ans = 0;
	string res(n, 'E');
	for (int i = 0; i < n; i++) {
		if (can[i].F && can[i].S) {
			ans++;
			res[i] = 'A';
		}
		DFS1(i);
		DFS2(i);
	}
	cout << ans << '\n';
	cout << res << '\n';
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