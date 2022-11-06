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
const int N = 3e5 + 9, M = 1e7 + 9, mod = 998244353, INF = 1e18;
int n, m;
vector<int> pa[N], pc[N];
int top, h[M], a[M], dp[M], cnt, L[M], R[M];
int stac[M];
signed main() 
{		
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		int op = read(), x;
		for (int j = 1; j <= op; j++) x = read(), pa[i].push_back(x);
		for (int j = 1; j <= op; j++) x = read(), pc[i].push_back(x);
	}
	int op = read();
	for (int i = 1; i <= op; i++)
	{
		int x = read(), y = read();
		for (int j = 0; j < pa[x].size(); j++) 
			h[++cnt] = pa[x][j], a[cnt] = pc[x][j] * y;
	}
	n = cnt;
	for (int i = 0; i <= n + 1; i++) dp[i] = INF;
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		while(top && i - h[i] <= stac[top] - h[stac[top]]) top--;
		if(!top || i - h[i] >= stac[top]) L[i] = max(1ll, i - h[i] + 1);
		else L[i] = L[stac[top]]; 
		stac[++top] = i;
	}
	top = 0;
	for (int i = n; i >= 1; i--)
	{
		while(top && i + h[i] >= stac[top] + h[stac[top]]) top--;
		if(!top || i + h[i] <= stac[top]) R[i] = min(n, i + h[i] - 1);
		else R[i] = R[stac[top]];
		stac[++top] = i;
	}
	top = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[L[i] - 1] + a[i];
		while(top && R[stac[top]] < i) top--;
		if(top) dp[i] = min(dp[i], dp[stac[top] - 1] + a[stac[top]]);
		if(!top || dp[i - 1] + a[i] < dp[stac[top] - 1] + a[stac[top]]) stac[++top] = i;
 	}
 	cout << dp[n] << endl;
	return 0;
}//qwq