/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
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
const int N = 4e5 + 9, mod = 1e9 + 7;
int ans, n, k, jc[N], inv[N];
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
inline int C(int x, int y) {return jc[x] * inv[y] % mod * inv[x - y] % mod;}
signed main() 
{
	n = read(), k = read(); jc[0] = 1; 
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod; inv[n] = Pow(jc[n], mod - 2); 
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	ans = 1;
	for (int i = 1; i <= min(k, n); i++) ans = (ans + C(n, i)) % mod;
	cout << ans << endl;
	return 0;
}