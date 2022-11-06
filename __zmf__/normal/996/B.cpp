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
const int N = 1e5 + 9;
int n, a[N], res = 1e9;
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), res = min(res, a[i] - i + 1);
	int t = (res + n - 1) / n; t = max(0ll, t);
	for (int i = 1; i <= n; i++) a[i] -= t * n;
	for (int i = 1; i <= n; i++)
		if(a[i] - i + 1 <= 0)
		{
			cout << i << endl;
			return 0;
		}
	return 0;
}