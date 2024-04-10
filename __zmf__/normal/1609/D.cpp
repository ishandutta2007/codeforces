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
const int N = 2e5 + 9;
int n, m, fa[N], siz[N];
int pp[N], cnt;
struct point
{
	int x, y;
}p[N];
inline int find(int x)
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
inline void Merge(int x, int y)
{
	fa[y] = x, siz[x] += siz[y];
} 
inline void work(int id)
{
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	int k = 1; cnt = 0;
	for (int i = 1; i <= id; i++) 
	{
		int fx = find(p[i].x), fy = find(p[i].y);
		if(fx != fy) Merge(fx, fy);
		else ++k;
	}
	for (int i = 1; i <= n; i++)
		if(i == find(i)) pp[++cnt] = siz[i];
	sort(pp + 1, pp + cnt + 1);
	reverse(pp + 1, pp + cnt + 1);
	int ans = 0;
	for (int i = 1; i <= k; i++) ans += pp[i];
	printf("%lld\n", ans - 1);
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		p[i].x = read(), p[i].y = read();
		work(i);
	}
	return 0;
}