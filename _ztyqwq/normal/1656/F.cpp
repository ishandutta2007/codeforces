#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[200010], sum[200010];
inline int Sum(int l, int r)
{
	return sum[r] - sum[l - 1];
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		sum[0] = 0;
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i];
		int ans = LONG_LONG_MIN;
		int vt = a[1] * (n - 1) + Sum(2, n);
		if(vt > 0)
		{
			printf("INF\n");
			goto no;
		}
		vt = a[n] * (n - 1) + Sum(1, n - 1);
		if(vt < 0)
		{
			printf("INF\n");
			goto no;
		}
		for(int i = 1; i < n; i++) // a[i] + t < 0, a[i + 1] + t > 0
		{
			// val = b[1] * (b[i + 1] + ... + b[n - 1]) + (b[1] + ... + b[i - 1]) * b[n] + b[1] * b[n]
			int val = a[1] * Sum(i + 1, n - 1) + Sum(2, i) * a[n] + a[1] * a[n];
			int valt = a[1] * (n - 1 - i) + Sum(i + 1, n - 1) + a[n] * (i - 1) + Sum(2, i) + a[1] + a[n];
			int mnt = -a[i + 1], mxt = -a[i];
			ans = max(ans, val + max(valt * mnt, valt * mxt));
		}
		printf("%lld\n", ans);
		no:;
	}
	return 0;
}