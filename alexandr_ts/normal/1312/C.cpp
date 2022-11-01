#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 14;
const int N = 5e5 + 10;

ll a[N];

void solve() {
	ll n, k;
	cin >> n >> k;
	map<ll, int> m;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		int cur = 0;
		while (x) {
			if (x % k) {
				m[cur] += (x % k);	
			}
			x /= k;
			cur++;
		}	
	}

	for (auto [k, v]: m) {
		if (v > 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}