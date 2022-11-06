#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 2009;
const int mod = 998244353;
ll C[MaxN + 9][MaxN + 9];


ll modPow(ll n, ll k) {
	ll res = 1;
	for(n %= mod; k; k >>= 1) {
		if(k & 1) res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for(int i = 0; i <= MaxN; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}

	ll n, m, k;
	cin >> n >> m >> k;

	ll ans = C[n-1][k] * m % mod * (k == 0 ? 1 : modPow(m-1, k));
	cout << (ans%mod + mod) % mod;
	return 0;
}