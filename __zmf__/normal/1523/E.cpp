//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int sum = 0, nega = 1; char ch = getchar();
    while(ch > '9' || ch < '0') {if(ch == '-') nega = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
    return sum * nega;
}
const int N = 1e5 + 9, mod = 1e9 + 7;
int T, k, n, jc[N], inv[N], ans;
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
inline void init()
{
	jc[0] = 1;
	for (int i = 1; i <= N - 9; i++) jc[i] = jc[i - 1] * i % mod;
	inv[N - 9] = Pow(jc[N - 9], mod - 2);
	for (int i = N - 10; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline int C(int x, int y)
{
	if(x < y) return 0;
	else return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main()
{
	T = read();
	init();
    for (int ttt = 1; ttt <= T; ttt++) 
    {
    	n = read(), k = read(); k--; ans = 0;
    	for (int i = 2; i <= n; i++)
    	{
    		int val = (C(n - k * (i - 2), i - 1) * jc[i - 1] % mod * (n - i + 1) % mod - C(n - k * (i - 1), i) * jc[i] % mod + mod) % mod;
    	//	cout << inv[n] << " " << jc[n - i] << endl;
			ans = (ans + val * i % mod * inv[n] % mod * jc[n - i] % mod) % mod;
		}
		printf("%lld\n", ans);
	}
    return 0;
}
/*
3 3 1
2 5 3
*/
 
/*
10 10 0
5 6 4 2 9 1 2 4 9 7
*/