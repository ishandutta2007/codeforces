#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x, a[N], b[N];
char str[N];
int vis[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str + 1);
		n = strlen(str + 1);
		scanf("%d", &x);
		int tot = 0;
		bool flag = 0;
		for (int i = 1; i <= n; i++) vis[i] = -1;
		for (int i = 1; i <= n; i++)
			if (str[i] == '0')
			{
				if (i - x > 0) flag |= vis[i - x] == 1, vis[i - x] = 0;
				if (i + x <= n) flag |= vis[i + x] == 1, vis[i + x] = 0;
			}
			else
			{
				if (i - x > 0 && i + x <= n) a[++tot] = i - x, b[tot] = i + x;
				else if (i - x > 0) flag |= vis[i - x] == 0, vis[i - x] = 1;
				else if (i + x <= n) flag |= vis[i + x] == 0, vis[i + x] = 1;
				else flag = 1;
			}
		for (int i = 1; i <= tot; i++)
			if (!vis[a[i]] && !vis[b[i]]) flag = 1;
		if (flag) {puts("-1"); continue;}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] < 0) vis[i] = 1;
			putchar(vis[i] + '0');
		}
		puts("");
	}
	return 0;
}