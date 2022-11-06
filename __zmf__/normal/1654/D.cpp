/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 6e5 + 9, mod = 998244353;
int T;
int n, head[N], nxt[N * 2], valx[N * 2], valy[N * 2], to[N * 2], cnt;
int ans[N], now[N], pp = 1, res, inv[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y) 
	{
		if(y & 1) res = 1ll * res * base % mod;
		base = 1ll * base * base % mod;
		y >>= 1;
	}
	return res;
}
inline void addedge(int u, int v, int p1, int p2)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, valx[cnt] = p1, valy[cnt] = p2;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt, valx[cnt] = p2, valy[cnt] = p1;
}
inline void upd(int x, int v)
{
	for (int i = 2; i * i <= x; i++)
		while(x % i == 0) 
		{
			now[i] += v; 
			if(now[i] > ans[i]) ans[i] = now[i], pp = 1ll * pp * i % mod;
			x /= i;
		}
	if(x != 1) 
	{
		now[x] += v;
		if(now[x] > ans[x]) ans[x] = now[x], pp = 1ll * pp * x % mod;
	}
}
inline void dfs(int u, int f)
{
//	cout << u << " " << f << endl;
	for (int i = head[u]; i; i = nxt[i]) 
		if(to[i] != f)
		{
//			cout << u << " " << to[i] << endl;
			upd(valy[i], -1);
			upd(valx[i], 1);
			dfs(to[i], u);
			upd(valx[i], -1);
			upd(valy[i], 1);
		}
}
inline void dfs2(int u, int f, int w)
{
	for (int i = head[u]; i; i = nxt[i]) 
		if(to[i] != f) 
		{
			dfs2(to[i], u, 1ll * w * valy[i] % mod * 1ll * inv[valx[i]] % mod);
		}
	res = (res + w) % mod;
}
inline void init()
{
	for (int i = 1; i <= 2e5; i++) inv[i] = Pow(i, mod - 2) % mod;
}
signed main()
{
	init();
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();	cnt = 0;
		for (int i = 1; i <= n; i++) head[i] = 0;
		for (int t = 1; t < n; t++) 
		{
			int u = read(), v = read(), p1 = read(), p2 = read();
			int d = __gcd(p1, p2); p1 /= d, p2 /= d;
			addedge(u, v, p1, p2);
		//	ans[p1] = ans[p2] = 0;
			for (int i = 2; i * i <= p1; i++) 
				while(p1 % i == 0) 
				{
					ans[i] = 0, p1 /= i;
				}
			for (int i = 2; i * i <= p2; i++) 
				while(p2 % i == 0) 
				{
					ans[i] = 0, p2 /= i;
				}
			ans[p1] = ans[p2] = 0;
		}
		pp = 1; res = 0;
		dfs(1, 0);
		dfs2(1, 0, pp);
		printf("%lld\n", res);
 	}
	return 0;
}