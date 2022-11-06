// Problem: B. Cobb
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if(ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
		sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int a[N], n, T, k, ans;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(); k = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		ans = -1e12;
		for (int i = n; i >= 1; i--)
			for (int j = i - 1; j >= 1; j--)
			{
				if  (ans >= i * j) break;
				ans = max(ans, i * j - k * (a[i] | a[j]));
			}
		cout << ans << endl;
	}
	return 0;
}