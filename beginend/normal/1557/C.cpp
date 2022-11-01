#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MOD = 1000000007;
const int N = 200005;

int n, k, bin[N];

int ksm(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = (LL)ans * x % MOD;
		x = (LL)x * x % MOD; y >>= 1;
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		bin[0] = 1;
		for (int i = 1; i <= max(n, k); i++) bin[i] = bin[i - 1] * 2 % MOD;
		int ans = 0, s = 1;
		for (int i = k; i >= 1; i--) {
			int w1, w2;
			if (n & 1) {
				w1 = 1 + bin[n - 1];
				w2 = 0;
			}
			else {
				w1 = bin[n - 1] - 1;
				w2 = 1;
			}
			(ans += (LL)s * w2 % MOD * ksm(bin[i - 1], n) % MOD) %= MOD;
			s = (LL)s * w1 % MOD;
		}
		(ans += s) %= MOD;
		printf("%d\n", ans);
	}
	return 0;
}