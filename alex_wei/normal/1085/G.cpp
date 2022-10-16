#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int mod = 998244353;
int n, ans, a[N][N], f[N][N], pw[N];
struct BIT {
	int c[N];
	void add(int x, int v) {if(x) while(x <= n) c[x] += v, x += x & -x;}
	int query(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}
} null, full, trap, trnap;
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n;
	for(int i = 1; i <= n; i++) full.add(i, 1);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	for(int i = f[0][0] = 1; i <= n; i++)
		for(int j = 0; j <= i; j++) {
			if(j == 0) f[i][j] = 1ll * f[i - 1][0] * i % mod;
			else if(i == j) f[i][i] = i == 1 ? 0 : 1ll * (i - 1) * (f[i - 1][i - 1] + f[i - 2][i - 2]) % mod;
			else f[i][j] = (1ll * j * f[i - 1][j - 1] + 1ll * (i - j) * f[i - 1][j]) % mod;
		}
	for(int i = pw[0] = 1; i <= n; i++) pw[i] = 1ll * pw[i - 1] * f[n][n] % mod;
	for(int i = 1; i <= n; i++) {
		int ap1[N], ap2[N], L = n;
		memset(ap1, 0, sizeof ap1), memset(ap2, 0, sizeof ap2);
		trap = null, trnap = full;
		long long coef = 0;
		for(int j = 1; j <= n; j++) {
			if(!ap2[a[i - 1][j]]) L--, trnap.add(a[i - 1][j], -1);
			coef += 1ll * trap.query(a[i][j] - 1) * f[n - j][i > 1 ? L : 0];
			if(L || i == 1) coef += 1ll * trnap.query(a[i][j] - 1) * f[n - j][i > 1 ? L - 1 : 0];
			ap1[a[i][j]] ? trap.add(a[i][j], -1) : trnap.add(a[i][j], -1);
			ap1[a[i - 1][j]] = ap2[a[i][j]] = 1;
			if(!ap2[a[i - 1][j]]) trap.add(a[i - 1][j], 1);
			if(!ap1[a[i][j]]) L--;
		}
		ans = (ans + (coef % mod + mod) * pw[n - i]) % mod;
	}
	cout << ans << endl;
	return 0;
}

/*
2022/4/28
start thinking at 7:37

, .
 f_{i, j}  i  j .
,  f_{i, j}  D_n ^ {n - i} .
n ^ 3.
BIT  n ^ 2 log n.

f_{i, j} ?
.
 i .
 i,  f_{i - 1, j - 1},  j.
 i,  f_{i - 1, j},  i - j.
f_{i, j} = (j - 1)f_{i - 1, j - 1} + (i - j)f_{i - 1, j}
i = j .

 i = 1 
n ^ 3 finished at 8:42

finish debugging at 9:00
*/