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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 3e5 + 9;
int n, sum, p[N], m, dep[N], vis[N], col[N], x[N], y[N], cnt1, cnt2, ans1[N], ans2[N], fa[N];
vector<int> G1[N], G[N];
inline void dfs(int u, int f)
{
	
	dep[u] = dep[f] + 1; vis[u] = 1;
	fa[u] = f;
//	cout << u << " " << f << " " << dep[u] << "qwq" << endl;
	for (int i = 0; i < G1[u].size(); i++)
		if(!vis[G1[u][i]])
		{
			G[u].push_back(G1[u][i]);
			G[G1[u][i]].push_back(u);
			dfs(G1[u][i], u);
		}
}
inline int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
//	cout << x << " " << y << ":" << dep[x] << " " << dep[y] << endl;
	int pp = dep[x] - dep[y];
	for (int i = 1; i <= pp; i++) x = fa[x];
//	cout << x << " " << y << ":" << dep[x] << " " << dep[y] << endl;
	while(x != y) x = fa[x], y = fa[y];
//	cout << x << endl;
	return x;
}
signed main() 
{	
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		G1[x].push_back(y);
		G1[y].push_back(x);
	}
	dfs(1, 0);
	int q = read();
	for (int i = 1; i <= q; i++)
	{
		x[i] = read(), y[i] = read();
		col[x[i]] ^= 1; col[y[i]] ^= 1;
	}
//	for (int i = 1; i <= n; i++) cout << dep[i] << " " << fa[i] << endl;
	int res = 0;
	for (int i = 1; i <= n; i++) res += col[i];
	if(!res)
	{
		puts("YES");
		for (int j = 1; j <= q; j++)
		{
			cnt1 = 0, cnt2 = 0;
			int p = LCA(x[j], y[j]), now = x[j];
			while(now != p) ans1[++cnt1] = now, now = fa[now];
			now = y[j];
			while(now != p) ans2[++cnt2] = now, now = fa[now];
			printf("%lld\n", cnt1 + cnt2 + 1);
			for (int i = 1; i <= cnt1; i++) printf("%lld ", ans1[i]);
			printf("%lld ", p);
			for (int i = cnt2; i >= 1; i--) printf("%lld ", ans2[i]);
			puts(""); 
		}
	}
	else
	{
		puts("NO");
		cout << res / 2 << endl;
	}
	return 0;
}