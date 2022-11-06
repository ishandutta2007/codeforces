#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 50 + 5

int n, k;
LL ans, Sum[N][N];
bool Dp[N][N];

bool Check(LL x)
{
	for (int i = 1; i <= k; i ++)
		for (int j = 1; j <= n; j ++)
			Dp[i][j] = 0;
	Dp[0][0] = 1;
	for (int i = 1; i <= k; i ++)
		for (int j = i; j <= n; j ++)
			for (int u = i - 1; u < j; u ++)
				Dp[i][j] |= Dp[i - 1][u] & ((Sum[u + 1][j] & x) == x);
	return Dp[k][n];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", Sum[i] + i);
		for (int j = 1; j < i; j ++)
			Sum[j][i] = Sum[j][i - 1] + Sum[i][i];
	}
	for (int i = 62; ~i; i --)
	{
		LL _ans = ans | (1LL << i);
		if (Check(_ans)) ans = _ans;
	}
	printf("%lld\n", ans);
	return 0;
}