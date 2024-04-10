#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, m, a[N], w[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		int s = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &w[i]), s += w[i] == 1;
		sort(a + 1, a + n + 1);
		sort(w + 1, w + m + 1);
		LL ans = 0;
		for (int i = 1; i <= m; i++) ans += a[n - i + 1];
		for (int i = 1; i <= s; i++) ans += a[n - i + 1];
		int now = n - m + 1;
		for (int i = 1; i <= m; i++)
			if (w[i] > 1) now -= w[i] - 1, ans += a[now];
		printf("%lld\n", ans);
	}
	return 0;
}