#include <bits/stdc++.h>
typedef long long ll;
#define int ll
using namespace std;
const int MAXN = 1005;
int a[1001], sum[1001], f[1001][1001];
int Work(int a, int b, int c, int d)
{
	if(a > c)
		swap(a, c), swap(b, d);
	if(b < c)
		return 0;
	else if(b < d)
		return b - c + 1;
	return d - c + 1;
}
signed main()
{
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i] * ((i & 1) ? 1 : -1);
	memset(f, 0x3f, sizeof(f));
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int now = 0;
		for(int j = i; j <= n; j++)
		{
			now += a[j] * ((j & 1) ? 1 : -1);
			f[i][j] = min(now, f[i][j - 1]);
		}
	}
	for(int l = 1; l <= n; l++)
	{
		for(int r = l + 1; r <= n; r++)
		{
			int s = sum[r - 1] - sum[l];
			int L, R;
			if(r & 1)
				L = -s - 1, R = -s - a[r];
			else
				L = -s + 1, R = -s + a[r];
			if(l & 1)
			{
				int res = max(1ll, -f[l + 1][r - 1]);
				if(res <= a[l])
					ans += Work(res, a[l], L, R);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}