#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, ans, Cnt[5][2];
char s[N];

void dfs(int dep, int a, int b, int cur)
{
	if (dep > 4)
	{
		ans = min(ans, cur);
		return ;
	}
	if (a < 2) dfs(dep + 1, a + 1, b, cur + Cnt[dep][0]);
	if (b < 2) dfs(dep + 1, a, b + 1, cur + Cnt[dep][1]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 4; i ++)
		for (int j = 1; j <= n; j ++)
		{
			scanf("%s", s + 1);
			for (int k = 1; k <= n; k ++)
				Cnt[i][j + k + s[k] & 1] ++;
		}
	ans = 4 * n * n;
	dfs(1, 0, 0, 0);
	printf("%d\n", ans);
	return 0;
}