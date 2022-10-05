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

ll n, x;
vector<ll> v, u;
bool viv = false;


void solve() {
	cin >> n >> x;
	v.resize(n);
	u.resize(n);
	for (auto &i : v)
		cin >> i;
	for (auto &i : u)
		cin >> i;
	sort(v.begin(), v.end());
	sort(u.rbegin(), u.rend());
	bool good = true;
	for (int i = 0; i < n; i++)
		if (v[i] + u[i] > x)
			good = false;
	if (good)
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