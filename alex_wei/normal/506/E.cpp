#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
const int mod = 1e4 + 7;
int n, m, sz, red, green, ans;
char s[N];
struct mat {
	int a[N << 1][N << 1]; //  =.=
	void init() {memset(a, 0, sizeof(a));}
	friend mat operator * (mat &x, mat &y) {
		mat z;
		z.init();
		for(int i = 1; i <= sz; i++)
			for(int k = i; k <= sz; k++) {
				for(int j = k; j <= sz; j++) z.a[i][j] += x.a[i][k] * y.a[k][j];
				if(k % 20 == 0 || k == sz) for(int j = 1; j <= sz; j++) z.a[i][j] %= mod;
			}
		return z;
	}
} tr, PATH;
mat matrix_quickpow(mat a, int b) {
	assert(b--);
	mat s = a;
	while(b) {
		if(b & 1) s = s * a;
		a = a * a, b >>= 1;
	}
	return s;
}

int k, f[N][N][N], tmp[N];
bool vis[N][N][N];
int calc_path(int l, int r, int num) {
	if(num < 0) return 0;
	if(l > r) return num ? 0 : 1;
	if(vis[l][r][num]) return f[l][r][num];
	vis[l][r][num] = 1;
	if(s[l] ^ s[r]) f[l][r][num] = calc_path(l, r - 1, num - 1) + calc_path(l + 1, r, num - 1);
	else f[l][r][num] = calc_path(l + 1, r - 1, num);
	return f[l][r][num] % mod;
}
int calc_path2(int l, int r, int num) {
	if(l >= r || num < 0) return 0;
	if(l + 1 == r && s[l] == s[r]) return num ? 0 : 1;
	if(vis[l][r][num]) return f[l][r][num];
	vis[l][r][num] = 1;
	if(s[l] ^ s[r]) f[l][r][num] = calc_path2(l, r - 1, num - 1) + calc_path2(l + 1, r, num - 1);
	else f[l][r][num] = calc_path2(l + 1, r - 1, num);
	return f[l][r][num] % mod;
}

int main() {
	// freopen("1.in", "r", stdin);
	cin >> s + 1 >> n, m = strlen(s + 1), k = m + n >> 1;
	for(int i = 0; i < m; i++) tmp[i] = calc_path(1, m, i);
	// for(int i = 0; i < m; i++) cerr << i << " " << calc_path(1, m, i) << endl;
	red = m - 1, green = m + 1 >> 1, sz = red + green * 2;
	for(int i = 1; i < red + green; i++) tr.a[i][i + 1] = 1;
	for(int i = red + 1; i <= red + green; i++) tr.a[i][i + green] = 1;
	for(int i = 1; i <= red; i++) tr.a[i][i] = 24;
	for(int i = red + 1; i <= red + green; i++) tr.a[i][i] = 25;
	for(int i = red + green + 1; i <= sz; i++) tr.a[i][i] = 26;
	PATH = matrix_quickpow(tr, k);
	if(n + m & 1) {
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		for(int i = 0; i <= m - 2; i++) {
			int coef = calc_path2(1, m, i);
			// cerr << i << " " << coef << endl;
			if(m - i & 1) {assert(!coef); continue;}
			ans = (ans - coef * PATH.a[red + 1 - i][red + (m - i >> 1)]) % mod;
		}
		ans += mod, PATH = PATH * tr;
	}
	// cerr << ans - mod << endl;
	for(int i = 0; i < m; i++) {
		int gnum = m - i + 1 >> 1;
		// cerr << i << " " << red + green + gnum << " " << PATH.a[red + 1 - i][red + green + gnum] << endl;
		ans = (ans + tmp[i] * PATH.a[red + 1 - i][red + green + gnum]) % mod;
	}
	cout << ans << endl;
	return 0;
}

/*
2022/4/28
start thinking at 7:55

 f_{i, l, r}  i , s_l ~ s_r .
i .
i , ?
.
.

.
 |s| ^ 2 .
?
, !
!
 f_{i, j}  i  j .
, ,  j .

, .
.
, .
.
.

.

start coding at 9:48
finish debugging at 11:11
*/