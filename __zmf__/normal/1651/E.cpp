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
const int N = 3009;
int n; 
vector<int> G[N];
int cnt, ans; 
int a[N], vis[N];
struct query
{
	int l, r, x, y;
}bl, wh;
inline void Set(query &x) {x.l = 2 * n + 1; x.r = x.x = x.y = 0; return ;}
inline void upd(query &x, int t) 
{
	x.l = min(x.l, t); x.r = max(x.r, t); return ;
}
inline void cha(query &x, int t) 
{
	if(!x.x) x.x = t; else x.y = t; return ;
}
inline int getval(int x) {return x * (x + 1) / 2;}
inline int get(query x, int det) 
{
	/*if(x.l == 2 * n + 1 && x.r == 0) 
	{
		x.x -= det, x.y -= det; if(x.x > x.y) swap(x.x, x.y);
		return getval(x.x - 1) + getval(n - x.y) + getval(x.y - x.x - 1);
	}*/
	x.l -= det, x.r -= det, x.x -= det, x.y -= det;
	if(x.l <= x.x && x.x <= x.r) return 0;
	if(x.l <= x.y && x.y <= x.r) return 0;
	int L = 1, R = n;
	if(x.x < x.l) L = max(L, x.x + 1); if(x.y < x.l) L = max(L, x.y + 1);
	if(x.x > x.r) R = min(R, x.x - 1); if(x.y > x.r) R = min(R, x.y - 1);
	return (x.l - L + 1) * (R - x.r + 1); 
}
inline void dfs(int u) 
{
	if(u > n) a[cnt++] = u, upd(wh, u);
	else a[cnt++] = u, upd(bl, u);
	vis[u] = 1;
	for (auto v : G[u]) 
		if(!vis[v]) dfs(v);
}
inline void calc()
{
	for (int i = 0; i < cnt; i++) 
	{
		Set(bl); Set(wh);
		for (int len = 1; len < cnt; len++) 
		{
			int pos = (i + len - 1) % cnt;
			if(a[pos] <= n) upd(bl, a[pos]); else upd(wh, a[pos]);
			bl.x = bl.y = wh.x = wh.y = 0;
			pos = (i - 1 + cnt) % cnt;
			if(a[pos] <= n) cha(bl, a[pos]); else cha(wh, a[pos]);
			pos = (i + len) % cnt;
			if(a[pos] <= n) cha(bl, a[pos]); else cha(wh, a[pos]);
		//	cout << i << " " << len << " " << bl.x << " " << bl.y << endl;
			ans += (len / 2) * get(bl, 0) * get(wh, n);
		}
	}
}
signed main()
{
	n = read();
	for (int i = 1; i <= 2 * n; i++) 
	{
		int x = read(), y = read();
		G[x].push_back(y); G[y].push_back(x);
	}
	for (int i = 1; i <= 2 * n; i++) 
		if(!vis[i])
		{
			cnt = 0; Set(bl); Set(wh);
			dfs(i); ans += (cnt / 2) * get(bl, 0) * get(wh, n);
			calc();  
		}
	cout << ans << endl;
	return 0;
}