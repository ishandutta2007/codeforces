#include <bits/stdc++.h>
using std::min; using std::max;
typedef long long LL;
const int N = 5005, P = 1e9 + 7;
int n, k, q, a[N], e[N], f[N], g[N], dp[N][N];
int ans = 0;
int main() {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++) dp[0][i] = 1; //{ e[i] = i == 1 || i == n ? 1 : 2; f[i] = 1; }
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % P;
	for (int i = 1; i <= n; i++) f[i] = 1, e[i] = dp[k][i];
	for (int i = 1; i <= k; i++) {
		memcpy(g, f, sizeof g); memset(f, 0, sizeof f);
		for (int j = 1; j <= n; j++) {
			if (j > 1) (f[j-1] += g[j]) %= P;
			if (j < n) (f[j+1] += g[j]) %= P;
		}
		for (int j = 1; j <= n; j++) e[j] = (e[j] + 1LL*f[j]*dp[k-i][j]) % P;//(e[i] += f[i]) %= P;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans = (ans + 1LL*a[i]*e[i]) % P;
	//for (int i = 1; i <= n; i++) printf("%d ", e[i]); puts("");
	while (q--) {
		int p, x; scanf("%d%d", &p, &x);
		ans = (ans - 1LL*a[p]*e[p]%P + P) % P;
		a[p] = x;
		ans = (ans + 1LL*a[p]*e[p]) % P;
		printf("%d\n", ans);
	}
	return 0;
}