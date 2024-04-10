#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, p[N], h[N], s[N], les[N];
bool flag;
vector<int> e[N];

void dfs(int x, int fa)
{
	les[x] = 0; s[x] = p[x];
	for (int to : e[x])
		if (to != fa) dfs(to, x), les[x] += les[to], s[x] += s[to];
	if ((s[x] + h[x]) % 2 != 0 || s[x] < h[x] || flag) {flag = 1; return;}
	int ned = (s[x] - h[x]) / 2;
	if (ned - p[x]> les[x]) {flag = 1; return;}
	les[x] = ned;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i]), e[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
		for (int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			e[x].push_back(y); e[y].push_back(x);
		}
		flag = 0;
		dfs(1, 0);
		puts(flag ? "NO" : "YES");
	}
	return 0;
}