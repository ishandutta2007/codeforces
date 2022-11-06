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
int lx[N], ly[N], n, k;
int x[N], y[N];
signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	for (int i = 1; i <= n; i++) y[i] = read();
	for (int i = 1; i <= n; i++) lx[i] = max(0ll, x[i] - k * y[i] + lx[i - 1]), ly[i] = max(0ll, y[i] - k * x[i] + ly[i - 1]);
	for (int i = 1; i <= n; i++)
		if(lx[i] > k || ly[i] > k)
		{
			puts("NO"); return 0;
		}	
	puts("YES");
	return 0;
}