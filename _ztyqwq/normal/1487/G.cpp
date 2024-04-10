#include <bits/stdc++.h>
using namespace std;
const int m = 26, mod = 998244353;
typedef long long ll;
#define int ll
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod, n >>= 1;
	}
	return ans;
}
int c[30];
int f[2][410][2][2], g[2][410][410][3][3];
int sumf[410], sumg[410][410];
inline void admod(int &x, int y)
{
	x = (x + y) % mod;
}
inline int GetSumF(int l, int r)
{
	return (sumf[r] - sumf[l - 1] + mod) % mod;
}
inline int GetSumG(int l1, int r1, int l2, int r2)
{
	return (sumg[r1][r2] - sumg[r1][l2 - 1] - sumg[l1 - 1][r2] + sumg[l1 - 1][l2 - 1] + 2 * mod) % mod;
}
signed main()
{
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= m; i++)
		scanf("%lld", &c[i]);
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++)
			f[0][i + j][i][j] = (25 - i * 24) * (25 - j * 24);
	for(int I = 3, i = 1; I <= n; I++, i ^= 1)
	{
		for(int j = 0; j <= (I >> 1) + 1; j++)
			for(int s = 0; s <= 1; s++)
				for(int k = 0; k <= 1; k++)
					f[i][j][s][k] = 0;
		for(int j = 0; j <= (I >> 1) + 1; j++)
			for(int s = 0; s <= 1; s++)
			{
				admod(f[i][j][s][0], f[i ^ 1][j][0][s] * 24);
				admod(f[i][j + 1][s][1], f[i ^ 1][j][0][s]);
				admod(f[i][j][s][0], f[i ^ 1][j][1][s] * 25);
			}
	}
	for(int i = 0; i <= 2; i++)
		for(int j = 0; j <= 2; j++)
			g[0][(i == 1) + (j == 1)][(i == 2) + (j == 2)][i][j] = (24 - bool(i) * 23) * (24 - bool(j) * 23);
	for(int I = 3, i = 1; I <= n; I++, i ^= 1)
	{
		for(int j = 0; j <= (I >> 1) + 1; j++)
			for(int k = 0; k <= (I >> 1) + 1; k++)
				for(int s = 0; s <= 2; s++)
					for(int l = 0; l <= 2; l++)
						g[i][j][k][s][l] = 0;
		for(int j = 0; j <= (I >> 1) + 1; j++)
			for(int k = 0; k <= (I >> 1) + 1; k++)
				for(int s = 0; s <= 2; s++)
				{
					admod(g[i][j][k][s][0], g[i ^ 1][j][k][0][s] * 23);
					admod(g[i][j + 1][k][s][1], g[i ^ 1][j][k][0][s]);
					admod(g[i][j][k + 1][s][2], g[i ^ 1][j][k][0][s]);
					admod(g[i][j][k][s][0], g[i ^ 1][j][k][1][s] * 24);
					admod(g[i][j][k + 1][s][2], g[i ^ 1][j][k][1][s]);
					admod(g[i][j][k][s][0], g[i ^ 1][j][k][2][s] * 24);
					admod(g[i][j + 1][k][s][1], g[i ^ 1][j][k][2][s]);
				}
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= 1; j++)
			for(int k = 0; k <= 1; k++)
				admod(sumf[i], f[n & 1][i][j][k]);
		if(i >= 1)
			sumf[i] = (sumf[i] + sumf[i - 1]) % mod;
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
		{
			for(int k = 0; k <= 2; k++)
				for(int l = 0; l <= 2; l++)
					admod(sumg[i][j], g[n & 1][i][j][k][l]);
			if(i >= 1)
				sumg[i][j] = (sumg[i][j] + sumg[i - 1][j]) % mod;
			if(j >= 1)
				sumg[i][j] = (sumg[i][j] + sumg[i][j - 1]) % mod;
			if(i >= 1 && j >= 1)
				sumg[i][j] = (sumg[i][j] - sumg[i - 1][j - 1] + mod) % mod;
		}
	int ans0 = 26 * 26 * fastpow(25, n - 2) % mod;
	int ans1 = 0;
	for(int i = 1; i <= m; i++)
		ans1 = (ans1 + GetSumF(c[i] + 1, n)) % mod;
	int ans2 = 0;
	for(int i = 1; i <= m; i++)
		for(int j = i + 1; j <= m; j++)
			ans2 = (ans2 + GetSumG(c[i] + 1, n, c[j] + 1, n)) % mod;
	int ans = (ans0 - ans1 + ans2 + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}