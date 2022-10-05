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
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i = abs(i);

	map<int, vector<int>> mp; 
	for (int mask = 0; mask < (1 << n); mask++) {
		int f = mask;
		ll sum = 0;
		for (int j = 0; j < n; j++) {
			if (f & 1)
				sum += v[j];
			f >>= 1;
		}
		mp[sum].push_back(mask);
	}

	for (auto p : mp) {
		for (auto m1 : p.S)
			for (auto m2: p.S)
				if (m1 != m2)
					if (m1 + m2 == (m1 | m2)) {
						cout << "YES\n";
						return;
					}
	}
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