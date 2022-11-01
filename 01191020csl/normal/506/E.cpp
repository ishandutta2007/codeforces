#include<bits/stdc++.h>
#define mod 10007
using namespace std;
char s[210];
int f[201][201][201], vis[201][201][201], m;
int dfs(int l, int r, int n) {
	if (vis[l][r][n]) return f[l][r][n];
	vis[l][r][n] = 1;
	int ans = 0;
	if (r != m && s[l] != s[r+1]) ans += dfs(l, r + 1, n - 1);
	if (l != 1 && s[l-1] != s[r]) ans += dfs(l - 1, r, n - 1);
	if (l != 1 && r != m && s[l-1] == s[r+1]) ans += dfs(l - 1, r + 1, n);
	return f[l][r][n] = ans % mod;
}
int trans[401][401], ans[401][401];
int a[401][401], b[401][401], c[401][401];
void times(int n) {
	for (int i = 0; i <= n; i++)
		for (int k = i; k <= n; k++) {
			c[i][k] = 0;
			for (int j = i; j <= k; j++)
				c[i][k] = (c[i][k]+a[i][j]*b[j][k])%mod;
		}
}
int solveodd(int m, int n) {
	memset(trans, 0, sizeof(trans));
	memset(ans, 0, sizeof(ans));
	int n0 = (n+m+1)/2+1;
	int n1 = m-1, n2 = (m+1)/2;
	for (int i = 0; i < n1; i++) trans[i][i+1] = 1;
	for (int i = 0; i <= n1; i++) {
		trans[i][i] = 24;
		if ((m-i) & 1) continue;
		int tmp = 0;
		for (int j = 1; j <= m; j++)
			if (j != m && s[j] == s[j+1]) tmp += f[j][j+1][i];
		trans[i][n1+n2+1-(m-i+1)/2] = tmp % mod;
	}
	trans[0][0] = 0;
	for (int i = n1 + 1; i <= n1 + n2; i++) trans[i][i+1] = 1, trans[i][i] = 25;
	n2 += n1 + 1;
	for (int i = 0; i <= n2; i++) ans[i][i] = 1;
	while (n0) {
		if (n0 & 1) {
			for (int i = 0; i <= n2; i++)
				for (int j = i; j <= n2; j++)
					a[i][j] = trans[i][j], b[i][j] = ans[i][j];
			times(n2);
			for (int i = 0; i <= n2; i++)
				for (int j = i; j <= n2; j++)
					ans[i][j] = c[i][j];
		}
		for (int i = 0; i <= n2; i++)
			for (int j = i; j <= n2; j++)
				a[i][j] = b[i][j] = trans[i][j];
		times(n2);
			for (int i = 0; i <= n2; i++)
				for (int j = i; j <= n2; j++)
					trans[i][j] = c[i][j];
		n0 >>= 1;
	}
	return ans[0][n2];
}
int main() {
	cin >> s + 1;
	int n;
	cin >> n;
	m = strlen(s + 1);
	vis[1][m][0] = 1, f[1][m][0] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
			for (int k = 0; k <= m; k++)
				dfs(i, j, k);
	int n0 = (n+m+1)/2 + 1;
	int n1 = m - 1, n2 = (m+1)/2;
	for (int i = 0; i < n1; i++) trans[i][i+1] = 1;
	for (int i = 0; i <= n1; i++) {
		trans[i][i] = 24;
		int tmp = 0;
		for (int j = 1; j <= m; j++) {
			tmp += f[j][j][i];
			if (j != m && s[j] == s[j+1]) tmp += f[j][j+1][i];
		}
		trans[i][n1+n2+1-(m-i+1)/2] = tmp % mod;
	}
	trans[0][0] = 0;
	for (int i = n1 + 1; i <= n1 + n2; i++) trans[i][i+1] = 1, trans[i][i] = 25;
	n2 += n1 + 1, trans[n2][n2] = 26;
	for (int i = 0; i <= n2; i++) ans[i][i] = 1;
	while (n0) {
		if (n0 & 1) {
			for (int i = 0; i <= n2; i++)
				for (int j = i; j <= n2; j++)
					a[i][j] = trans[i][j], b[i][j] = ans[i][j];
			times(n2);
			for (int i = 0; i <= n2; i++)
				for (int j = i; j <= n2; j++)
					ans[i][j] = c[i][j];
		}
		for (int i = 0; i <= n2; i++)
			for (int j = i; j <= n2; j++)
				a[i][j] = b[i][j] = trans[i][j];
		times(n2);
			for (int i = 0; i <= n2; i++)
				for (int j = i; j <= n2; j++)
					trans[i][j] = c[i][j];
		n0 >>= 1;
	}
	int res = ans[0][n2];
	if ((n + m) & 1) res = (mod + res - solveodd(m, n)) % mod;
	cout << res << endl;
}