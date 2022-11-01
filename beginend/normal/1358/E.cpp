#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500005;

int n;
LL x, s[N], a[N];
int mn[N];

int main()
{
	scanf("%d", &n);
	int m = (n + 1) / 2;
	for (int i = 1; i <= m; i++) scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
	scanf("%lld", &x);
	if (x <= 0)
	{
		for (int i = 1; i <= n; i++) mn[i] = n;
		for (int i = 1; i <= m; i++)
		{
			int l = 0, r = n - m;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (s[m] - s[i - 1] + x * mid > 0) l = mid + 1;
				else r = mid - 1;
			}
			mn[n - i + 1] = min(mn[n - i + 1], m - i + 1 + l - 1);
		}
		int w = n;
		for (int i = n; i > n - m; i--)
		{
			w = min(w, mn[i]);
			if (w >= i)
			{
				printf("%d\n", i);
				return 0;
			}
		}
		puts("-1");
	}
	else
	{
		if (s[m] + x * (n - m) > 0) printf("%d\n", n);
		else
		{
			int mx = 0;
			for (int i = 1; i <= m; i++)
			{
				int l = 0, r = n - m;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (s[m] - s[i - 1] + x * mid > 0) r = mid - 1;
					else l = mid + 1;
				}
				if (r < n - m) mx = max(mx, m - i + 1 + r + 1);
				else mx = max(mx, n - i + 2);
			}
			if (mx > n) puts("-1");
			else printf("%d\n", mx);
		}
	}
	return 0;
}