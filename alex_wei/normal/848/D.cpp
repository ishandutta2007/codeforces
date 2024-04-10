#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
const int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, m, inv[N], f[N][N], g[N][N], h[N][N], G[N][N][N], visf[N][N], visg[N][N];
int calcg(int i, int j);
int calcf(int i, int j) {
	if(i < j) return 0;
	if(!i || !j) return i == j;
	if(visf[i][j]) return f[i][j];
	for(int x = 1; x <= i; x++) for(int y = 1; y <= j; y++) calcg(x, y);
	visf[i][j] = 1;
	f[i][j] = h[i][j];
	// cerr << "fffff " << i << " " << j << " " << f[i][j] << endl;
	return f[i][j];
}
int calcg(int i, int j) {
	if(i < j) return 0;
	if(!i || !j) return i == j;
	if(visg[i][j]) return g[i][j];
	visg[i][j] = 1;
	for(int l = 0, r = i - 1; l < i; l++, r--) {
		long long coef = 0;
		for(int p = j - 1; p <= r; p++) coef += calcf(r, p);
		add(g[i][j], coef % mod * calcf(l, j - 1) % mod);
		coef = 0;
		for(int p = j; p <= l; p++) coef += calcf(l, p);
		add(g[i][j], coef % mod * calcf(r, j - 1) % mod);
	}
	// cerr << i << " " << j << " " << g[i][j] << endl;
	G[i][j][0] = 1;
	for(int p = 1; p <= n; p++) G[i][j][p] = 1ll * G[i][j][p - 1] * (g[i][j] + p - 1) % mod * inv[p] % mod;
	for(int p = n; p; p--)
		for(int q = n; q; q--)
			for(int k = 1, pp = p - i, qq = q - j; pp >= 0 && qq >= 0; k++, pp -= i, qq -= j)
				add(h[p][q], 1ll * h[pp][qq] * G[i][j][k] % mod);
	// cerr << "chk " << x << " " << y << " " << G[x][y][0] << " " << G[x][y][1] << " " << h[1][1] << " " << h[2][1] << " " << h[2][2] << endl;
	return g[i][j];
}
int main() {
	h[0][0] = 1;
	// freopen("1.in", "r", stdin);
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod; 
	cin >> n >> m, cout << calcf(n, m - 1) << endl;
	return 0;
}

/*
2022/4/30
start thinking at ??:??

 f_{i, j}  i  j .
g_{i, j}  j 

f_{i, j}  g_{i, j} .
g_{i, j} = prod_{l + r = i - 1} f_{l, j - 1} * sum f_{r, j - 1 ~ r} + f_{r, j - 1} * sum f_{l, j ~ l}

, .
n ^ 6 ln n.

 n ^ 4 ln n, , .

start coding at ??:??
finish debugging at 15:57
*/