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
const int N = 2e6 + 9;
int T, n, a[N], ans, ri;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1);
		ans = 0;
		for (int i = 1; i + ri <= n; i++)
			if(a[i] <= i) ans = i;
		printf("%lld\n", ans + 1);
	}
	return 0;
}