#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int qpow(int a, int p) {
	if (p == 0)
		return 1;
	else if (p % 2 == 1)
		return (a * qpow(a, p - 1)) % mod;
	else {
		int h = qpow(a, p / 2);
		return (h * h) % mod;
	}
}

int inv(int a) {
	return qpow(a, mod - 2);
}

vector<int> f;

int C(int n, int k) {
	if (n < k)
		return 0;
	return (((f[n] * inv(f[n - k])) % mod) * inv(f[k])) % mod;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		// cout << C(n - k * (i - 1), i) << endl;
		int p = (C(n - (k - 1) * (i - 1), i));
		p = (p*inv(C(n, i))) % mod;
		ans = (ans + p) % mod;
	}
	ans = (ans + 1) % mod;
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	f.push_back(1);
	for (int i = 1; i < 1e5 + 10; ++i)
		f.push_back((f[i - 1] * i) % mod);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}