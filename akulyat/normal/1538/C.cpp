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

ll n, l, r;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> l >> r;
	v.resize(n);
	for (auto &i : v) 
		cin >> i;
	sort(v.begin(), v.end());
	ll ans = 0;
	for (auto i : v) {
		int mini = l - i;
		auto z1 = lower_bound(v.begin(), v.end(), mini);
		int maxi = r - i;
		auto z2 = upper_bound(v.begin(), v.end(), maxi);
		int add = (z2 - z1);
		add = max(add, 0);
		ans += add;
	}
	for (auto i : v) 
		if (l <= 2 * i && 2 * i <= r)
			ans -= 1;
	ans /= 2;
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