#include <bits/stdc++.h>
using namespace std;
int a[20];
int g[20][10010];
struct Num
{
	int tot, ind;
	bool operator < (const Num& ano) const
	{
		return tot < ano.tot;
	}
}b[10010], ans[10010];
int id[10010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			for(int j = 1; j <= m; j++)
				g[i][j] = (s[j - 1] == '1');
		}
		int mx = (1 << n), mxans = INT_MIN;
		for(int i = 0; i < mx; i++)
		{
			for(int j = 1; j <= m; j++)
				b[j] = {0, j};
			int res = 0;
			for(int j = 1; j <= n; j++)
			{
				int sn = ((i >> (j - 1)) & 1) ? 1 : -1;
				for(int k = 1; k <= m; k++)
					b[k].tot += g[j][k] * sn;
				res += -a[j] * sn;
			}
			sort(b + 1, b + m + 1);
			for(int j = 1; j <= m; j++)
				res += j * b[j].tot;
			if(res > mxans)
			{
				mxans = res;
				for(int j = 1; j <= m; j++)
					ans[j] = b[j];
			}
		}
		for(int i = 1; i <= m; i++)
			id[ans[i].ind] = i;
		for(int i = 1; i <= m; i++)
			printf("%d ", id[i]);
		putchar('\n');
	}
	return 0;
}