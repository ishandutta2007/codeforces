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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 4e5 + 9;
int T, n, a[N], b[N], pre[N], sum[N], mx;
inline void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = 1; i <= n; i++) 
		if(a[i] > b[i]) 
		{
			puts("No"); return ;
		} 
	for (int i = 1; i < n; i++) 
		if(b[i] > b[i + 1] + 1 && a[i] != b[i]) 
		{
			puts("No"); return ;
		}
	if(b[n] > b[1] + 1 && a[n] != b[n]) puts("No"); 
	else puts("Yes"); return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}