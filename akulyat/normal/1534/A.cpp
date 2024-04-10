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

ll n, m;
vector<string> v;
bool viv = false;

bool ok(vector<string> p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != '.' && v[i][j] != p[i][j])
				return false;
		}
	}
	cout << "YES\n";
	for (auto s : p)
		cout << s << '\n';
	return true;
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &s : v)
		cin >> s;
	auto p = v, q = v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) & 1) {
				p[i][j] = 'R';
				q[i][j] = 'W';
			} else {
				p[i][j] = 'W';
				q[i][j] = 'R';				
			}
		}
	}
	if (ok(p))
		return;
	if (ok(q))
		return;
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