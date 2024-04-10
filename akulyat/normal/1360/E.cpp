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

ll n;
vector<vector<ll>> f;
bool viv = false;


void solve() {
	cin >> n;
	f.clear();
	f.resize(n);
	for (auto &l : f) {
		string s;
		cin >> s;
		for (auto &c : s)
			l.push_back(c == '1');
	}
	bool res = true;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++) {
			if (f[i][j] && !f[i + 1][j] && !f[i][j + 1])
				res = false;
		}
	if (res)
		cout << "YES\n";
	else
		cout << "NO\n";
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