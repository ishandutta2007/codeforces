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
const int N = 2e5 + 9, mod = 1e9 + 7;
int l[N], r[N], n, sum1, ans, sum, sum2, v[N], len[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) l[i] = read();
	for (int i = 1; i <= n; i++) r[i] = read();
	for (int i = 1; i <= n; i++) len[i] = (r[i] - l[i] + 1);
	for (int i = 1; i < n; i++)
	{
		int L = max(l[i], l[i + 1]), R = min(r[i], r[i + 1]);
		v[i] = max(0ll, R - L + 1) * Pow(len[i] * len[i + 1] % mod, mod - 2) % mod;
		sum1 = (sum1 + v[i]) % mod;
	}
	sum = sum1 * sum1 % mod;
	for (int i = 3; i <= n; i++) 
	{
		sum = (sum - v[i - 1] * v[i - 2] % mod * 2ll % mod + mod) % mod;
		int L = max(max(l[i], l[i - 1]), l[i - 2]), R = min(min(r[i], r[i - 1]), r[i - 2]);
		sum = (sum + max(0ll, R - L + 1) * Pow(len[i] * len[i - 1] % mod * len[i - 2] % mod, mod - 2) % mod * 2ll % mod) % mod;		
	}
	for (int i = 1; i < n; i++)
	{
		sum = (sum - v[i] * v[i] % mod + mod) % mod; sum = (sum + v[i]) % mod;
	}
	ans = (n * n % mod - 2 * n * sum1 % mod + sum + mod) % mod; 
	printf("%lld\n", ans);
	return 0;
}