#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int c[100001];
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &c[i]);
		int ans[2], sum[2], mn[2];
		sum[1] = mn[1] = c[1], sum[0] = mn[0] = c[2];
		ans[1] = c[1] * n, ans[0] = c[2] * n;
		int res = ans[0] + ans[1];
		for(int i = 3; i <= n; i++)
		{
			int p = (i & 1);
			sum[p] += c[i];
			mn[p] = min(mn[p], c[i]);
			ans[p] = sum[p] + mn[p] * ((n - (i + 1) / 2));
			res = min(res, ans[0] + ans[1]);
		}
		printf("%lld\n", res);
	}
	return 0;
}