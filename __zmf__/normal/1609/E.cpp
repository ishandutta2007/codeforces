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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9, INF = 1e18;
struct Matrix
{
	int mat[4][4];
};
inline Matrix mul(Matrix a, Matrix b)
{
	Matrix c;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			c.mat[i][j] = INF;
	for (int k = 1; k <= 3; k++)
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)		
				c.mat[i][j] = min(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);
	return c;
}
Matrix tree[N << 2]; 
char s[N];
int n, m;
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p) {tree[p] = mul(tree[rc(p)], tree[lc(p)]);}
inline void build(int l, int r, int p)
{
	int mid = (l + r) >> 1;
	if(l == r) 
	{
		tree[p].mat[2][1] = tree[p].mat[3][1] = tree[p].mat[3][2] = 0;
		tree[p].mat[1][1] = (s[l] == 'a');
		tree[p].mat[2][2] = (s[l] == 'b');
		tree[p].mat[3][3] = (s[l] == 'c');
		tree[p].mat[1][2] = tree[p].mat[1][3] = tree[p].mat[2][3] = INF;
		return ;
	}
	build(l, mid, lc(p));
	build(mid + 1, r, rc(p));
	push_up(p);
}
inline void update(int l, int r, int p, int k)
{
	int mid = (l + r) >> 1;
	if(l == r) 
	{
		tree[p].mat[2][1] = tree[p].mat[3][1] = tree[p].mat[3][2] = 0;
		tree[p].mat[1][1] = (s[l] == 'a');
		tree[p].mat[2][2] = (s[l] == 'b');
		tree[p].mat[3][3] = (s[l] == 'c');
		tree[p].mat[1][2] = tree[p].mat[1][3] = tree[p].mat[2][3] = INF;
		return ;
	}
	if(mid >= k) update(l, mid, lc(p), k);
	else update(mid + 1, r, rc(p), k);
	push_up(p);
	return ;
}
char opt[5];
signed main()
{
	n = read(), m = read();
	scanf("%s", s + 1);
	build(1, n, 1); 
	for (int i = 1; i <= m; i++)
	{
		int pos = read();
		scanf("%s", opt + 1);
		s[pos] = opt[1];
		update(1, n, 1, pos);
		Matrix x;
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
				x.mat[j][k] = INF;
		x.mat[1][1] = 0; x = mul(tree[1], x);
		printf("%lld\n", min(x.mat[1][1], min(x.mat[2][1], x.mat[3][1])));
	}
	return 0;
}