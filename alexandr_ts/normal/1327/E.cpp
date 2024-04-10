#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll p[N];


void solve() {
	int n;
	cin >> n;
	
	p[0] = 1;
	for (int i = 1; i <= n + 10; ++i) {
		p[i] = p[i - 1] * 10 % MOD;
	}

	for (int k = 1; k <= n; ++k) {
		if (k == n) {
			cout << "10 ";
		} else if (k == n - 1) {
			cout << "180 ";
		} else {
			ll v1 = (n - k - 1) * 10 * (9*9) % MOD * p[n - k - 2] % MOD;
			ll v2 = 2 * 10 * 9 * p[n - k - 1] % MOD;
			cout << (v1 + v2) % MOD << " ";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}