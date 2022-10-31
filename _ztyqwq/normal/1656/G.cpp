#include <bits/stdc++.h>
using namespace std;
int a[200010];
int pre[200010], pos[200010], b[200010];
vector<int> num[200010];
int f[200010], ans[200010];
inline int Root(int x)
{
	return f[x] == x ? x : f[x] = Root(f[x]);
}
inline void Link(int x, int y)
{
	int rx = Root(x), ry = Root(y);
	if(rx != ry)
		f[rx] = ry;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
			pre[i] = 0, num[i].clear(), f[i] = i;
		int pl = 0, pr = n + 1;
		for(int i = 1; i <= n; i++)
		{
			num[a[i]].push_back(i);
			if(pre[a[i]])
			{
				pos[pre[a[i]]] = ++pl;
				pos[i] = --pr;
				pre[a[i]] = 0;
			}
			else
				pre[a[i]] = i;
		}
		bool flag = false;
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(pre[i])
			{
				pos[pre[i]] = ++pl;
				if((++cnt) >= 2)
				{
					printf("NO\n"), flag = true;
					break;
				}
			}
		if(flag)
			continue;
		for(int i = 1; i <= n; i++)
			b[pos[i]] = i;
		for(int i = 1; i <= n; i++)
			Link(i, pos[i]);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < int(num[i].size()) - 1; j++)
			{
				int u = num[i][j], v = num[i][j + 1];
				if(Root(u) != Root(v))
				{
					swap(b[pos[u]], b[pos[v]]);
					swap(pos[u], pos[v]);
					Link(u, pos[u]);
				}
			}
		int rt = 1;
		if(b[n + 1 - pos[rt]] == rt)
			rt++;
		for(int i = 1; i <= n; i++)
			if(Root(i) != Root(rt))
			{
				int u = rt, v = i, ru = b[n + 1 - pos[u]], rv = b[n + 1 - pos[v]];
				if(ru == u || rv == v)
					continue;
				swap(b[pos[u]], b[pos[v]]), swap(pos[u], pos[v]);
				swap(b[pos[ru]], b[pos[rv]]), swap(pos[ru], pos[rv]);
				swap(b[pos[v]], b[pos[rv]]), swap(pos[v], pos[rv]);
				Link(u, pos[u]);
			}
		int r1 = Root(1);
		for(int i = 2; i <= n; i++)
			if(Root(i) != r1)
			{
				printf("NO\n"), flag = true;
				break;
			}
		if(flag)
			continue;
		printf("YES\n");
		for(int i = 1; i <= n; i++)
			ans[pos[i]] = i;
		for(int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}