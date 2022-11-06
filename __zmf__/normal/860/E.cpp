/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 5e5 + 9;
int fa[N][22], n, rt, dep[N], ans[N], val[N];
vector<int> G[N], p[N];
struct node
{
	int u, val, pos;
};
node sta[N];
inline void dfs1(int u, int f)
{
	fa[u][0] = f; dep[u] = dep[f] + 1;
	p[dep[u]].push_back(u);
	for (int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : G[u])
		if(v != f)
			dfs1(v, u);
}
inline void dfs2(int u, int f)
{
	ans[u] += (ans[f] + dep[f]);
	for (auto v : G[u]) 
		if(v != f) dfs2(v, u);
}
inline int Lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for (int i = 20; i >= 0; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
inline void work(int now)
{
	int top = 0; int cnt = 0, res = 0;
	for (auto u : p[now])
	{
		cnt++;
		if(!top) sta[++top] = (node){u, 0, cnt};
		else
		{
			while(top)
			{
				int r = Lca(u, sta[top].u);
				if(dep[r] >= sta[top].val) 
				{
					sta[++top] = (node){u, dep[r], cnt}; break;
				}
				res -= (sta[top].pos - sta[top - 1].pos) * sta[top].val;
				top--;
			}
			res += (sta[top].pos - sta[top - 1].pos) * sta[top].val;
		}
		ans[u] += res;
	}
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		if(!x) rt = i;
		else G[x].push_back(i);
	}
	dfs1(rt, 0);
	for (int i = 1; i <= n; i++)
		if(p[i].size() > 1)
		{
			work(i);
			reverse(p[i].begin(), p[i].end());
			work(i);
		}
//	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	dfs2(rt, 0);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}