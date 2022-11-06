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
const int N = 2e5 + 9;
int T;
int n, flag1, flag0, a[N];
inline void solve()
{
	n = read(); flag1 = flag0 = 0;
	for (int i = 1; i <= n; i++)
	{
	 	a[i] = read();
	 	if(a[i] == 1) flag1 = 1;
	 	else if(a[i] == 0) flag0 = 1;
	}
	sort(a + 1, a + n + 1);
	if(flag1 && flag0) 
	{
		puts("No"); return ;
	}
	else if(!flag1) 
	{
		puts("Yes"); return ;
	}
	for (int i = 1; i < n; i++)
		if(a[i] + 1 == a[i + 1])
		{
			puts("No"); return ;
		}
	puts("Yes"); return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}