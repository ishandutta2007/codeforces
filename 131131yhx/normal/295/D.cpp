#include <bits/stdc++.h>
#define P 1000000007

using namespace std;

typedef long long ll;

int Dp[2010][2010], S[2010][2010], K[2010][2010], Q[2010][2010], n, m, ans = 0;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++) Dp[2][i] = 1, Dp[3][i] = i * 2 + 1;
	for(int i = 2; i <= m; i++) Dp[i][0] = 1, S[i][0] = 1;
	for(int i = 4; i <= m; i++)
		for(int j = 1; j <= n; j++)
			Dp[i][j] = ((Dp[i - 1][j] * 2 % P - Dp[i - 2][j]) % P + Dp[i][j - 1]) % P;
	for(int i = 2; i <= m; i++)
		for(int j = 1; j <= n; j++)
			S[i][j] = (S[i][j - 1] + Dp[i][j]) % P;
	for(int i = 2; i <= m; i++) {
		ans = (ans + (ll) S[i][n - 1] * (m - i + 1)) % P;
		for(int j = 0; j <= n - 2; j++)
			ans = (ans + S[i][j] * ((ll) S[i][n - j - 1] - S[i][n - j - 2]) % P * (m - i + 1)) % P;
	}
	printf("%d\n", (ans % P + P) % P);
	return 0;
}