#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 80;
const int inf = 1e9;

int n, k, f[N][N], pre[N][N], seq[N];
struct data{int x, y, id;}a[N];

bool cmp(data a, data b)
{
	return a.y < b.y;
}

void work()
{
	int p1 = n, p2 = n - 1;
	for (int i = n, j = k; i; j = pre[i][j], i--)
		if (pre[i][j] == j) seq[p2--] = a[i].id;
		else if (p1 == n) seq[p1] = a[i].id, p1 = k - 1;
		else seq[p1--] = a[i].id;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				f[i][j] = -inf;
		f[0][0] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= k; j++) if (f[i][j] > -inf)
			{
				LL w = f[i][j] + a[i + 1].y * (k - 1);
				if (w > f[i + 1][j]) f[i + 1][j] = w, pre[i + 1][j] = j;
				if (j == k) continue;
				w = f[i][j] + a[i + 1].x + a[i + 1].y * j;
				if (w > f[i + 1][j + 1]) f[i + 1][j + 1] = w, pre[i + 1][j + 1] = j;
			}
		work();
		printf("%d\n", n + n - k);
		for (int i = 1; i < k; i++) printf("%d ", seq[i]);
		for (int i = k; i < n; i++) printf("%d %d ", seq[i], -seq[i]);
		printf("%d\n", seq[n]);
	}
	return 0;
}