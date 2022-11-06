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
const int N = ((1 << 22) + 9);
int n, x, y, k, dp[N], tmp[N], ans;
signed main()
{
	n = read(), x = read(), y = read(); k = max(x, y);
	for (int i = 1; i <= x + y; i++)
	{
		for (int j = 0; j < (1 << k); j++) tmp[j] = 0;
		int v = n / (x + y);
		if(n % (x + y) >= i) ++v; 
		for (int j = 0; j < (1 << k); j++) 
		{
			int M = (j << 1); 
			if(M >= (1 << k)) M -= (1 << k);
			tmp[M] = max(tmp[M], dp[j]);
			if(j & (1 << (x - 1))) continue;
			if(j & (1 << (y - 1))) continue;
			tmp[(M ^ 1)] = max(tmp[(M ^ 1)], dp[j] + v);
		}
		for (int j = 0; j < (1 << k); j++) ans = max(ans, tmp[j]), dp[j] = tmp[j];
	} 
	cout << ans << endl;
	return 0;
}