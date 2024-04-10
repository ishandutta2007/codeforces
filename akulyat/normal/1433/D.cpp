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
vector<int> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	bool good = false;
	for (int i = 0; i < n; i++)
		if (v[i] != v[0])
			good = true;
	if (!good) {
		cout << "NO\n";
		return;
	}
	vector<pii> ans;
	for (int i = 1; i < n; i++)
		if (v[i] != v[0])
			ans.push_back({0, i});
	int j = 0;
	while (v[j] == v[0])
		j++;	
	for (int i = 1; i < n; i++)
		if (v[i] == v[0])
			ans.push_back({j, i});
	cout << "YES\n";
	for (auto p : ans ) {
		cout << p.F + 1 << ' ';
		cout << p.S + 1 << '\n';
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