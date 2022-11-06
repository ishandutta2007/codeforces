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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 1e6 + 9, mod = 1e9 + 7;
int cnt[N], val[N], now, inv[N], jc[N], n, k, q, beg[N];
int phi[N], pep, prime[N], vis[N];
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
inline int C(int x, int y)
{
	if(x < y) return 0;
	else return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
inline void init()
{
	phi[1] = 1;
	for (int i = 2; i <= N - 9; i++)
	{
		if(!vis[i]) prime[++pep] = i, phi[i] = i - 1;
		for (int j = 1; j <= pep && prime[j] * i <= N - 9; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i] * phi[prime[j]];
		}
	}
	return ;
};	
signed main()
{
	n = read(), k = read(), q = read();
	init();
	jc[0] = 1;
	for (int i = 1; i <= n + q; i++) jc[i] = jc[i - 1] * i % mod;
	inv[n + q] = Pow(jc[n + q], mod - 2);
	for (int i = n + q - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		for (int j = 1; j * j <= x; j++)
			if(x % j == 0)
			{
				if(j * j != x) cnt[j]++, cnt[x / j]++;
				else cnt[j]++;
			}
	}
	for (int i = N - 9; i >= 1; i--)
	{
		val[i] = (val[i] + C(cnt[i], k)) % mod;
		for (int j = 2; j <= (N - 9) / i; j++) val[i] = (val[i] - val[j * i] + mod) % mod, beg[j * i] = (beg[j * i] + i) % mod;
		now = (now + val[i] * i) % mod;
	}
	for (int i = 1; i <= q; i++)
	{
		int x = read();
		for (int j = 1; j * j <= x; j++)
			if(x % j == 0)
			{
				int pp = (C(cnt[j] + 1, k) - C(cnt[j], k) + mod) % mod;
				now = (now + pp * phi[j] % mod) % mod;
				cnt[j]++;
				if(j * j == x) continue;
				pp = (C(cnt[x / j] + 1, k) - C(cnt[x / j], k) + mod) % mod;
				now = (now + pp * phi[x / j] % mod) % mod;
				cnt[x / j]++;
			}
		cout << now << endl;
	}
	return 0; 
}