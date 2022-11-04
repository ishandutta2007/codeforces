#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 998244353;
int n, x[N], y[N], w[N], f[N], ps[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &w[i]);
	int ans = (x[n] + 1) % mod;
	for (int i = 1; i <= n; i++) {
		int j = lower_bound(x + 1, x + 1 + n, y[i]) - x;
		f[i] = ((ps[i - 1] + mod - ps[j - 1]) % mod + (x[i] - y[i])) % mod;
		ps[i] = (ps[i - 1] + f[i]) % mod;
		if (w[i]) ans = (ans + f[i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}