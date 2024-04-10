#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100005;

int m, q[N], w[N];
LL n;

LL get(int n)
{
	if (n & 1) return (LL)n * (n - 1) / 2 + 1;
	else return (LL)n * (n - 1) / 2 + (n - 1) / 2 + 1;
}

int main()
{
	scanf("%lld%d",  &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &q[i], &w[i]);
	sort(w + 1, w + m + 1);
	int k = 0;
	for (int i = m; i >= 1; i--)
		if (get(i) <= n)
		{
			k = i;
			break;
		}
	LL ans = 0;
	for (int i = 0; i < k; i++) ans += w[m - i];
	printf("%lld\n", ans);
	return 0;
}