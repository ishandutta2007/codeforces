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
const int N = 19, P = (1 << 18) + 9;
int n, a[P], sum, m;
signed main()
{
	n = read(), m = read();
	for (int i = 0; i < (1 << n); i++) a[i] = read(), sum += a[i];
	printf("%.6lf\n", sum * 1.0 / (1 << n));
	for (int i = 1; i <= m; i++)
	{
		int r = read(), x = read();
		sum -= a[r]; sum += x; a[r] = x;
		printf("%.6lf\n", sum * 1.0 / (1 << n));
	}
	return 0;
}