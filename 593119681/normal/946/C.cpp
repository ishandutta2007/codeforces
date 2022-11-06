#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, Fa[N][27];
char s[N];
bool ok = 0, Dp[N][27];

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	Dp[0][0] = 1;
	for (int i = 1; !ok && i <= n; i ++)
	{
		for (int j = 0; j <= 26; j ++)
			Dp[i][j] = Dp[i - 1][j], Fa[i][j] = j;
		for (int j = 1; j <= 26; j ++)
			if (Dp[i - 1][j - 1] && s[i] - 'a' + 1 <= j)
				Dp[i][j] = 1, Fa[i][j] = j - 1;
		ok = Dp[i][26];
		if (ok)
		{
			for (int _i = i, j = 26; _i; j = Fa[_i][j], _i --)
				if (Fa[_i][j] != j) s[_i] = 'a' + j - 1;
		}
	}
	if (!ok) puts("-1");
	else printf("%s\n", s + 1);
	return 0;
}