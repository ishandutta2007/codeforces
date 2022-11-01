#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;
const LL inf = (LL)1e18;

int n;
LL a[N], b[N];

LL solve(int n)
{
	LL mx = 0, mn = 0;
	for (int i = 1; i <= n; i++)
	{
		b[i] += b[i - 1];
		mx = max(mx, b[i] - mn);
		mn = min(mn, b[i]);
	}
	return mx;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for (int i = 1; i <= n / 2; i++) b[i] = a[i * 2] - a[i * 2 - 1];
		LL ans = solve(n / 2);
		for (int i = 1; i <= (n - 1) / 2; i++) b[i] = a[i * 2] - a[i * 2 + 1];
		ans = max(ans, solve((n - 1) / 2));
		LL s = 0;
		for (int i = 1; i <= n; i++)
			if (i & 1) s += a[i];
		printf("%lld\n", s + ans);
	}
	return 0;
}