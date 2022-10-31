#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[200010];
int ecnt = 0, head[100010];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int d[100010], pre[100010];
int cycle_u, cycle_v;
vector<int> pts;
void dfs(int u)
{
	pts.push_back(u);
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre[u])
			continue;
		if(pre[v])
		{
			cycle_u = u;
			cycle_v = v;
			return;
		}
		pre[v] = u;
		dfs(v);
		if(cycle_u != -1)
			return;
	}
}
int ans[100010];
inline void Print(int n)
{
	printf("YES\n");
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	putchar('\n');
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			head[i] = -1, d[i] = pre[i] = ans[i] = 0;
		ecnt = 0;
		while(m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v);
			addedge(v, u);
			d[u]++, d[v]++;
		}
		for(int st = 1; st <= n; st++)
			if(!pre[st])
			{
				pre[st] = st;
				cycle_u = cycle_v = -1;
				pts.clear();
				dfs(st);
				if(cycle_u != -1)
				{
					int now = cycle_u;
					while(now != cycle_v)
						ans[now] = 1, now = pre[now];
					ans[now] = 1;
					Print(n);
					goto end;
				}
				for(auto x: pts)
					if(d[x] >= 4)
					{
						ans[x] = 2;
						for(int i = head[x]; i != -1; i = e[i].nxt)
							ans[e[i].to] = 1;
						Print(n);
						goto end;
					}
				int p3 = -1;
				for(auto x: pts)
					if(d[x] == 3)
					{
						if(p3 == -1)
							p3 = x;
						else
						{
							for(auto y: pts)
								pre[y] = 0;
							pre[p3] = p3;
							cycle_u = cycle_v = -1;
							pts.clear();
							dfs(p3);
							int now = x;
							while(now != p3)
								ans[now] = 2, now = pre[now];
							ans[now] = 2;
							for(int i = head[p3]; i != -1; i = e[i].nxt)
								if(!ans[e[i].to])
									ans[e[i].to] = 1;
							for(int i = head[x]; i != -1; i = e[i].nxt)
								if(!ans[e[i].to])
									ans[e[i].to] = 1;
							Print(n);
							goto end;
						}
					}
				if(p3 != -1)
				{
					vector<int> ps[3];
					for(int i = head[p3], j = 0; i != -1; i = e[i].nxt, j++)
					{
						int s = e[i].to, prev = p3;
						ps[j].push_back(p3);
						ps[j].push_back(s);
						bool flag = true;
						while(flag)
						{
							flag = false;
							for(int ii = head[s]; ii != -1; ii = e[ii].nxt)
							{
								int ss = e[ii].to;
								if(ss != prev)
								{
									prev = s, s = ss;
									ps[j].push_back(s);
									if(ps[j].size() < 10)
										flag = true;
									break;
								}
							}
						}
					}
					if(1.0 / ps[0].size() + 1.0 / ps[1].size() + 1.0 / ps[2].size() <= 1.0)
					{
						ans[p3] = 2520;
						for(int j = 0; j < 3; j++)
						{
							int len = ps[j].size();
							for(int i = 0; i < len; i++)
								ans[ps[j][i]] = 2520 * (len - i) / len;
						}
						Print(n);
						goto end;
					}
				}
			}
		printf("NO\n");
		end:;
	}
	return 0;
}