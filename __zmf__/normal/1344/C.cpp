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
int n, m;
vector<int> G1[N], G2[N];
int f, e, q[N];
int nxt[N], pre[N], deg[N];
inline void bfs()
{
	while(f < e)
	{
		int u = q[++f];
		for (auto v : G1[u]) 
		{
			deg[v]--;
			if(deg[v] == 0) q[++e] = v;
		}
	}
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		G1[x].push_back(y); G2[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) 
	{
		deg[i] = G2[i].size(); if(deg[i] == 0) q[++e] = i;
	}
	bfs();
	if(e != n) 
	{
		puts("-1"); return 0;
	}
	for (int i = 1; i <= n; i++) pre[i] = nxt[i] = i;
	for (int i = 1; i <= n; i++)
		for (auto j : G2[q[i]]) pre[q[i]] = min(pre[q[i]], pre[j]);
	for (int i = n; i >= 1; i--)
		for (auto j : G1[q[i]]) nxt[q[i]] = min(nxt[q[i]], nxt[j]);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += (pre[i] == i && nxt[i] == i);
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if(pre[i] == i && nxt[i] == i) putchar('A');
		else putchar('E');
	return 0;
}