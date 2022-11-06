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
const int N = 1e4 + 9;
int n, m, k, x;
bool mp[N << 1];
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		k = read();
		bool flag = 0;
		for (int i = 0; i <= 2 * n; i++) mp[i] = 0;
		for (int j = 1; j <= k; j++)
		{
			x = read();
			if(mp[-x + n]) flag = 1;
			mp[x + n] = 1;
		}
		if(!flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}