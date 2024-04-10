/*
	
	
	
	
	
	

	
	
	
										Naicissu
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
	while (ch <= '9'&&ch >= '0')sum=sum*10+ch-'0',ch=getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int ans;
int T, n, a1[N], a2[N], sum1[N], sum2[N];
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		for (int i = 1; i <= n; i++) a1[i] = read();
		for (int i = 1; i <= n; i++) a2[i] = read();
		for (int i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + a1[i];
		for (int i = 1; i <= n; i++) sum2[i] = sum2[i - 1] + a2[i];
		ans = 1e18;
		for (int i = 1; i <= n; i++) ans = min(ans, max(sum1[n] - sum1[i], sum2[i - 1]));
		printf("%lld\n", ans);
	}
	return 0;
}