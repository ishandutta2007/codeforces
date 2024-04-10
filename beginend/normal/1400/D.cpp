#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3005;

int n, a[N], s[N][N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				s[i][j] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i][a[i]]++;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				s[i][j] += s[i - 1][j];
		LL ans = 0;
		for (int i = 2; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ans += s[i - 1][a[j]] * (s[n][a[i]] - s[j][a[i]]);
		printf("%lld\n", ans);
	}
	return 0;
}