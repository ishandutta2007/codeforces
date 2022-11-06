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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 4e5 + 9, mod = 1e9 + 7;
int n, q;
int pr[309], to[309], cnt, a[N], v[66]; 
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
struct Tree
{
	int mul, tagmul;
	int fac, tagfac;
}tree[N << 2];
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p) 
{
	tree[p].mul = tree[lc(p)].mul * tree[rc(p)].mul % mod;
	tree[p].fac = (tree[lc(p)].fac | tree[rc(p)].fac);
}
inline void push_down(int l, int r, int p)
{
	int mid = (l + r) >> 1;
	if(tree[p].tagmul != 1) 
	{
		tree[lc(p)].tagmul = tree[lc(p)].tagmul * tree[p].tagmul % mod;
		tree[rc(p)].tagmul = tree[rc(p)].tagmul * tree[p].tagmul % mod;
		tree[lc(p)].mul = tree[lc(p)].mul * Pow(tree[p].tagmul, mid - l + 1) % mod;
		tree[rc(p)].mul = tree[rc(p)].mul * Pow(tree[p].tagmul, r - mid) % mod;
		tree[p].tagmul = 1;
	}
	if(tree[p].tagfac) 
	{
		tree[lc(p)].tagfac |= tree[p].tagfac;
		tree[rc(p)].tagfac |= tree[p].tagfac;
		tree[lc(p)].fac |= tree[p].tagfac;
		tree[rc(p)].fac |= tree[p].tagfac;
		tree[p].tagfac = 0;
	}
	return ;
}
inline void build(int l, int r, int p) 
{
	tree[p].tagmul = 1, tree[p].tagfac = 0;
	if(l == r) 
	{
		tree[p].mul = a[l];
		tree[p].fac = to[a[l]];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lc(p));
	build(mid + 1, r, rc(p));
	push_up(p);
}
inline void update(int l, int r, int p, int L, int R, int x) 
{
	if(L <= l && r <= R) 
	{
		tree[p].tagmul = tree[p].tagmul * x % mod;
		tree[p].tagfac |= to[x];
		tree[p].mul = tree[p].mul * Pow(x, r - l + 1) % mod;
		tree[p].fac |= to[x];
		return ;
	}
	push_down(l, r, p);
	int mid = (l + r) >> 1;
	if(mid >= L) update(l, mid, lc(p), L, R, x);
	if(mid < R) update(mid + 1, r, rc(p), L, R, x);
	push_up(p);
	return ;
}
inline int query1(int l, int r, int p, int L, int R) 
{
	if(L <= l && r <= R) return tree[p].mul;
	int mid = (l + r) >> 1;
	push_down(l, r, p); 
	int res = 1;
	if(mid >= L) res = res * query1(l, mid, lc(p), L, R) % mod;
	if(mid < R) res = res * query1(mid + 1, r, rc(p), L, R) % mod;
	push_up(p);
	return res;
}
inline int query2(int l, int r, int p, int L, int R) 
{
	if(L <= l && r <= R) return tree[p].fac;
	int mid = (l + r) >> 1;
	push_down(l, r, p);
	int res = 0;
	if(mid >= L) res |= query2(l, mid, lc(p), L, R);
	if(mid < R) res |= query2(mid + 1, r, rc(p), L, R);
	return res;
} 
signed main()
{
	n = read(), q = read();
	for (int i = 2; i <= 300; i++)
	{
		int t = i;
		for (int j = 2; j * j <= t; j++) 
			while(t % j == 0) to[i] |= to[j], t /= j;
		to[i] |= to[t];
		if(t == i) pr[++cnt] = i, to[i] = (1ll << cnt), v[cnt] = (i - 1) * Pow(i, mod - 2) % mod;
	}
	for (int i = 1; i <= n; i++) a[i] = read();
	build(1, n, 1);
	for (int i = 1; i <= q; i++) 
	{
		char opt[11];
		scanf("%s", opt + 1);
		if(opt[1] == 'T') 
		{
			int l = read(), r = read();
			int mul = query1(1, n, 1, l, r), fac = query2(1, n, 1, l, r);
			for (int j = 1; j <= cnt; j++) 
				if(fac & (1ll << j)) mul = mul * v[j] % mod;
			printf("%lld\n", mul);
		}
		else
		{
			int l = read(), r = read(), x = read();
			update(1, n, 1, l, r, x);
		}
	}
	return 0;
}