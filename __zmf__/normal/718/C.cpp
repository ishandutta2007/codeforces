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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int mod = 1e9 + 7, N = 1e5 + 9;
struct Matrix
{
	int A[2][2];
};
Matrix a[N], tree[N << 2];
int tag[N << 2];
Matrix F;
inline void Clear(Matrix &z) 
{
	z.A[0][0] = z.A[0][1] = z.A[1][0] = z.A[1][1] = 0; return ;
}
inline Matrix mul(Matrix x, Matrix y) 
{
	Matrix z; Clear(z);
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			for (int k = 0; k < 2; k++)
				z.A[i][j] = (z.A[i][j] + x.A[i][k] * y.A[k][j]) % mod;
	return z;
}
inline Matrix add(Matrix x, Matrix y) 
{
	Matrix z; Clear(z);
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			z.A[i][j] = (x.A[i][j] + y.A[i][j]) % mod; 
	return z;
}
inline void Set(Matrix &x) 
{
	x.A[0][0] = x.A[1][1] = 1; x.A[0][1] = x.A[1][0] = 0;
}
inline Matrix Pow(Matrix x, int y) 
{
	Matrix res, base = x;
	Set(res);
	while(y) 
	{
		if(y & 1) res = mul(res, base);
		base = mul(base, base);
		y >>= 1;
	}
	return res;
}
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;} 
inline void push_up(int p) 
{
	tree[p] = add(tree[lc(p)], tree[rc(p)]);
	return ;
}
inline void push_down(int p) 
{
	if(tag[p]) 
	{
		tag[lc(p)] += tag[p], tag[rc(p)] += tag[p];
		Matrix tmp = Pow(F, tag[p]);
		tree[lc(p)] = mul(tree[lc(p)], tmp); 
		tree[rc(p)] = mul(tree[rc(p)], tmp);
		tag[p] = 0;
	}
}
inline void build(int l, int r, int p) 
{
	if(l == r) 
	{
		tree[p] = a[l]; return ;
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
		tag[p] += x; tree[p] = mul(Pow(F, x), tree[p]);
		return ;
	}
	int mid = (l + r) >> 1;
	push_down(p);
	if(mid >= L) update(l, mid, lc(p), L, R, x);
	if(mid < R) update(mid + 1, r, rc(p), L, R, x);
	push_up(p);
	return ;
}
inline Matrix query(int l, int r, int p, int L, int R)
{
	if(L <= l && r <= R) return tree[p];
	int mid = (l + r) >> 1;
	Matrix res; Clear(res);
	push_down(p);
	if(mid >= L) res = add(res, query(l, mid, lc(p), L, R));
	if(mid < R) res = add(res, query(mid + 1, r, rc(p), L, R));
	push_up(p);
	return res;
} 
int n, q;
signed main()
{
	n = read(), q = read();
	F.A[1][0] = F.A[1][1] = F.A[0][1] = 1;
	for (int i = 1; i <= n; i++) 
	{
		int x = read(); Set(a[i]); a[i] = mul(Pow(F, x - 1), a[i]);
	}
	build(1, n, 1);
	for (int i = 1; i <= q; i++) 
	{
		int opt = read(), l = read(), r = read();
		if(opt == 1) 
		{
			int x = read(); update(1, n, 1, l, r, x);
		}
		else printf("%lld\n", query(1, n, 1, l, r).A[1][1]);
	}
	return 0; 
}