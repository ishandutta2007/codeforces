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
int n, a[N], ans;
inline void solve()
{
	n = read(); ans = 1e9;
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int now = 0;
			for (int k = 1; k <= n; k++)
				if((a[j] - a[k]) * (i - k) != (a[i] - a[k]) * (j - k)) now++;
			ans = min(ans, now);
		}
	if(n == 1) ans = 0;
	printf("%lld\n", ans);
	return ;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}