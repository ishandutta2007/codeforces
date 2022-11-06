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
const int N = 2009, M = 1e5 + 9;
int u[M], v[M], col[N][N]; 
int a, b, m;
int deg[N], ans;
signed main()
{
	a = read(), b = read(), m = read();
	for (int i = 1; i <= m; i++) 
		u[i] = read(), v[i] = read() + a, deg[u[i]]++, deg[v[i]]++, ans = max(ans, deg[u[i]]), ans = max(ans, deg[v[i]]);
	cout << ans << endl;
	for (int i = 1; i <= m; i++) 
	{
		int colu = 1, colv = 1, nowcol = 0; 
		while(col[u[i]][colu]) colu++;
		while(col[v[i]][colv]) colv++;
		col[u[i]][colu] = v[i], col[v[i]][colv] = u[i];
		if(colu == colv) continue; 
		nowcol = colv;
		for (int r = v[i]; r; r = col[r][nowcol], nowcol ^= (colu ^ colv))
			swap(col[r][colu], col[r][colv]); 
	}
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= ans; j++) 
			if(col[u[i]][j] == v[i]) printf("%lld ", j);
	return 0;
}