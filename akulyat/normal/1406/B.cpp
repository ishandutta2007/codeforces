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
		cin >> i;

	vector<ll> a, b;
	for (auto i : v)
		if (i > 0)
			a.push_back(i);
		else
			b.push_back(i);
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	ll ans = -3 * inf;
	for (int k = 0; k <= 5; k++) {
		if (b.size() >= k && a.size() >= 5 - k) {
			ll res1 = 1;
			ll res2 = 1;
			ll res3 = 1;
			ll res4 = 1;
			for (int j = 0; j < k; j++) {
				res1 *= b[j];
				res2 *= b[j];
				res3 *= b[(int)b.size() - 1 - j];
				res4 *= b[(int)b.size() - 1 - j];
			}
			for (int j = 0; j < 5 - k; j++) {
				res1 *= a[j];
				res2 *= a[(int)a.size() - 1 - j];
				res3 *= a[j];
				res4 *= a[(int)a.size() - 1 - j];
			}
			ans = max(ans, res1);
			ans = max(ans, res2);
			ans = max(ans, res3);
			ans = max(ans, res4);
		}
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