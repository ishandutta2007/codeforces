/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
*/

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9, M = 6e6 + 9;
int n, q, Rt, rt[N], fa[N][20], dep[N], ans[N], r[N];
int cnt;
vector<int> G[N];
struct node
{
	int id, d;
};
struct Tree
{
	int ls, rs, v;
}tree[M];
vector<node> Q[N];
inline void dfs1(int u, int f) 
{
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : G[u]) 
		if(v != f) dfs1(v, u);
}
inline void push_up(int p) {tree[p].v = tree[tree[p].ls].v + tree[tree[p].rs].v;}
inline int update(int id, int l, int r, int pos) 
{
	if(!id) id = ++cnt;
	if(l == r) 
	{
		tree[id].v++; return id;
	}
	int mid = (l + r) >> 1;
	if(mid >= pos) tree[id].ls = update(tree[id].ls, l, mid, pos);
	else tree[id].rs = update(tree[id].rs, mid + 1, r, pos);
	push_up(id);
	return id;
}
inline int Merge(int x, int y, int l, int r) 
{
	if(!x || !y) return x + y;
	if(l == r) 
	{
		tree[x].v += tree[y].v;
		return x;
	}
	int mid = (l + r) >> 1;
	tree[x].ls = Merge(tree[x].ls, tree[y].ls, l, mid);
	tree[x].rs = Merge(tree[x].rs, tree[y].rs, mid + 1, r);
	push_up(x);
	return x;
}
inline int query(int id, int l, int r, int pos) 
{
	if(l == r) return tree[id].v;
	int mid = (l + r) >> 1;
	if(mid >= pos) return query(tree[id].ls, l, mid, pos);
	else return query(tree[id].rs, mid + 1, r, pos);
}
inline void dfs2(int u, int f) 
{
	for (auto v : G[u]) 
		if(v != f) 
		{
			dfs2(v, u);
			rt[u] = Merge(rt[u], rt[v], 1, n);
		}
	for (auto v : Q[u]) 
		ans[v.id] = query(rt[u], 1, n, v.d);
	return ;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		r[i] = read();
		if(r[i])
		{
			G[i].push_back(r[i]); G[r[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) 
		if(!r[i]) dfs1(i, 0);
	q = read();
	for (int i = 1; i <= q; i++) 
	{
		int v = read(), p = read();
		int D = dep[v];
		for (int j = 19; j >= 0; j--) 
			if(p & (1 << j)) v = fa[v][j];
		if(!v) continue;
		Q[v].push_back(node{i, D});
	}
	for (int i = 1; i <= n; i++) rt[i] = update(rt[i], 1, n, dep[i]);
	for (int i = 1; i <= n; i++) 
		if(!r[i]) dfs2(i, 0);
	for (int i = 1; i <= q; i++) 
		printf("%d ", max(0, ans[i] - 1));
	return 0;
}