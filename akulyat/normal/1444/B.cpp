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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v, p;
bool viv = false;

ll obr(ll v, ll st = mod - 2) {
	if (st == 0)
		return 1;
	ll sq = obr(v, st / 2);
	ll ans = sq * sq;
	ans %= mod;
	if (st & 1) {
		ans *= v;
		ans %= mod;
	}
	return ans;
}

ll C(ll n, ll k) {
	ll ans = 1;
	for (int i = n - k + 1; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
	for (int i = 1; i <= k; i++) {
		ans *= obr(i);
		ans %= mod;
	}
	return ans;
}

void solve() {
	cin >> n;
	n *= 2;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < n / 2; i++)
		ans += (v[n - 1 - i] - v[i]);
	ans %= mod;
	ans *= C(n, n / 2);
	ans %= mod;
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}