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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 2e6 + 9;
int n, a[N], x, k, sum[N], mid;
inline int check()
{
	mid = n - k;
	int mn = n;
	for (int i = 1; i <= mid; i++)
	{
		int pp = sum[mid] - sum[i - 1];
		if(pp <= 0) return -1;
		else
		{
			int cnt = (pp - 1) / (-x);
			if(mid - i + 1 + cnt <= k) return -1;
			//cout << cnt << " " << mid - i + 1 + cnt << endl;
			mn = min(mn, mid - i + 1 + cnt);
			if(i + mn - 1 >= n) return mn;
		}
	}
	return mn;
}
signed main()
{
	n = read();
	for (int i = 1; i <= (n + 1) / 2; i++) a[i] = read();
	x = read();
	for (int i = (n + 1) / 2 + 1; i <= n; i++) a[i] = x;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	k = n >> 1;
	if(x >= 0)
	{
		if(sum[n] > 0) cout << n << endl;
		else cout << -1 << endl;
		return 0;
	}
	cout << check() << endl;
	return 0;
}