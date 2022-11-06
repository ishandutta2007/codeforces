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
int n, a[N], ans, t;
inline void work()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	ans = 0; t = 0;
	for (int i = 1; i < n; i++)
	{
		if(a[i] >= a[i + 1]) t += a[i] - a[i + 1], ans += a[i] - a[i + 1];
		else ans += a[i + 1] - a[i];
	}
	ans += abs(a[1] - t);
	printf("%lld\n", ans);
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) work();
	return 0;
}