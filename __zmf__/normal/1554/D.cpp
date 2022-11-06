// Problem: D. Diane
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/D
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
int T, n;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		if (n % 2 == 0)
		{
			for (int i = 1; i <= (n - 1) / 2; i++) putchar('a');
			putchar('b');
			for (int i = 1; i <= n / 2; i++) putchar('a');
			puts("");
		}
		else
		{
			if(n == 1)
			{
				puts("a");
			}
			else
			{
				for(int i = 1; i <= (n - 2) / 2; i++) putchar('a');
				putchar('b');
				putchar('c');
				for(int i = 1; i <= n - 2 - (n - 2) / 2; i++) putchar('a');
				puts("");
			}
		}
	}
	return 0;
}