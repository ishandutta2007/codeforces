#include<bits/stdc++.h>

using namespace std;

const int md = 1000000007;

int a[201], dp[201][102][1001], n, k;

void add(int i, int j, int p, int d) {
	if (j < 0 || j > n - i) return;
	
	p -= j * a[i];
	if (p > k) return;
	
	dp[i][j][p] += d;
	dp[i][j][p] %= md;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= min(i, n - i); j++)
			for (int p = 0; p <= k; p++)
				if (dp[i][j][p] > 0) {
					add(i + 1, j, j * a[i] + p, (dp[i][j][p] * 1ll * (j + 1)) % md);
					add(i + 1, j + 1, j * a[i] + p + a[i + 1], dp[i][j][p]);
					add(i + 1, j - 1, j * a[i] + p - a[i + 1], (dp[i][j][p] * 1ll * j) % md);
				}
	
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		ans += dp[n][0][i];
		ans %= md;
	}
	
	printf("%d\n", ans);
	
	return 0;
}