#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;
const int maxn = 200000;

int n, mn1[N], mn2[N], tot, prime[N], low[N], cnt[N];
bool not_prime[N];

void get_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i]) prime[++tot] = i, low[i] = tot;
		for (int j = 1; j <= tot && i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = 1;
			low[i * prime[j]] = j;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
	get_prime(maxn);
	for (int i = 1; i <= tot; i++) mn1[i] = mn2[i] = 100;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		while (x > 1)
		{
			int id = low[x], s = 0;
			cnt[id]++;
			while (x % prime[id] == 0) x /= prime[id], s++;
			if (s < mn1[id]) mn2[id] = mn1[id], mn1[id] = s;
			else if (s < mn2[id]) mn2[id] = s;
		}
	}
	LL ans = 1;
	for (int i = 1; i <= tot; i++)
	{
		if (n - cnt[i] >= 2) continue;
		if (n - cnt[i] == 1) mn2[i] = 0;
		if (n - cnt[i] == 0) mn1[i] = 0;
		for (int j = 1; j <= mn1[i] + mn2[i]; j++)
			ans *= prime[i];
	}
	printf("%lld\n", ans);
	return 0;
}