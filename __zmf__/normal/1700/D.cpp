/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
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
int n, a[N], sum, res, Q;
inline void work()
{
	n = read(); sum = 0; res = 0;
	for (int i = 1; i <= n; i++) 
	{
		a[i] = read(), sum += a[i];
		res = max(res, (sum + i - 1) / i);
	}
	Q = read();
	for (int i = 1; i <= Q; i++) 
	{
		int x = read();
		if(x < res) 
		{
			puts("-1"); continue;
		}
		else printf("%lld\n", (sum + x - 1) / x);
	}
}
signed main()
{
	int T = 1;
	for (int ttt = 1; ttt <= T; ttt++) work();
	return 0;
}