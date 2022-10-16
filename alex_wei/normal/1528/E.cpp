#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 998244353;
long long n, f[N], g[N], h[N], s[N], ans;
long long calc(long long x) {return x * (x + 1) % mod * (x + 2) % mod * (mod + 1) / 6 % mod;}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n;
	f[0] = s[0] = 1;
	g[1] = h[1] = 1, f[1] = 2, s[1] = 3;
	for(int i = 2; i <= n; i++) {
		g[i] = (s[i - 1] * (s[i - 1] + 1) - s[i - 2] * (s[i - 2] + 1)) / 2 % mod;
		g[i] = (g[i] % mod + mod) % mod;
		f[i] = (f[i - 1] + g[i]) % mod;
		s[i] = (s[i - 1] + f[i]) % mod;
		h[i] = (h[i - 1] + g[i]) % mod;
	}
	ans = f[n] + calc(s[n - 1]) + mod - calc(n > 1 ? s[n - 2] : 0);
	ans = (ans * 2 - 1) % mod;
	for(int i = 1; i + 1 < n; i++) ans = (ans + g[i] * h[n - i - 1]) % mod;
	cout << ans << endl;
	return 0;
}