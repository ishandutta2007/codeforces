#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17, K = 1 << 3, mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1; // add 1ll
	}
	return s;
}
void FWT(int *f, int n, int op) {
	for(int k = 1; k < n; k <<= 1)
		for(int i = 0; i < n; i += k << 1)
			for(int j = 0, x, y; j < k; j++)
				x = f[i | j], y = f[i | j | k], f[i | j] = (x + y) % mod, f[i | j | k] = (x + mod - y) % mod;
	if(op != 1) for(int i = 0; i < n; i++) f[i] = 1ll * f[i] * op % mod;
}
int n, m, k, c[K], f[K], g[N], a[N][K], buc[K][N];
int main() {
	cin >> n >> m, k = 3;
	for(int i = 0; i < k; i++) cin >> c[i], c[i] %= mod;
	for(int i = 0; i < n; i++) {
		memset(f, 0, sizeof(f));
		for(int j = 0; j < k; j++) cin >> a[i][j];
		for(int j = 1; j < 1 << k; j++) for(int p = 0; p < k; p++) if(j >> p & 1) f[j] = f[j ^ (1 << p)] ^ a[i][p];
		for(int j = 0; j < 1 << k; j++) buc[j][f[j]]++;
	}
	for(int i = 0; i < 1 << k; i++) FWT(buc[i], 1 << m, 1);
	for(int i = 0; i < 1 << m; i++) {
		for(int j = 0; j < 1 << k; j++) f[j] = buc[j][i];
		FWT(f, 1 << k, ksm(mod + 1 >> 1, k)), g[i] = 1;
		for(int j = 0; j < 1 << k; j++) {
			int sum = 0;
			for(int p = 0; p < k; p++) sum = (sum + (j >> p & 1 ? mod - c[p] : c[p])) % mod;
			g[i] = 1ll * g[i] * ksm(sum, f[j]) % mod;
		}
	}
	FWT(g, 1 << m, ksm(mod + 1 >> 1, m));
	for(int i = 0; i < 1 << m; i++) cout << g[i] << " ";
	return 0;
}