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
const int mod = 1e9 + 7;
inline int Pow(int x, int y)
{
	int res = 1, base = (x % mod);
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
int a, b, n, x, p, ans;
signed main()
{
	a = read(), b = read(), n = read(), x = read();
	if(a == 1)
	{
		n %= mod;
		ans = b * n % mod + x;
		ans %= mod;
		cout << ans << endl;
		return 0; 
	}
	p = b * Pow(a - 1, mod - 2) % mod;
	ans = (x + p) * Pow(a, n) % mod;
	ans = (ans - p + mod) % mod;
	ans = (ans + mod) % mod;
	cout << ans << endl;
	return 0;
}
/*
4 4
1 2
1 3
2 4
3 4
*/