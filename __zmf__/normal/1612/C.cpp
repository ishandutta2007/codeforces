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
int T, k, x;
inline int check(int x)
{
	if(x <= k) return x * (x + 1) / 2;
	x = 2 * k - 1 - x;
	return k * k - x * (x + 1) / 2;
}
inline void solve()
{
	k = read(), x = read();
	if(x >= k * k) printf("%lld\n", k * 2 - 1);
	else
	{
		int l = 1, r = k * 2 - 1, ans = 0;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(check(mid) >= x) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}