#include <bits/stdc++.h>

using namespace std;
#define int long long

int MOD = 1000000007;
#define MAX_N 600005

int inv[MAX_N], fac[MAX_N], finv[MAX_N];

void make() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		inv[i] = MOD - (long long)inv[MOD % i] * (MOD / i) % MOD;
		fac[i] = (long long)fac[i - 1] * i % MOD;
		finv[i] = (long long)finv[i - 1] * inv[i] % MOD;
	}
}

int comb(int a, int b) {
	if (a < b) {
		return 0;
	}
	return fac[a] * ((long long)finv[b] * finv[a - b] % MOD) % MOD;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N >> MOD;
	int res = 0;
	make();
	for (int i = 1; i <= N; i++) {
		int ans = 0;
		ans = (N - i + 1) * fac[i] % MOD;
		ans = ans * fac[N - i] % MOD;
		ans = ans * (N - i + 1) % MOD;
		res = res + ans; 
	}
	res %= MOD;
	res += MOD;
	res %= MOD;
	cout << res << endl;
}