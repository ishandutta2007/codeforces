#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, f[N];
bool vis[N];
char str[N];

int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", str + 1);
		int ans = 0, now = 2;
		for (int i = 0; i <= n; i++) vis[i] = 0, f[i] = i;
		for (int i = 1; i <= n; i++) if (!vis[i])
		{
			ans++;
			while (now <= n)
			{
				if (!vis[now] && find(now - 1) && str[now] == str[find(now - 1)]) break;
				now++;
			}
			if (now <= n) vis[now] = 1, f[now] = now - 1;
			else vis[i] = 1, f[i] = i - 1;
			while (i <= n && vis[i]) i++;
			if (i > n) break;
			char c = str[i];
			while (i <= n && (vis[i] || str[i] == c)) vis[i] = 1, f[i] = min(f[i], i - 1), i++;
			i--;
		}
		printf("%d\n", ans);
	}
	return 0;
}