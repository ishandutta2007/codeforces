#include <bits/stdc++.h>
using namespace std;
int a[1000010], sum[1000010], ans[1000010];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int tot = 0;
	for(int i = 1; i <= m; i++)
		scanf("%d", &a[i]), tot += a[i];
	a[m] += (n - tot % n) % n, tot = (tot - 1) / n + 1;
	printf("%d\n", tot);
	sum[0] = 0;
	for(int i = 1; i <= m; i++)
		sum[i] = (sum[i - 1] + a[i] - 1) % n + 1;
	sort(sum + 1, sum + m + 1);
	sum[m + 1] = n;
	for(int i = 1; i <= m; i++)
		ans[i] = sum[i] - sum[i - 1];
	for(int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	putchar('\n');
	int pos = 1;
	for(int i = 1; i <= tot; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("%d ", pos);
			a[pos] -= ans[j];
			while(pos < m && !a[pos])
				pos++;
		}
		putchar('\n');
	}
	return 0;
}