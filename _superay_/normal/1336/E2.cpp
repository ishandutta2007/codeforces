#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, ans[60], cnt[60], w[60][60], C[60][60];
long long bs[60], sb[60];
inline void Add(long long x) {
	for (int i = m - 1; i >= 0; i--) if (x >> i & 1) {
		if (!bs[i]) { bs[i] = x; break; }
		x ^= bs[i];
	}
}
vector<long long> vec;
void dfs(int i, long long cur) {
	if (i == (int)vec.size()) { cnt[__builtin_popcountll(cur)]++; return; }
	dfs(i + 1, cur);
	dfs(i + 1, cur ^ vec[i]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		long long x;
		scanf("%lld", &x);
		Add(x);
	}
	for (int i = 0; i < m; i++) for (int j = 0; j < i; j++) if (bs[i] >> j & 1) bs[i] ^= bs[j];
	int c = 0;
	for (int i = 0; i < m; i++) if (bs[i]) c++, vec.push_back(bs[i]);
	int pw2 = 1;
	if (c <= 26) {
		for (int i = 0; i < n - c; i++) pw2 = 2 * pw2 % mod;
		dfs(0, 0);
		for (int i = 0; i <= m; i++) ans[i] = 1ll * cnt[i] * pw2 % mod;
	} else {
		if (n - m >= 0) for (int i = 0; i < n - m; i++) pw2 = 2 * pw2 % mod;
		else for (int i = 0; i < m - n; i++) pw2 = 1ll * pw2 * ((mod + 1) >> 1) % mod;
		for (int i = 0; i < m; i++) if (!bs[i]) sb[i] ^= (1ll << i);
		for (int i = 0; i < m; i++) if (bs[i]) {
			for (int j = 0; j < m; j++) if (!bs[j]) {
				sb[j] ^= ((bs[i] >> j & 1) << i);
			}
		}
		c = 0;
		vec.clear();
		for (int i = 0; i < m; i++) if (sb[i]) c++, vec.push_back(sb[i]);
		dfs(0, 0);
		for (int i = C[0][0] = 1; i <= m; i++) for (int j = C[i][0] = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k <= i; k++) {
					int cur = 1ll * C[j][k] * C[m - j][i - k] % mod;
					if (k & 1) cur = mod - cur;
					w[i][j] = (w[i][j] + cur) % mod;
				}
			}
		}
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= m; j++) {
				ans[i] = (ans[i] + 1ll * cnt[j] * w[i][j]) % mod;
			}
			ans[i] = 1ll * ans[i] * pw2 % mod;
		}
	}
	for (int i = 0; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
	return 0;
}