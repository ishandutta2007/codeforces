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
const int N = 2e5 + 9, M = 1e7 + 9;
struct SegmentTree
{
	int cnt = 0; 
	struct Tree 
	{
		int lc, rc, v;
	}tree[M];
	inline int lc(int p) {return tree[p].lc;}
	inline int rc(int p) {return tree[p].rc;}
	inline void push_up(int p) {tree[p].v = tree[lc(p)].v + tree[rc(p)].v;}
	inline void upd(int &p, int l, int r, int pos, int v) 
	{
		if(!p) p = ++cnt;
		if(l == r) {tree[p].v += v; return ;}
		int mid = (l + r) >> 1;
		if(mid >= pos) upd(tree[p].lc, l, mid, pos, v);
		else upd(tree[p].rc, mid + 1, r, pos, v);
		push_up(p);
	}
	inline int Merge(int x, int y, int l, int r)
	{
		if(!x || !y) return x + y;
		int qwq = ++cnt; 
		if(l == r) {tree[qwq].v = tree[x].v + tree[y].v; return x;}
		int mid = (l + r) >> 1;
		tree[qwq].lc = Merge(lc(x), lc(y), l, mid); 
		tree[qwq].rc = Merge(rc(x), rc(y), mid + 1, r);
		push_up(qwq); return qwq;
	}
	inline int query(int p, int l, int r, int L, int R)
	{
		if(R < L) return 0;
		if(L <= l && r <= R) return tree[p].v;
		int res = 0, mid = (l + r) >> 1;
		if(mid >= L) res += query(lc(p), l, mid, L, R);
		if(mid < R) res += query(rc(p), mid + 1, r, L, R);
		return res;
	}
}T;
struct SAM
{
	int nxt[28], len, link;
}tree[N];
int rt[N], mx, mc;
vector<int> G[N];
int pt = 1, lst = 1, len, n, l, r;
inline void add(int c, int id) 
{
	int now = ++pt;
	for (;lst && !tree[lst].nxt[c]; lst = tree[lst].link) tree[lst].nxt[c] = now;
	if(!lst) tree[now].link = 1;
	else 
	{
		int q = tree[lst].nxt[c];
		if(tree[q].len == tree[lst].len + 1) tree[now].link = q; 
		else 
		{
			int cl = ++pt;
			tree[cl] = tree[q]; tree[cl].len = tree[lst].len + 1;
			for (;lst && tree[lst].nxt[c] == q; lst = tree[lst].link) tree[lst].nxt[c] = cl;
			tree[q].link = tree[now].link = cl;
		}
	}
	lst = now; T.upd(rt[now], 1, n, id, 1);
	return ;
}
char s[N];
inline void dfs1(int u) 
{
	for (auto v : G[u]) 
	{
		dfs1(v); rt[u] = T.Merge(rt[u], rt[v], 1, n);
	} return ;
}
inline void dfs2(int now, int dep)
{
	if(dep > len) return ;
	int st = s[dep + 1] - 'a' + 1; 
	if(dep == len) st = 0;
//	cout << dep << " " << st << endl;
	for (int i = st + 1; i <= 26; i++) 
	{
		if(T.query(rt[tree[now].nxt[i]], 1, n, l + dep, r)) 
		{
			mx = dep; mc = i; break;
		}
	}
	if(T.query(rt[tree[now].nxt[st]], 1, n, l + dep, r)) dfs2(tree[now].nxt[st], dep + 1);
}
signed main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) add(s[i] - 'a' + 1, i);
	for (int i = 1; i <= pt; i++) G[tree[i].link].push_back(i);
	dfs1(1);
	int Q = read();
	for (int i = 1; i <= Q; i++) 
	{
		l = read(), r = read(); 
		mx = mc = 0;
		scanf("%s", s + 1); len = strlen(s + 1);
		dfs2(1, 0);
		if(!mx && !mc) puts("-1");
		else 
		{
			for (int j = 1; j <= mx; j++) putchar(s[j]); putchar(mc + 'a' - 1); puts("");
		}
	}
	return 0;
}