#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int N = 500005;

int n, m, col[N], dis[N];
queue<int> que;
vector<pi> e[N];

void bfs()
{
	for (int i = 1; i < n; i++) dis[i] = n + 1;
	que.push(n);
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		for (pi to : e[x])
			if (!col[to.first]) col[to.first] = (to.second ^ 1) + 1;
			else if (col[to.first] == to.second + 1 && dis[x] + 1 < dis[to.first])
			{
				dis[to.first] = dis[x] + 1;
				que.push(to.first);
			}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		e[y].push_back(make_pair(x, z));
	}
	bfs();
	printf("%d\n", dis[1] < n ? dis[1] : -1);
	for (int i = 1; i <= n; i++) printf("%d", col[i] ? col[i] - 1 : col[i]);
	return 0;
}