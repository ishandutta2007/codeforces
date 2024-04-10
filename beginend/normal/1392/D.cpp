#include<bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N], f[N][5];
char str[N];

int solve(int l, int r)
{
	for (int i = l; i <= r; i++)
		f[i][1] = f[i][2] = f[i][0] = f[i][3] = n;
	if (a[l] == 0) f[l][0] = f[l][1] = 1;
	else f[l][0] = f[l][1] = 0;
	for (int i = l + 1; i <= r; i++)
	{
		if (!a[i])
		{
			f[i][0] = min(f[i - 1][2], f[i - 1][3]) + 1;
			f[i][1] = min(f[i - 1][0], min(f[i - 1][2], f[i - 1][3])) + 1;
			f[i][2] = f[i - 1][1];
			f[i][3] = f[i - 1][2];
		}
		else
		{
			f[i][0] = min(f[i - 1][2], f[i - 1][3]);
			f[i][1] = min(f[i - 1][0], min(f[i - 1][2], f[i - 1][3]));
			f[i][2] = f[i - 1][1] + 1;
			f[i][3] = f[i - 1][2] + 1;
		}
	}
	return min(f[r][2], f[r][3]);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++) a[i] = str[i] == 'L' ? 0 : 1;
		int ans = n;
		for (int i = 1; i <= 5; i++)
		{
			ans = min(ans, solve(i, n + i - 1));
			a[n + i] = a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}