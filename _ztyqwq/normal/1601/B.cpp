#include <bits/stdc++.h>
using namespace std;
int n, mx;
struct Edge
{
	int to, nxt, val;
}e[15000010];
int ecnt = 0, head[1500010];
inline void addedge(int from, int to, int val)
{
	e[ecnt].to = to;
	e[ecnt].val = val;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int a[300010], b[300010];
inline void Get(int u, int l, int r, int L, int R, vector<int>& es)
{
	if(r < L || R < l)
		return;
	if(L <= l && r <= R)
	{
		es.push_back(u);
		return;
	}
	int mid = (l + r) >> 1;
	Get(u << 1, l, mid, L, R, es);
	Get(u << 1 | 1, mid + 1, r, L, R, es);
}
int yes[1500010];
inline void Build(int u, int l, int r)
{
	if(l == r)
	{
		yes[u] = l;
		addedge(u, mx + l + b[l], 0);
		return;
	}
	addedge(u, u << 1, 0);
	addedge(u, u << 1 | 1, 0);
	int mid = (l + r) >> 1;
	Build(u << 1, l, mid);
	Build(u << 1 | 1, mid + 1, r);
}
deque<int> q;
bool vis[1500010];
int pre[1500010], dis[1500010];
int main()
{
	// freopen("B.in", "r", stdin);
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	mx = n << 2;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	Build(1, 1, n);
	for(int i = 1; i <= n; i++)
	{
		vector<int> vec;
		Get(1, 1, n, max(1, i - a[i]), i, vec);
		for(auto x: vec)
			addedge(mx + i, x, 1);
		if(i - a[i] <= 0)
			addedge(mx + i, 0, 1);
	}
	for(int i = 0; i <= 5 * n; i++)
		dis[i] = 0x7fffffff;
	dis[mx + n] = 0;
	q.push_back(mx + n);
	while(!q.empty())
	{
		int u = q.front();
		q.pop_front();
		if(vis[u])
			continue;
		vis[u] = true;
		if(u == 0)
		{
			int p = 0;
			stack<int> stk;
			while(p != mx + n)
			{
				if(yes[p])
					stk.push(yes[p]);
				p = pre[p];
			}
			printf("%d\n", dis[u]);
			while(!stk.empty())
			{
				printf("%d ", stk.top());
				stk.pop();
			}
			printf("0\n");
			return 0;
		}
		for(int i = head[u]; i != -1; i = e[i].nxt)
		{
			int v = e[i].to;
			if(dis[v] <= dis[u] + e[i].val)
				continue;
			dis[v] = dis[u] + e[i].val;
			pre[v] = u;
			if(e[i].val)
				q.push_back(v);
			else
				q.push_front(v);
		}
	}
	printf("-1\n");
	return 0;
}