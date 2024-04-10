#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 107;
const int MAXK = MAXN * MAXN;
const int MOD = 1000000007;

int n, k;
long long m;
int c[MAXN][MAXN];
int f[MAXN][MAXK];
int g[MAXN];

int powmod(int a, long long b, int m)
{
	if (b == 0)
		return 1;
	long long res = powmod(a, b >> 1, m);
	(res *= res) %= m;
	return b & 1? res * a % MOD : res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < MAXN; i++)
		c[i][0] = 1;
	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;

	f[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
			g[j] = powmod(c[n][j], (m - i - 1) / n + 1, MOD);

		for (int j = 0; j <= n * n; j++)
			if (f[i][j])
				for (int x = 0; x <= n && j + x <= k; x++)
				{
					f[i + 1][j + x] += f[i][j] * (long long)g[x] % MOD;
					if (f[i + 1][j + x] >= MOD)
						f[i + 1][j + x] -= MOD;
				}
	}
	printf("%d\n", f[n][k]);
	return 0;
}