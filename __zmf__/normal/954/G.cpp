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
const int N = 1e6 + 9;
int n, p, k, a[N], b[N], sum[N];
inline int check(int x)
{
	int now = 0, res = 0;
	for (int i = 1; i <= n; i++) b[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		now -= b[i];
		if(a[i] + now >= x) continue;
		res = res + (x - a[i] - now);
		b[min(i + 2 * p + 1, n + 1)] += (x - a[i] - now); 
		now = now + (x - a[i] - now);
		if(res > k) return 0;
	}
	return 1;
}
signed main()
{
	n = read(), p = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		int l = max(1ll, i - p), r = min(n, i + p);
		a[i] = sum[r] - sum[l - 1];
	}
	int l = 0, r = 2e18, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}