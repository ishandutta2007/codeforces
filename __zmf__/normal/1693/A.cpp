/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
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
const int N = 2e5 + 9;
int n, a[N];
inline void solve()
{
	n = read(); int sum = 0;
	for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
	if(sum != 0) 
	{
		puts("No"); return ;
	}
	for (int i = 1; i < n; i++) 
	{
		if(a[i] < 0) 
		{
			puts("No"); return ;
		}
		if(a[i] == 0) 
		{
			for (int j = i + 1; j <= n; j++) 
				if(a[j] != 0) 
				{
					puts("No"); return ;
				}
			puts("Yes"); return ;
		}
		a[i + 1] += a[i];
	}
	puts("Yes"); return ;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}