#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e6;

ll fac[maxn + 1], dp[21][maxn + 1];

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b & 1) return a * pw(a, b - 1) % mod;
	a = pw(a, b / 2);
	return a * a % mod;
}

ll cnk(ll n, ll k) {
	return fac[n] * pw(fac[n - k] * fac[k] % mod, mod - 2) % mod;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fac[0] = 1;
	for(int i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2; i <= maxn; i++) dp[1][i] = 1;
	for(int j = 1; j <= 19; j++)
		for(int i = 2; i <= maxn; i++)
			if(dp[j][i])
				for(int d = i + i; d <= maxn; d += i)
					dp[j + 1][d] = (dp[j + 1][d] + dp[j][i]) % mod;
	int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;
		if(x == 1) {
			cout << pw(2, y - 1) << '\n';
			continue;
		}
		ll ret = 0;
		for(int i = 1; i <= 20; i++)
			ret = (ret + dp[i][x] * cnk(y, i)) % mod;
		cout << ret * pw(2, y - 1) % mod << '\n';
	}
}