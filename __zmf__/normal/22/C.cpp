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
int n, m, v, x;
signed main()
{
 	n = read(), m = read(), v = read();
 	if(m < n - 1 || m > n - 1 + (n - 2) * (n - 3) / 2) 
 	{
 		puts("-1");
 		return 0;
	}
	if(v == 1) x = 2;
	else x = 1;
	for (int i = 1; i <= n; i++)
		if(v != i) 
			printf("%d %d\n", i, v);
	m -= (n - 1);
	if(!m) return 0;
	for (int i = 1; i <= n;	i++)
		for (int j = i + 1; j <= n; j++)
			if(i != x && i != v && j != x && j != v)
			{
				m--; printf("%d %d\n", i, j);
				if(!m) return 0; 
			}
	return 0;
}