#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 205, N2 = 405, P = 10007;
int n, m, cnt, f[N][N][N], g[N], ans;
char s[N];
int get(int a){ return (n - a + 1) >> 1; }
void inc(int &a, int b){ (a += b) >= P ? a -= P : 0; }
long long tmp[N2][N2];
struct matrix{ // upper triangle
	int a[N2][N2];
	void operator *= (const matrix &B){
		for (register int i = 1; i <= cnt; ++i)
			for (register int k = i; k <= cnt; ++k)
				for (register int j = k; j <= cnt; ++j)
					tmp[i][j] = tmp[i][j] + a[i][k] * B.a[k][j];
		for (register int i = 1; i <= cnt; ++i)
			for (register int j = i; j <= cnt; ++j)
				a[i][j] = tmp[i][j] % P, tmp[i][j] = 0;
	}
}A;
matrix qpow(matrix a, int b){
	matrix s = a;
	for (--b; b; b >>= 1, a *= a) if (b & 1) s *= a;
	return s;
}
int main(){
	scanf("%s", s + 1), n = strlen(s + 1), m = read();
	f[1][n][0] = 1;
	for (register int len = n; len; --len)
		for (register int l = 1, r; l <= n - len + 1; ++l){
			r = l + len - 1;
			for (register int k = 0; k <= n - len + 1; ++k)
				if (s[l] == s[r]) inc(len > 2 ? f[l + 1][r - 1][k] : g[k], f[l][r][k]);
				else inc(f[l + 1][r][k + 1], f[l][r][k]), inc(f[l][r - 1][k + 1], f[l][r][k]);
			// printf("%d %d:\n", l, r);
			// for (register int i = 0; i <= n; ++i) printf("%d ", f[l][r][i]); putchar('\n');
		}
	// for (register int i = 0; i <= n; ++i) printf("%d ", g[i]); putchar('\n');
	for (register int i = 1; i <= n; ++i) A.a[i][i + 1] = 1, A.a[i][i] = 24;
	int t = (n + 1) >> 1;
	for (register int i = 1; i < t; ++i) A.a[n + i][n + i + 1] = 1;
	for (register int i = 1; i <= t; ++i)
		A.a[n + i][n + i] = 25, A.a[n + i][n + t + i] = 1, A.a[n + t + i][n + t + i] = 26;
	cnt = n + (t << 1);
	A = qpow(A, (n + m) >> 1);
	// for (register int i = 1; i <= cnt; ++i){
	// 	for (register int j = 1; j <= cnt; ++j)
	// 		printf("%d ", A.a[i][j]);
	// 	putchar('\n');
	// }
	for (register int i = 0; i <= n; ++i)
		ans = (ans + g[i] * A.a[n - i + 1][n + t + get(i)]) % P;
	if ((n + m) & 1){
		ans = ans * 26 % P;
		for (register int i = 1; i <= n; ++i)
			for (register int j = 0; j < n; ++j)
				ans = (ans + f[i][i][j] * A.a[n - j + 1][n + get(j)]) % P;
	}
	printf("%d\n", ans);
}
/*
aba
2
*/