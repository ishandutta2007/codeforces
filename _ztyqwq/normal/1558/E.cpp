#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
	int to, nxt;
}e[5001];
int head[1001], ecnt = 0;
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int a[1001], b[1001];
int vis[1001], pre[1001]; // vis = 0: un-vised, vis = 1: pre-vised, vis = 2: now-vising
bool pre0[1001];
set<int> inv;
void dfs(int u, int fa, ll now, bool p0)
{
	if(now < a[u])
		return;
	if(vis[u] == 0)
		now += b[u];
	p0 |= (vis[u] == 0);
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa || now <= a[v])
			continue;
		if(vis[v] == 2)
		{
			if(p0)
			{
				int uu = u;
				while(vis[uu] != 2)
				{
					if(vis[uu] == 0)
						inv.insert(uu);
					uu = pre[uu];
				}
			}
			continue;
		}
		else if(vis[v] == 1)
		{
			if(pre[v])
			{
				if(p0 || pre0[v])
				{
					int uu = u, vv = v;
					while(vis[uu] != 2)
					{
						if(vis[uu] == 0)
							inv.insert(uu);
						uu = pre[uu];
					}
					while(vis[vv] != 2)
					{
						if(vis[vv] == 0)
							inv.insert(vv);
						vv = pre[vv];
					}
				}
				continue;
			}
			pre[v] = u;
			pre0[v] = pre0[u];
			dfs(v, u, now, p0);
			if(inv.size())
				return;
		}
		else
		{
			if(pre[v]) // found
			{
				int uu = u, vv = v;
				while(vis[uu] != 2)
				{
					if(vis[uu] == 0)
						inv.insert(uu);
					uu = pre[uu];
				}
				while(vis[vv] != 2)
				{
					if(vis[vv] == 0)
						inv.insert(vv);
					vv = pre[vv];
				}
				return;
			}
			else
			{
				pre[v] = u;
				pre0[v] = true;
				dfs(v, u, now, p0);
				if(inv.size())
					return;
			}
		}
	}
}
inline bool check(int n, ll power)
{
	set<int> now;
	now.insert(1);
	int tot = 1;
	memset(vis, 0, sizeof(vis));
	while(tot < n)
	{
		memset(pre, 0, sizeof(pre));
		memset(pre0, false, sizeof(pre0));
		for(auto x: now)
			vis[x] = 2, pre[x] = x;
		inv.clear();
		for(auto x: now)
		{
			dfs(x, x, power, false);
			if(inv.size())
			{
				for(auto x: inv)
					power += b[x];
				for(auto x: now)
					vis[x] = 1;
				now = inv;
				tot += inv.size();
				break;
			}
		}
		if(!inv.size())
			return false;
	}
	return true;
}
int main()
{
	int testcase;
	scanf("%d", &testcase);
	while(testcase--)
	{
		memset(head, -1, sizeof(head));
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 2; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 2; i <= n; i++)
			scanf("%d", &b[i]);
		a[1] = b[1] = 0;
		while(m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		int L = 1, R = 1000000001;
		while(L < R)
		{
			int mid = (L + R) >> 1;
			if(check(n, mid))
				R = mid;
			else
				L = mid + 1;
		}
		printf("%d\n", L);
	}
	return 0;
}