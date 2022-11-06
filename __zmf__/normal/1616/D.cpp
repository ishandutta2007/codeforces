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
const int N = 1e5 + 9;
int n, a[N], ans, x, sum[N], now, R[N];
inline void solve()
{
	n = read(); ans = 0, now = -1e15;
	for (int i = 1; i <= n; i++) a[i] = read(); x = read();
	for (int i = 1; i <= n; i++) a[i] -= x, sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) 
	{
		if(sum[i] < now) 
		{
		//	cout << i << "qwq" << endl;
			ans++; now = -1e15; continue;
		}
		now = max(now, sum[i - 1]);
	}
	printf("%lld\n", n - ans);
	return ;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}