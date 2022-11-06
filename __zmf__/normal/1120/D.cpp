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
const int N = 1e6 + 9, INF = 1e18;
int a[N];
int l[N], r[N], cnt, m, n, ans, res[N], kel, now;
vector<int> G[N];
int fa[N];
inline int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
struct point
{
	int id, x, y, z;
}p[N];
inline bool cmp(point xxx, point yyy)
{
	return xxx.z < yyy.z;
}
inline void dfs(int u, int f)
{
	l[u] = N, r[u] = 0; 
	for (auto v: G[u])
		if(v != f)
		{
			dfs(v, u);
			l[u] = min(l[u], l[v]);
			r[u] = max(r[u], r[v]);
		}
	if(u != 1 && G[u].size() == 1) 
		l[u] = r[u] = ++cnt;
//	cout << l[u] << " " << r[u] << " " << u << endl;
	p[++m].id = u, p[m].x = l[u], p[m].y = r[u] + 1, p[m].z = a[u];
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	n = cnt + 1;
	sort(p + 1, p + m + 1, cmp);
	//for (int i = 1; i <= m; i++) cout << p[i].x << " " << p[i].y << " " << p[i].z << " " << p[i].id << endl;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i = now + 1)
	{
		while(p[now + 1].z == p[i].z) now++;
		//cout << now << endl;
		for (int j = i; j <= now; j++)
		{
			int fx = find(p[j].x), fy = find(p[j].y);
			if(fx != fy)
				res[++kel] = p[j].id;
		}
		for (int j = i; j <= now; j++)
		{
			int fx = find(p[j].x), fy = find(p[j].y);
			if(fx != fy)
				ans += p[j].z, fa[fx] = fy;
		}
	}
	sort(res + 1, res + kel + 1);
	cout << ans << " " << kel << endl;
	for (int i = 1; i <= kel; i++) printf("%lld ", res[i]);
	return 0;
}