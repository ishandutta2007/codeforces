#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, Dp[2][N];
char s[N];

bool Judge(int id)
{
	if (id & 1) return 0;
	int mid = id >> 1;
	for (int i = 1; i <= mid; i ++)
		if (s[i] != s[mid + i]) return 0;
	return 1;
}

int main()
{
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i ++)
	{
		Dp[0][i] = Dp[0][i - 1] + 1;
		Dp[1][i] = Dp[1][i - 1] + 1;
		if (Judge(i)) Dp[1][i] = min(Dp[1][i], Dp[0][i >> 1] + 1);
	}
	printf("%d\n", min(Dp[0][n], Dp[1][n]));
	return 0;
}