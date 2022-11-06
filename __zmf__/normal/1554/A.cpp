// Problem: A. Cherry
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/A
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
long long ans, n, a[N];
int T;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		ans = 0;
		for (int i = 1; i < n; i++) ans = max(ans, a[i] * a[i + 1]);
		cout << ans << endl;
	}
	return 0;
}