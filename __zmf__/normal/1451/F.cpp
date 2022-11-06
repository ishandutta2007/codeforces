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
const int N = 209;
int n, m, T;
int t[N];
inline void solve()
{
	memset(t, 0, sizeof(t));
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			t[i + j] ^= read();
	for (int i = 2; i <= n + m; i++) 
		if(t[i])
		{
			puts("Ashish"); return ;
		}
	puts("Jeel"); return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}