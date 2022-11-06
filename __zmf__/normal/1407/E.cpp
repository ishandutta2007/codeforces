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
const int N = 1e6 + 9;
int n, m;
int col[N], val[N], nxt[N], cnt, head[N], to[N];
inline void addedge(int u, int v, int w)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, val[cnt] = w;
}
struct point
{
	int x, step;
}q[N];
int f, e, vis[N], step[N];
inline void BFS()
{
	f = 0, e = 1; q[1].x = n, q[1].step = 0; vis[n] = 1;
	while(f < e)
	{
		point u = q[++f];
		for (int i = head[u.x]; i; i = nxt[i]) 
		{
			point v; v.x = to[i], v.step = u.step + 1; 
		//	cout << u.x << " " << v.x << " " << val[i] << " " << col[v.x] << " " << vis[v.x] << endl;
			if(col[v.x] != val[i]) 
			{
				col[v.x] = (val[i] ^ 1);
			}
			else if(!vis[v.x])
			{
			//	cout << v.x << " " << v.step << endl;
				vis[v.x] = 1; step[v.x] = v.step;
				q[++e] = v;
			}
		}
	}
	if(vis[1]) printf("%lld\n", step[1]);
	else printf("-1\n");
	for (int i = 1; i <= n; i++) 
		if(col[i] != -1) putchar(col[i] + '0');
		else putchar('0');
	return ;
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++) 
	{
		int u = read(), v = read(), w = read(); addedge(v, u, w);
	}
	for (int i = 1; i <= n; i++) col[i] = -1;
	BFS(); 
	return 0;
}