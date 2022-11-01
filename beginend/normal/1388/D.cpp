#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, b[N], deg[N];
LL a[N], ans;
vector<int> e[N], u[N];

void dfs(int x)
{
	for (int to : e[x])
	{
		dfs(to);
		if (a[to] > 0) a[x] += a[to], u[to].push_back(x), deg[x]++;
		else u[x].push_back(to), deg[to]++;
	}
	ans += a[x];
}

void pri()
{
	queue<int> que;
	for (int i = 1; i <= n; i++) if (!deg[i]) que.push(i);
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		printf("%d ", x);
		for (int to : u[x])
		{
			deg[to]--;
			if (!deg[to]) que.push(to);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] != -1) e[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (b[i] == -1) dfs(i);
	printf("%lld\n", ans);
	pri();
	return 0;
}