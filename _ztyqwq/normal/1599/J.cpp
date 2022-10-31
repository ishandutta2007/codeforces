#include <bits/stdc++.h>
using namespace std;
int n, N, m;
int a[1010], ans[1010];
inline void get3(int u, int v, int w)
{
	ans[u] = (a[v] + a[w] - a[u]) / 2;
	ans[v] = (a[w] + a[u] - a[v]) / 2;
	ans[w] = (a[u] + a[v] - a[w]) / 2;
}
unordered_map<int, int> mp;
void dfs(int u, int now, int val, int cnt)
{
	if(u == N + 1)
	{
		assert(cnt == m);
		if(mp.find(val) != mp.end())
		{
			int ano = mp[val];
			vector<int> v1, v2;
			bool vis[30];
			memset(vis, false, sizeof(vis));
			for(int i = 1; i <= N; i++)
			{
				bool f1 = (now >> (N - i)) & 1, f2 = (ano >> (N - i)) & 1;
				if(f1 && !f2)
					v1.push_back(i), vis[i] = true;
				if(!f1 && f2)
					v2.push_back(i), vis[i] = true;
			}
			assert(v1.size() == v2.size());
			int len = v1.size();
			ans[0] = 0;
			for(int i = 0; i < len; i++)
			{
				ans[i * 2 + 1] = a[v1[i]] - ans[i * 2];
				ans[i * 2 + 2] = a[v2[i]] - ans[i * 2 + 1];
			}
			assert(ans[len * 2] == 0);
			len *= 2;
			for(int i = 1; i <= N; i++)
				if(!vis[i])
					ans[++len] = a[i];
			for(int i = N + 1; i <= n; i++)
				ans[i] = a[i];
			printf("YES\n");
			for(int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			putchar('\n');
			exit(0);
		}
		mp[val] = now;
		return;
	}
	if(N - u >= m - cnt)
		dfs(u + 1, now << 1, val, cnt);
	if(cnt + 1 <= m)
		dfs(u + 1, now << 1 | 1, val + a[u], cnt + 1);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int od[3] = {0, 0, 0}, ev[3] = {0, 0, 0};
	for(int i = 1; i <= n; i++)
	{
		if(a[i] & 1)
		{
			for(int j = 0; j < 3; j++)
				if(!od[j])
				{
					od[j] = i;
					break;
				}
		}
		else
		{
			for(int j = 0; j < 3; j++)
				if(!ev[j])
				{
					ev[j] = i;
					break;
				}
		}
		int u = 0, v = 0, w = 0;
		if(ev[2])
			u = ev[0], v = ev[1], w = ev[2];
		else if(ev[0] && od[1])
			u = ev[0], v = od[0], w = od[1];
		if(u)
		{
			get3(u, v, w);
			for(int i = 1; i <= n; i++)
				if(i != u && i != v && i != w)
					ans[i] = a[i] - ans[u];
			printf("YES\n");
			for(int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			putchar('\n');
			return 0;
		}
	}
	N = min(n, 27), m = min(N / 2, 12);
	dfs(1, 0, 0, 0);
	printf("NO\n");
	return 0;
}