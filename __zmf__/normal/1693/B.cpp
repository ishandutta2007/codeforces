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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 2e5 + 9;
int n, a[N], L[N], R[N], dp[N], w[N];
vector<int> G[N];
inline void dfs(int u, int f) 
{
//	cout << u << " " << f << endl;
	int sumw = 0;
	for (auto v : G[u])
	{
		dfs(v, u);
		dp[u] += dp[v]; sumw += w[v];
	}
	if(sumw < L[u]) 
	{
		dp[u]++; w[u] = R[u];
	}
	else w[u] = min(R[u], sumw);
}
inline void solve()
{
	n = read(); 
	for (int i = 1; i <= n; i++) G[i].clear(), dp[i] = w[i] = 0;
	for (int i = 2; i <= n; i++)
	{
		int x = read(); 
		G[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) L[i] = read(), R[i] = read();
	dfs(1, 0);
	printf("%lld\n", dp[1]);
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}