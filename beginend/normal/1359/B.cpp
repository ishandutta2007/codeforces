#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, x, y, f[N];
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &x, &y);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str + 1);
			for (int j = 1; j <= m; j++)
				if (str[j] == '*') f[j] = f[j - 1];
				else if (j > 1 && str[j - 1] == '.') f[j] = min(f[j - 1] + x, f[j - 2] + y);
				else f[j] = f[j - 1] + x;
			ans += f[m];
		}
		printf("%d\n", ans);
	}
	return 0;
}