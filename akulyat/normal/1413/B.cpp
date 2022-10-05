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
vector<vector<int>> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.resize(n);
	map<int, int> fr;
	int cnt = 0;
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i;
		fr[l[0]] = cnt++;
	}

	auto fv = v;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			if (fr.find(val) != fr.end()) {
				fv[i] = v[fr[val]];
			}
		}
	}
	for (auto l : fv) {
		for (auto i : l)
			cout << i << ' ';
		cout << '\n';
	}
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