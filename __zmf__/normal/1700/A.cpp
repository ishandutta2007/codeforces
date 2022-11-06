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
int T, ans;
inline void work()
{
	int n = read(), m = read();
	ans = 0;
	ans += m * (m + 1) / 2;
	ans += m * n * (n + 1) / 2;
	ans -= m;
	printf("%lld\n", ans);
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) work();
	return 0;
}