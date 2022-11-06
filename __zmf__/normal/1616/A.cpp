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
const int N = 109;
int n, a[N], cnt[N], ans;
inline void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = abs(read()), cnt[a[i]]++;
	ans = 0;
	ans += min(1ll, cnt[0]);
	for (int i = 1; i <= 100; i++) ans += min(2ll, cnt[i]);
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) cnt[a[i]]--;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}