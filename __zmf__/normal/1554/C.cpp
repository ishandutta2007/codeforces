// Problem: C. Mikasa
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if(ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
		sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
long long n, m, T;
int ans;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(), m = read();
		if (n > m)
		{
			puts("0");
			continue;
		}
		m++;
		ans = 0;
		for (int i = 32; i >= 0; i--)
		{
			int b1 = (n & (1ll << i));
			int b2 = (m & (1ll << i));
			if (b2 > 0 && b1 == 0) ans = ans + (1ll << i);
			else if (b2 == 0 && b1 > 0)break; 
		}
		printf("%lld\n", ans);
	}
	return 0;
}