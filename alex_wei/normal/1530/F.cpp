#pragma GCC optimize("Ofast") // bingo!
#include <bits/stdc++.h>
using namespace std;

const int N = 23;
const int mod = 31607;
int n, f[1 << N], g[1 << N], p[N][N], inv[N][N];
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = s * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return s;
}
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
void FWT(int *f, int op) {
	for(int k = 1; k < 1 << n + 2; k <<= 1)
		for(int i = 0; i < 1 << n + 2; i += k << 1)
			for(int j = 0; j < k; j++)
				if(op) add(f[i | j | k], f[i | j]);
				else add(f[i | j | k], mod - f[i | j]);
} 
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j],
			p[i][j] = p[i][j] * ksm(1e4, mod - 2) % mod,
			inv[i][j] = ksm(p[i][j], mod - 2);
	for(int i = 0; i < 1 << n + 2; i++) f[i] = 1; //  f = x ^ 0  FMT  f_S  1
	for(int i = 1; i <= n; i++) {
		memset(g, 0, sizeof(g));
		static int v[1 << N - 2];
		memset(v, 0, sizeof(v)), v[0] = 1;
		for(int j = 1; j <= n; j++) v[0] = v[0] * p[i][j] % mod;
		for(int j = 1; j < 1 << n; j++) {
			for(int k = 0; k < n; k++)
				if(j >> k & 1) {
					v[j] = v[j ^ (1 << k)] * inv[i][k + 1] % mod * (1 + mod - p[i][k + 1]) % mod;
					break;
				}
			g[j + ((j >> i - 1 & 1) << n) + ((j >> n - i & 1) << n + 1)] = v[j];
		}
		FWT(g, 1);
		for(int p = 0; p < 1 << n + 2; p++) f[p] = f[p] * g[p] % mod;
	}
	FWT(f, 0), cout << (mod + 1 - f[(1 << n + 2) - 1]) % mod << endl;
	return 0;
}