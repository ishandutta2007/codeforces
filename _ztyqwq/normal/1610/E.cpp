#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == a[i - 1])
				continue;
			int tot = 2, u = i + 1;
			while(true)
			{
				int v = lower_bound(a + u + 1, a + n + 1, a[u] * 2 - a[i])  - a;
				if(v > n)
					break;
				tot++;
				u = v;
			}
			ans = max(ans, tot);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}