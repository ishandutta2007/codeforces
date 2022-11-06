#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

const int MxN = 5009;
ll modInv[MxN + 9];
ll occ[MxN + 9];
ll dp[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= MxN; ++i)
		modInv[i] =  modPow(i, mod-2);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}

	dp[0] = 1;

	ll ans = 0;

	for (int i = 1; i <= n; ++i) {
		if (!occ[i])
			continue;

		for (int j = 1; j <= i; ++j) {
			ans += dp[j - 1] * occ[i] % mod * (occ[i] - 1) % mod * modInv[n - j + 1] % mod * modInv[n - j];
			ans %= mod;
		}

		for (int j = i; j >= 1; --j) {
			dp[j] += dp[j - 1] * occ[i] % mod * modInv[n - j + 1];
			dp[j] %= mod;
		}
	}

	cout << (ans % mod + mod) % mod;
	return 0;
}