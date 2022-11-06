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
const int N = 1e5 + 9;
int n, m, mod, fa[N], siz[N], ans, B;
inline int find(int x) 
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
} 
inline void Merge(int x, int y) 
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return ;
	fa[fy] = fx, siz[fx] += siz[fy]; return ;
}
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
signed main()
{
	n = read(), m = read(); mod = read();
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++) 
	{
		int x = read(), y = read(); Merge(x, y);
	} ans = 1;
	for (int i = 1; i <= n; i++) 
		if(fa[i] == i) ans = ans * siz[i] % mod, B++;
	if(B == 1) printf("%lld\n", 1ll % mod);
	else printf("%lld\n", ans * Pow(n, B - 2) % mod);
	return 0;
}