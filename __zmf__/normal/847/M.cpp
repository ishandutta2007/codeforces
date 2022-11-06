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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 109;
int n, a[N], t;
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(); t = a[2] - a[1];
	for (int i = 3; i <= n; i++)
		if(a[i] - a[i - 1] != t)
		{
			printf("%lld\n", a[n]); return 0;
		}
	printf("%lld\n", t + a[n]);
	return 0;
}