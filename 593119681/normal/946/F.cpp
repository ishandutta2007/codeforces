#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define Mod 1000000007

int n, x, Pow[N], Cnt[N][N][N], L[N][N][N], R[N][N][N], Dp[N][N][N];
char s[N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

// 10110 11
// 14

int main()
{
	scanf("%d%d", &n, &x);
	scanf("%s", s + 1);
	Pow[0] = Pow[1] = 2;
	for (int i = 1; i <= n; i ++)
		if (s[i] == '0') Cnt[0][i][i] = 1, L[0][i][i] = n - i + 1, R[0][i][i] = i, Dp[0][i][i] = i * (n - i + 1);
			else Cnt[1][i][i] = 1, L[1][i][i] = n - i + 1, R[1][i][i] = i, Dp[1][i][i] = i * (n - i + 1);
	for (int i = 2; i <= x; i ++)
	{
		Pow[i] = 1LL * Pow[i - 1] * Pow[i - 2] % Mod;
		for (int l = 1; l <= n; l ++)
			for (int r = l; r <= n; r ++)
			{
				Cnt[i][l][r] = Inc(Cnt[i - 1][l][r], Cnt[i - 2][l][r]);
				L[i][l][r] = Inc(1LL * L[i - 1][l][r] * Pow[i - 2] % Mod, L[i - 2][l][r]);
				R[i][l][r] = Inc(R[i - 1][l][r], 1LL * R[i - 2][l][r] * Pow[i - 1] % Mod);
				Dp[i][l][r] = Inc(1LL * Dp[i - 1][l][r] * Pow[i - 2] % Mod, 1LL * Dp[i - 2][l][r] * Pow[i - 1] % Mod);
				for (int k = l; k < r; k ++)
				{
					Cnt[i][l][r] = Inc(Cnt[i][l][r], 1LL * Cnt[i - 1][l][k] * Cnt[i - 2][k + 1][r] % Mod);
					L[i][l][r] = Inc(L[i][l][r], 1LL * Cnt[i - 1][l][k] * L[i - 2][k + 1][r] % Mod);
					R[i][l][r] = Inc(R[i][l][r], 1LL * R[i - 1][l][k] * Cnt[i - 2][k + 1][r] % Mod);
					Dp[i][l][r] = Inc(Dp[i][l][r], 1LL * R[i - 1][l][k] * L[i - 2][k + 1][r] % Mod);
				}
			}
	}
	printf("%d\n", Dp[x][1][n]);
	return 0;
}