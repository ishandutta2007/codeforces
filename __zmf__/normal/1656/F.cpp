/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int __int128
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
inline void write(int X)
{
	if(X < 0) putchar('-'), X = -X;
	if(X > 9) write(X / 10);
	putchar(X % 10 + '0');
}
const int N = 2e5 + 9;
int T;
int n, a[N], sum[N], ans;
bool Inf;
inline void solve()
{
	n = read(); ans = -1e18;
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1); a[0] = -1e18; a[n + 1] = 1e18;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 0; i <= n; i++) 
	{
		int L = -a[i + 1], R = -a[i], now = 0, x = 0;
		x += i * a[n] + sum[i];
		x += (n - i) * a[1] + (sum[n] - sum[i]);
		if(i == 0) x -= 2 * a[1];
		else if(i == n) x -= 2 * a[n];
		else x -= (a[1] + a[n]);
		now += sum[i] * a[n]; 
		now += (sum[n] - sum[i]) * a[1];
		if(i == 0) now -= a[1] * a[1];
		else if(i == n) now -= a[n] * a[n];
		else now -= a[1] * a[n];
		if(i == 0 && x > 0) 
		{
			puts("INF"); return ;
		}
		if(i == n && x < 0) 
		{
			puts("INF"); return ;
		}
		ans = max(ans, x * L + now);
		ans = max(ans, x * R + now);
	}
	write(ans); puts("");
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}