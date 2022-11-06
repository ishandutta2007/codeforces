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
int T, a, b, c, d, x, y, k, p;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		a = read(), b = read(), c = read(), d = read();
		x = c - a, y = d - b;
		k = min(x, y), p = max(x, y) - k - 1;
		cout << k * (k + 1) + p * k + 1 << endl;
	}
	return 0;
}