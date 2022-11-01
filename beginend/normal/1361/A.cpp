#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 500005;

int n, m, a[N], id[N];
bool vis[N];
vector<int> e[N];

int cmp(int x, int y)
{
	return a[x] < a[y];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		e[x].pb(y); e[y].pb(x);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		for (int x : e[id[i]]) vis[a[x]] = 1;
		for (int j = 1; j < a[id[i]]; j++)
			if (!vis[j])
			{
				puts("-1");
				return 0;
			}
		if (vis[a[id[i]]])
		{
			puts("-1");
			return 0;
		}
		for (int x : e[id[i]]) vis[a[x]] = 0;
	}
	for (int i = 1; i <= n; i++) printf("%d ", id[i]);
	return 0;
}