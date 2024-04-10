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
const int N = 3e5 + 9, mod = 998244353, M = 3e5;
int n;
int jc[N], inv[N], a[N], f[N], cnt[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
inline int C(int x, int y)
{
	if(x >= y) return jc[x] * inv[y] % mod * inv[x - y] % mod; 
	else return 0;
}
inline void init()
{
	for (int i = 1; i <= M; i++)
		for (int j = 2 * i; j <= M; j += i) cnt[i] += cnt[j];
}
inline void work(int x)
{
	for (int i = M; i >= 1; i--)
	{
		f[i] = C(cnt[i], x);
		for (int j = 2 * i; j <= M; j += i) f[i] = (f[i] + mod - f[j]) % mod;
	}
}
signed main()
{
	jc[0] = 1;
	for (int i = 1; i <= M; i++) jc[i] = jc[i - 1] * i % mod;
	inv[M] = Pow(jc[M], mod - 2);
	for (int i = M - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		int x = read(); ++cnt[x];
	}
	init();
	for (int i = 1; i <= 7; i++)
		if(i <= n)
		{
			work(i);
			if(f[1] > 0) 
			{
				cout << i << endl;
				return 0;
			}
		}
	puts("-1");
	return 0;
}