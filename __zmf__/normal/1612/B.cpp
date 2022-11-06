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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int T, n, a, b, ans[N], cnt;
inline void solve()
{
	n = read(), a = read(), b = read(); cnt = 0;
	for (int i = n / 2 + 1; i <= n; i++) 
		if(i != b && i != a) ans[++cnt] = i;
	ans[++cnt] = a, ans[++cnt] = b;
	for (int i = 1; i <= n / 2; i++)
		if(i != a && i != b) ans[++cnt] = i;
	int Min = 1e9, Max = -1e9;
	for (int i = 1; i <= n / 2; i++) Min = min(Min, ans[i]);
	for (int i = n / 2 + 1; i <= n; i++) Max = max(Max, ans[i]);
	if(Min != a || Max != b) puts("-1");
	else
	{
		for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
		puts("");
	}
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}