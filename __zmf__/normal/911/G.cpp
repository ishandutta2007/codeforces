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
inline void write(int X)
{
	if(X < 0) {putchar('-'); X = -X;}
	if(X > 9) write(X / 10);
	putchar(X % 10 + '0');
}
const int N = 2e5 + 9, M = 109, BL = 509;
int n, q, a[N], B, tag[N], L[BL], R[BL], m;
__int128 fa[BL][M], pown[M];
int to[109];
inline __int128 lowbit(__int128 x) {return x & (-x);}
inline void Set(int id) 
{
	for (int i = 1; i <= m; i++) to[i] = 0;
	for (int i = 1; i <= m; i++) 
		while(fa[id][i]) 
		{
			__int128 t = lowbit(fa[id][i]); fa[id][i] ^= t;
			int pos = lower_bound(pown + 1, pown + m + 1, t) - pown;
			to[pos] = i;
		}
	for (int i = L[id]; i <= R[id]; i++) a[i] = to[a[i]];
	for (int i = 1; i <= m; i++) fa[id][i] = pown[i];
	return ;
}
inline void update(int l, int r, int x, int y) 
{
	if(tag[l] == tag[r]) 
	{
		Set(tag[l]);
		for (int i = l; i <= r; i++) 
			if(a[i] == x) a[i] = y;
		return ;
	}
	Set(tag[l]);
	for (int i = l; i <= R[tag[l]]; i++) 
		if(a[i] == x) a[i] = y;
	Set(tag[r]);
	for (int i = L[tag[r]]; i <= r; i++) 
		if(a[i] == x) a[i] = y;
	for (int i = tag[l] + 1; i < tag[r]; i++) 
	{
		if(x != y) fa[i][y] |= fa[i][x], fa[i][x] = 0;
	}
	return ;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(); m = 100;
	pown[0] = 1;
	for (int i = 1; i <= m; i++) pown[i] = (pown[i - 1] << 1);
	B = sqrt(n); 
	for (int i = 1; i <= n; i++) tag[i] = (i - 1) / B + 1;
	for (int i = 1; i <= tag[n]; i++)
		for (int j = 1; j <= m; j++)
			fa[i][j] = pown[j];
	for (int l = 1, r; l <= n; l = r + 1) 
	{
		r = min(n, l + B - 1); 
		L[tag[l]] = l; R[tag[r]] = r;
	//	cout << l << " " << r << endl;
		if(r == n) break;
	}
	q = read();
	for (int i = 1; i <= q; i++) 
	{
		int l = read(), r = read(), x = read(), y = read();
		update(l, r, x, y);
	//	for (int j = 1; j <= n; j++) cout << a[j] << " "; cout << endl;
	}
	for (int i = 1; i <= tag[n]; i++) Set(i);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}