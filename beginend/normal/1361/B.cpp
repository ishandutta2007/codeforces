#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000005;
const int MOD = 1000000007;

int n, p, a[N], s[N], c[N];

int ksm(int x, int y)
{
	int ans = 1;
	while (y)
	{
		if (y & 1) ans = (LL)ans * x % MOD;
		x = (LL)x * x % MOD; y >>= 1;
	}
	return ans;
}

void dec(int & mx, int x)
{
	if (mx > x + 20)
	{
		c[x] -= 1;
		return;
	}
	int y = x;
	while (!c[y]) y++;
	c[y]--;
	for (int i = x; i < y; i++) c[i] += p - 1;
	while (mx >= x && !c[mx]) mx--;
	if (mx < x) mx = -1;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &p);
		if (p == 1)
		{
			for (int i = 1, x; i <= n; i++) scanf("%d", &x);
			printf("%d\n", (n & 1) ? 1 : 0);
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			s[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		int m = unique(a + 1, a + n + 1) - a - 1, mx = -1;
		for (int i = m; i >= 1; i--)
		{
			if (mx == -1)
			{
				if (s[a[i]] & 1) mx = a[i], c[a[i]] = 1;
			}
			else
			{
				while (s[a[i]] && mx >= 0) dec(mx, a[i]), s[a[i]]--;
				if (mx == -1 && (s[a[i]] & 1)) mx = a[i], c[a[i]] = 1;
			}
		}
		int ans = 0;
		for (int i = max(0, mx - 20); i <= mx; i++)
			if (c[i]) (ans += (LL)ksm(p, i) * c[i] % MOD) %= MOD, c[i] = 0;
		for (int i = 1; i <= m; i++)
			if (c[a[i]]) (ans += (LL)ksm(p, a[i]) * c[a[i]] % MOD) %= MOD, c[a[i]] = 0;
		printf("%d\n", (ans + MOD) % MOD);
		for (int i = 1; i <= m; i++) s[a[i]] = 0;
	}
	return 0;
}