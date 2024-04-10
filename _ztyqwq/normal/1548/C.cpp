#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
#define int ll
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
int inv[3000020];
inline void InitInv(int n)
{
	inv[1] = 1;
	for(int i = 2; i <= n; i++)
		inv[i] = mod - (mod / i) * inv[mod % i] % mod;
}
inline int read()
{
	char c;
	while((c = getchar()) < '0' || c > '9');
	int x = c - '0';
	while((c = getchar()) >= '0' && c <= '9')
		x = x * 10 + c - '0';
	return x;
}
int f[3000020][2];
signed main()
{
	int n = read(), q = read();
	InitInv(3 * n + 10);
	f[0][0] = f[0][1] = n + 1;
	int mx = 3 * n + 3, C = mx;
	for(int i = 1; i <= 3 * n; i++)
	{
		C = C * (mx - i) % mod * inv[i + 1] % mod;
		f[i][1] = (C + f[i - 1][0] - f[i - 1][1] + mod) * inv[3] % mod;
		f[i][0] = (f[i][1] - f[i - 1][0] + mod) % mod;
	}
	while(q--)
	{
		int x = read();
		printf("%lld\n", f[x][0]);
	}
	return 0;
}