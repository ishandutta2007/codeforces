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
const int N = 1e5 + 9;
int T, n, m, vis[N];
signed main() 
{	
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(), m = read();
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= m; i++)
		{
			int x = read(), y = read(), z = read();
			vis[y] = 1;
		}
		for (int i = 1; i <= n; i++)
			if(!vis[i])
			{
				for (int j = 1; j <= n; j++)
					if(j != i)
						printf("%lld %lld\n", i, j);
				break;
			}
	} 
	return 0;
}