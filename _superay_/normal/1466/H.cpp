#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k, p[45], vis[45], len[45], cnt[45], ps[45], f[1440], C[45][45], fact[45], pw[45][45];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	vector<int> vc;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		int j = i, c = 0;
		while (!vis[j]) {
			vis[j] = 1;
			c++;
			j = p[j];
		}
		vc.push_back(c);
	}
	sort(vc.begin(), vc.end());
	ps[0] = 1;
	for (int i = 0, j; i < (int)vc.size(); i = j) {
		for (j = i; j < (int)vc.size() && vc[i] == vc[j]; j++);
		++k;
		len[k] = vc[i];
		cnt[k] = j - i;
		ps[k] = ps[k - 1] * (cnt[k] + 1);
	}
	for (int i = fact[0] = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
	for (int i = C[0][0] = 1; i <= n; i++)
		for (int j = C[i][0] = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	for (int i = 0; i < n; i++) {
		int b = 0;
		for (int j = 0; j <= i; j++)
			b = (b + 1ll * fact[j] * fact[n - j - 1] % mod * C[i][j]) % mod;
		for (int j = pw[i][0] = 1; j <= n; j++)
			pw[i][j] = 1ll * pw[i][j - 1] * b % mod;
	}
	f[0] = 1;
	for (int mask = 1; mask < ps[k]; mask++) {
		int c[45], al = 0;
		for (int i = 1; i <= k; i++) c[i] = mask / ps[i - 1] % (cnt[i] + 1), al += len[i] * c[i];
		function<void(int, int, int, int)> go = [&](int i, int nmask, int sum, int cf) {
			if (i == k + 1) {
				if (nmask != mask) {
					f[mask] = (f[mask] + 1ll * cf * f[nmask] % mod * pw[sum][al - sum]) % mod;
				}
				return;
			}
			for (int b = 0; b <= c[i]; b++) {
				go(i + 1,
					nmask + ps[i - 1] * (c[i] - b),
						sum + len[i] * (c[i] - b),
							1ll * cf * ((b & 1) ? mod - C[c[i]][b] : C[c[i]][b]) % mod);
			}
		};
		go(1, 0, 0, mod - 1);
	}
	printf("%d\n", f[ps[k] - 1]);
	return 0;
}