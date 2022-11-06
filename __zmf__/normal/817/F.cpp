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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 1e6 + 9, INF = 1e15;
int n;
struct node
{
	int opt, l, r;
}q[N];
int a[N], b[N], tot;
struct Tree
{
	int tag, cov, ans0, ans1;
}tree[N << 2];
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p) 
{
	tree[p].ans0 = min(tree[lc(p)].ans0, tree[rc(p)].ans0);
	tree[p].ans1 = min(tree[lc(p)].ans1, tree[rc(p)].ans1);
}
inline void push_down(int l, int r, int p) 
{
	int mid = (l + r) >> 1;
	if(tree[p].cov != -1) 
	{
		tree[lc(p)].tag = tree[rc(p)].tag = 0;
		tree[lc(p)].cov = tree[rc(p)].cov = tree[p].cov;
		if(tree[p].cov) 
		{
			tree[lc(p)].ans1 = l; tree[lc(p)].ans0 = INF;
			tree[rc(p)].ans1 = mid + 1, tree[rc(p)].ans0 = INF;
		}
		else
		{
			tree[lc(p)].ans0 = l; tree[lc(p)].ans1 = INF;
			tree[rc(p)].ans0 = mid + 1, tree[rc(p)].ans1 = INF;	
		}
		tree[p].cov = -1;
	}
	if(tree[p].tag) 
	{
		if(tree[lc(p)].cov != -1) tree[lc(p)].cov ^= 1;
		else tree[lc(p)].tag ^= 1;
		if(tree[rc(p)].cov != -1) tree[rc(p)].cov ^= 1; 
		else tree[rc(p)].tag ^= 1;
		swap(tree[lc(p)].ans0, tree[lc(p)].ans1);
		swap(tree[rc(p)].ans0, tree[rc(p)].ans1);
		tree[p].tag = 0;
		return ;
	}
}
inline void build(int l, int r, int p) 
{
	tree[p].cov = -1;
	if(l == r) 
	{
		tree[p].ans0 = l; tree[p].ans1 = INF; return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lc(p)); build(mid + 1, r, rc(p));
	push_up(p); return ;
}
inline void update(int l, int r, int p, int L, int R, int id) 
{
	if(L <= l && r <= R) 
	{
		if(id == 1) 
		{
			tree[p].tag = 0, tree[p].cov = 1;
			tree[p].ans0 = INF, tree[p].ans1 = l; 
		}
		else if(id == 2) 
		{
			tree[p].tag = 0, tree[p].cov = 0;
			tree[p].ans1 = INF, tree[p].ans0 = l;
		}
		else 
		{
			if(tree[p].cov != -1) tree[p].cov ^= 1;
			else tree[p].tag ^= 1;
			swap(tree[p].ans0, tree[p].ans1);
		}
		return ;
	}
	int mid = (l + r) >> 1;
	push_down(l, r, p);
	if(mid >= L) update(l, mid, lc(p), L, R, id);
	if(mid < R) update(mid + 1, r, rc(p), L, R, id);
	push_up(p);
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		q[i].opt = read(), q[i].l = read(), q[i].r = read();
		a[i * 2 - 1] = q[i].l, a[i * 2] = q[i].r;
	}
	sort(a + 1, a + n * 2 + 1);
	if(a[1] != 1) b[++tot] = 1;
	for (int i = 1; i <= n * 2; i++) 
		if(a[i] != a[i + 1]) 
		{
			b[++tot] = a[i];
			if(a[i + 1] != a[i] + 1) b[++tot] = a[i] + 1;
		}
//	for (int i = 1; i <= tot; i++) cout << b[i] << " "; cout << endl;
	build(1, tot, 1);
	for (int i = 1; i <= n; i++)
	{
		int l = lower_bound(b + 1, b + tot + 1, q[i].l) - b;
		int r = lower_bound(b + 1, b + tot + 1, q[i].r) - b;
	//	cout << l << " " << r << endl;
		update(1, tot, 1, l, r, q[i].opt);
		printf("%lld\n", b[tree[1].ans0]); 
	}
	return 0;
}
/*
6
1 3 6
1 1 2
2 3 4
2 1 2
3 1 3
3 4 4
*/