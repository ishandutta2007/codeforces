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

ll n, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	v.assign(n + 2, 0);
	v[0] = 1;
	ll ans = 1;
	int lft = true;
	k -= 1;
	while (k > 0) {
		if (lft) {
			ll sum = v[0];
			v[0] = 0;
			for (int i = 1; i <= n; i++) {
				ll add = v[i];
				v[i] = sum;
				sum += add;
				sum %= mod;
			}
		} else {
			ll sum = v[n + 1];
			for (int i = n; i >= 1; i--) {
				ll add = v[i];
				v[i] = sum;
				sum += add;
				sum %= mod;
			}
		}
		if (viv) {
			cout << "\t";
			for (auto i : v)
				cout << i << ' ';
			cout << endl;
		}
		for (int i = 1; i <= n; i++)
			ans += v[i];
		ans %= mod;
		k--;
		lft ^= true;
	}
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