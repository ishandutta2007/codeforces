// Problem: CF712C Memory and De-Evolution
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF712C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	
	
	
	
	
	
	
	
	
	
	
	
					                  ever17 
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
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
	while (ch <= '9' && ch >= '0')sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
int x, y, z, n, p, tmp, cnt;
signed main()
{
	n = read(), p = read();
	x = y = z = p;
	while(1)
	{
		x = y, y = z, z = min(n, x + y - 1), cnt++;
		if(x == n && y == n && z == n)
		{
			cout << cnt << endl;
			return 0;
		} 
	}
	return 0;
}