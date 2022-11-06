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
const int N = 6e5 + 9;
struct Tree
{
	int mx, tag;
}tree[N << 2];
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p) {tree[p].mx = max(tree[lc(p)].mx, tree[rc(p)].mx);}
inline void push_down(int p)
{
	if(tree[p].tag == 0) return ;
	tree[lc(p)].mx += tree[p].tag; tree[rc(p)].mx += tree[p].tag;
	tree[lc(p)].tag += tree[p].tag; tree[rc(p)].tag += tree[p].tag;
	tree[p].tag = 0;
}
inline void build(int l, int r, int p)
{
	if(l == r) 
	{
		tree[p].mx = l; return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lc(p));
	build(mid + 1, r, rc(p));
	push_up(p);
}
inline void update(int l, int r, int p, int L, int R, int v)
{
	if(L <= l && r <= R) 
	{
		tree[p].mx += v, tree[p].tag += v;
		return ;
	}
	int mid = (l + r) >> 1;
	push_down(p);
	if(mid >= L) update(l, mid, lc(p), L, R, v);
	if(mid < R) update(mid + 1, r, rc(p), L, R, v);
	push_up(p);
}
inline int query(int l, int r, int p, int L, int R) 
{
	if(L <= l && r <= R) return tree[p].mx;
	int mid = (l + r) >> 1, res = 0;
	push_down(p);
	if(mid >= L) res = max(res, query(l, mid, lc(p), L, R));
	if(mid < R) res = max(res, query(mid + 1, r, rc(p), L, R));
	return res;
}
map<int, int> mp[N];
multiset<int> s;
int n, k, m;
signed main()
{
	n = read(), k = read(), m = read();
	build(1, 2 * n, 1);
	s.insert(n + 1);
	for (int i = 1; i <= m; i++) 
	{
		int x = read(), y = read();
		if(!mp[x][y]) 
		{
			mp[x][y] = 1;
			int w = y + abs(x - k); s.insert(w);
		//	cout << w << "qwq" << endl;
			update(1, 2 * n, 1, 1, w, 1);
		}
		else
		{
		//	cout << "qwq" << endl;
			mp[x][y] = 0;
			int w = y + abs(x - k); s.erase(s.find(w));
			update(1, 2 * n, 1, 1, w, -1);
		}
		int g = (*s.rbegin());
		//cout << query(1, 2 * n, 1, 1, 5) << "qwq" << endl;
		//cout << g << endl;
		printf("%lld\n", max(0ll, query(1, 2 * n, 1, 1, g) - n - 1));
	}
	return 0;
}