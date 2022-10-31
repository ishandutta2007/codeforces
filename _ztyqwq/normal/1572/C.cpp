#include <bits/stdc++.h>
using namespace std;
int a[3010], nxt[3010], ind[3010];
int f[3010][3010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			ind[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			nxt[ind[a[i]]] = i;
			ind[a[i]] = i;
		}
		for(int i = 1; i <= n; i++)
			nxt[ind[i]] = n + 1;
		for(int st = 1; st <= n; st++)
			for(int i = 1; i <= n - st + 1; i++)
			{
				int j = i + st - 1;
				f[i][j] = f[i + 1][j];
				for(int k = nxt[i]; k <= j; k = nxt[k])
					f[i][j] = max(f[i][j], f[i + 1][k - 1] + f[k][j] + 1);
			}
		printf("%d\n", n - 1 - f[1][n]);
	}
	return 0;
}