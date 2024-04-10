#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, Deg[N], Cnt[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Deg[u] ++, Deg[v] ++;
	}
	for (int i = 1; i <= n; i ++)
		Cnt[Deg[i]] ++;
	if (Cnt[1] + Cnt[2] < n - 1) puts("No");
	else if (Cnt[1] + Cnt[2] == n - 1)
	{
		puts("Yes");
		int rt = 0;
		for (int i = 1; !rt && i <= n; i ++)
			if (Deg[i] > 2) rt = i;
		printf("%d\n", Deg[rt]);
		for (int i = 1; i <= n; i ++)
			if (Deg[i] == 1)
				printf("%d %d\n", rt, i);
	}
	else
	{
		puts("Yes");
		int u = 0, v = 0;
		for (int i = 1; i <= n; i ++)
			if (Deg[i] == 1)
			{
				v = i;
				if (!u) swap(u, v);
			}
		puts("1");
		printf("%d %d\n", u, v);
	}
	return 0;
}