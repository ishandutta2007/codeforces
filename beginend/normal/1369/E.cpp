#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, w[N], a[N], b[N];
bool vis[N];
set<int> p[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		p[a[i]].insert(i);
		p[b[i]].insert(i);
	}
	queue<int> que;
	for (int i = 1; i <= n; i++) if (p[i].size() <= w[i]) que.push(i), vis[i] = 1;
	vector<int> ans;
	while (!que.empty())
	{
		int id = que.front(); que.pop();
		queue<int> tmp;
		for (int x : p[id]) tmp.push(x), ans.push_back(x);
		while (!tmp.empty())
		{
			int x = tmp.front(); tmp.pop();
			p[a[x]].erase(x);
			p[b[x]].erase(x);
			if (!vis[a[x]] && p[a[x]].size() <= w[a[x]]) que.push(a[x]), vis[a[x]] = 1;
			if (!vis[b[x]] && p[b[x]].size() <= w[b[x]]) que.push(b[x]), vis[b[x]] = 1;
		}
	}
	if (ans.size() != m) puts("DEAD");
	else
	{
		puts("ALIVE");
		for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
			printf("%d ", *it);
	}
	return 0;
}