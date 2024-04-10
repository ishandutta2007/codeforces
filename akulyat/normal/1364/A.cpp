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

ll n, x;
vector<ll> v;
bool viv = false;


void solve() {
	v.clear();
	cin >> n >> x;
	v.resize(n);
	ll sum = 0;
	for (auto &i : v)
		cin >> i, sum += i;
	if (sum % x != 0) {
		cout << n << '\n';
		return;
	}

	ll l = 0, r = n - 1;
	while (l < n && v[l] % x == 0)
		l++;
	while (r >= 0 && v[r] % x == 0)
		r--;

	if (l == n) {
		cout << -1 << '\n';
		return;
	}

	cout << max(n - (n - 1 - r), n - (l - 0)) - 1;
	cout << '\n';
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