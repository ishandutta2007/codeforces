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
const int N = 2e5 + 9;
int T, n, k, dep[N], res, vis[N]; 
vector<int> G[N];
inline void dfs(int u, int lim) 
{
	dep[u] = 1;
	for (auto v : G[u])
	{
		dfs(v, lim);
		dep[u] = max(dep[u], dep[v] + 1);
	}
	if(dep[u] == lim && !vis[u]) dep[u] = -1e9, res++;
	return ;
}
inline void work()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) G[i].clear(), vis[i] = 0;
	for (int i = 2; i <= n; i++) 
	{
		int x = read(); G[x].push_back(i);
		if(x == 1) vis[i] = 1;
	}
	vis[1] = 1;
	int l = 1, r = n - 1, ans = n - 1;
	while(l <= r) 
	{
		int mid = (l + r) >> 1; res = 0;
		dfs(1, mid);
		if(res <= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) work();
	return 0;
}