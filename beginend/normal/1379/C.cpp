#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
LL s[N];
struct data{LL x, y;}a[N];

bool cmp(data x, data y)
{
	return x.x > y.x;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i].x;
		LL ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int l = 1, r = m;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (a[mid].x >= a[i].y) l = mid + 1;
				else r = mid - 1;
			}
			l--;
			if (l >= i)
			{
				if (l >= n) ans = max(ans, s[n]);
				else ans = max(ans, s[l] + a[i].y * (n - l));
			}
			else
			{
				if (l + 1 >= n) ans = max(ans, s[n]);
				else ans = max(ans, s[l] + a[i].x + a[i].y * (n - l - 1));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}