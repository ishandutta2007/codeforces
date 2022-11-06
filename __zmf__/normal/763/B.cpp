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
const int N = 2e5 + 9;
int a, b, c, d, n;
signed main()
{
	n = read();
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		a = read(), b = read(), c = read(), d = read();
		a = (a % 2 + 2) % 2, b = (b % 2 + 2) % 2; 
		printf("%lld\n", a * 2 + b + 1);
	}
	return 0;
}