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
const int N = 5e5 + 9, mod = 1e9 + 7, M = 4e6 + 9;
int n, a[N], cnt[M], Max, now;
int ans1, ans2, jc[M];
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
	for (int i = 1; i <= n; i++) a[i] = read() - 1, Max = max(Max, a[i]), now += (a[i] + 1);
	Max++;
	ans1 = 0, ans2 = 1; jc[0] = 1;
	for (int i = 1; i <= M - 9; i++) jc[i] = jc[i - 1] * i % mod;
	for (int i = 1; i <= n; i++) 
	{
		cnt[a[i] + Max]++; 
		if(Max - a[i] - 2 >= 0) cnt[Max - a[i] - 2]--;
	}
	int p2 = Pow(2, mod - 2);
	for (int i = Max * 2 - 1; i >= 0; i--) 
	{
		ans2 = ans2 * jc[cnt[i]] % mod; cnt[i - 2] += cnt[i];
		int sum = (now * 2 % mod - cnt[i] % mod + 1 + mod) % mod * cnt[i] % mod * p2 % mod;
		ans1 = (ans1 + sum * (i - Max) % mod + mod) % mod;
		now -= cnt[i];
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}