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
int n, d, m, x, y;
signed main()
{
	n = read(), d = read();
	m = read();
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read();
		//cout << d * 2 << endl;
		if(x > n || y > n) puts("NO");
		else if(x + y < d) puts("NO");
		else if(x + y > n * 2 - d) puts("NO");
		else if(y - x > d || x - y > d) puts("NO");
		else puts("YES");
	}
	return 0;
}