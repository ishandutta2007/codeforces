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

ll n, ans;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ans = 1;
	for (int i = 1; i < n - 1; i++)
		ans *= i, ans %= mod;


	vector<bool> cool(n, true);
	for (int k = 0; k < 35; k++) {
		bool all = true;
		for (auto i : v)
			all = all & (i & 1);
		if (!all)
			for (int i = 0; i < n; i++)
				cool[i] = cool[i] & !(v[i] & 1);
		for (auto &i : v)
			i >>= 1;
	}
	ll cnt = 0;
	for (auto i : cool)
		cnt += i;
	ll cf = (cnt) * (cnt - 1);
	cf %= mod;
	ans *= cf;
	ans %= mod;
	cout << ans << '\n';
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