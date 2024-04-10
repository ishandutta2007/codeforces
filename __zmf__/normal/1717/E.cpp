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
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, dp[N], ans;
inline int Gcd(int x, int y) 
{
	if(y == 0) return x;
	else return Gcd(y, x % y); 
}
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
inline int get(int x) 
{
	return x * (x - 1) % mod * (x - 2) % mod * Pow(6, mod - 2) % mod;
}
signed main() 
{
	n = read();
	for (int i = n / 2; i >= 1; i--) 
	{
		int t = n / i;
		int sum = get(t) * i % mod; 
		sum += (n % i) * (t * (t - 1) / 2 % mod) % mod; sum %= mod;
		int x = i / Gcd(n, i); 
		sum = sum * x % mod;
		//cout << sum << endl;
		for (int j = i * 2; j <= n / 2; j += i) 
		{
			int y = j / Gcd(n, j);
		//	cout << i << " " << j << " " << x << " " << y << endl;
			sum = (sum - dp[j] * Pow(y / x, mod - 2) % mod + mod) % mod;
		}
		dp[i] = sum; //cout << sum << endl;
		ans = (ans + dp[i]) % mod;
	}
	cout << ans << endl;
	return 0;
}