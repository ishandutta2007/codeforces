#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, k, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		if (!k) printf("%d\n", a[n] - a[1]);
		else
		{
			LL ans = a[n];
			for (int i = 1; i <= k; i++) ans += a[n - i];
			printf("%lld\n", ans);
		}
	}
	return 0;
}