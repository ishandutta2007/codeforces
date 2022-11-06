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
const int N = 5009, mod = 998244353;
int T, a[N], n, jc[N], inv[N], ans, dp[N], lim[N];
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
inline int A(int x, int y)
{
	if(x < y) return 0;
	else return jc[x] * inv[x - y] % mod;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	init();
	sort(a + 1, a + n + 1);
	dp[0] = 1, lim[0] = -1;
	for (int i = 1; i <= n; i++) lim[i] = upper_bound(a + 1, a + n + 1, a[i] / 2) - a - 1;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= lim[i]; j++) dp[i] = (dp[i] + dp[j] * A(n - 2 - lim[j], lim[i] - lim[j] - 1) % mod) % mod;
	if(lim[n] == n - 1) cout << dp[n] << endl;
	else puts("0");
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