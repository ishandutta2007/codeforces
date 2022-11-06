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
int T;
int l, r; 
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		l = read(), r = read();
		if(l * 2 > r)
		{
			printf("%d\n", r - l);
		}
		else
		{
			printf("%d\n", (r - 1) / 2);
		}
	}
	return 0;
}