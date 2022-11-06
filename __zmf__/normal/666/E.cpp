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
const int N = 1e6 + 2e5 + 9, M = 3e7 + 9;
struct SegMentTree
{
	int cnt = 0;
	struct Tree
	{
		int mx, mxc, lc, rc;
	}tree[M];
	inline int lc(int p) {return tree[p].lc;}
	inline int rc(int p) {return tree[p].rc;}
	inline void Max(Tree &x, Tree y) 
	{
		if(y.mx > x.mx || (y.mx == x.mx && y.mxc < x.mxc)) x.mx = y.mx, x.mxc = y.mxc;
	}
	inline void push_up(int p) 
	{
		tree[p].mx = tree[p].mxc = 0;
		Max(tree[p], tree[lc(p)]); Max(tree[p], tree[rc(p)]); return ;
	}
	inline void upd(int &p, int l, int r, int pos, int v) 
	{
	//	cout << p << " " << l << " " << r << endl;
		if(!p) p = ++cnt;
		if(l == r) {tree[p].mx += v, tree[p].mxc = l; return ;}
		int mid = (l + r) >> 1;
		if(mid >= pos) upd(tree[p].lc, l, mid, pos, v);
		else upd(tree[p].rc, mid + 1, r, pos, v);
		push_up(p); return ;
	}
	inline int Merge(int x, int y, int l, int r) 
	{
		if(!x || !y) return x + y;
		int nd = ++cnt;
		if(l == r) 
		{
			tree[nd] = tree[x]; tree[nd].mx += tree[y].mx; return nd;
		}
		int mid = (l + r) >> 1;
		tree[nd].lc = Merge(lc(x), lc(y), l, mid);
		tree[nd].rc = Merge(rc(x), rc(y), mid + 1, r);
		push_up(nd); return nd;
	}
	inline Tree query(int p, int l, int r, int L, int R) 
	{
		if(L <= l && r <= R) return tree[p];
		Tree res; res.mx = res.mxc = 0;
		int mid = (l + r) >> 1;
		if(mid >= L) Max(res, query(lc(p), l, mid, L, R));
		if(mid < R) Max(res, query(rc(p), mid + 1, r, L, R));
		return res;
	}
}T;
struct SAM
{
	int nxt[28], link, len;
}tree[N];
int rt[N], mark[N];
int fa[N][23];
int pt = 1, lst = 1;
int n, m;
char s[N];
vector<int> G[N];
inline void add(int c, int col, int Mark) 
{
	int now = ++pt; tree[now].len = tree[lst].len + 1;
	for (;lst && !tree[lst].nxt[c]; lst = tree[lst].link) tree[lst].nxt[c] = now;
	if(!lst) tree[now].link = 1;
	else 
	{
		int q = tree[lst].nxt[c];
		if(tree[q].len == tree[lst].len + 1) tree[now].link = q;
		else 
		{
			int cl = ++pt; tree[cl] = tree[q]; tree[cl].len = tree[lst].len + 1;
			for (;lst && tree[lst].nxt[c] == q; lst = tree[lst].link) tree[lst].nxt[c] = cl;
			tree[now].link = tree[q].link = cl;
		}
	}
	lst = now; mark[Mark] = now;
	if(col) T.upd(rt[now], 1, m, col, 1); 
	return ;
}
inline void dfs(int u) 
{
	for (int i = 1; i <= 22; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : G[u]) 
	{
		fa[v][0] = u; dfs(v); rt[u] = T.Merge(rt[u], rt[v], 1, m);
	}return ;
}
inline int jump(int l, int r) 
{
	int now = mark[r], len = r - l + 1; 
	for (int i = 22; i >= 0; i--) 
		while(tree[fa[now][i]].len >= len) now = fa[now][i];
//	cout << tree[now].len << endl;
	return now;
}// 
signed main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) add(s[i] - 'a' + 1, 0, i); 
	m = read();add('z' - 'a' + 2, 0, 0);
	for (int i = 1; i <= m; i++) 
	{
		scanf("%s", s + 1); 
		int nn = strlen(s + 1); 
		for (int j = 1; j <= nn; j++) add(s[j] - 'a' + 1, i, 0);
		add('z' - 'a' + 2, 0, 0);
	} 
	for (int i = 1; i <= pt; i++) G[tree[i].link].push_back(i);
	dfs(1); 
	int Q = read();
	for (int i = 1; i <= Q; i++) 
	{
		int l = read(), r = read(), pl = read(), pr = read();
		int now = jump(pl, pr);
		printf("%d %d\n", max(l, T.query(rt[now], 1, m, l, r).mxc), T.query(rt[now], 1, m, l, r).mx);
	} 
	return 0;
}