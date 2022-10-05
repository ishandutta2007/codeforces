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
vector<vector<ll>> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.clear();
	v.resize(n);
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i;
	}

	bool can = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int val = 4;
			if (i == 0)
				val--;
			if (j == 0)
				val--;
			if (i + 1 == n)
				val--;
			if (j + 1 == m)
				val--;
			if (v[i][j] > val)
				can = false;
			v[i][j] = val;
		}
	}
	if (!can) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto l : v) {
		for (auto i : l)
			cout << i << ' ';
		cout << '\n';
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}