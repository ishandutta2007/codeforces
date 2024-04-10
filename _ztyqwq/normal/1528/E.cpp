#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
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
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
int sum[1000010];
const int i6 = inv(6);
inline int get2(int n)
{
	return n * (n + 1) / 2 % mod;
}
inline int get3(int n)
{
	return n * (n + 1) % mod * (n + 2) % mod * i6 % mod;
}
signed main()
{
	int n;
	scanf("%lld", &n);
	sum[0] = 1;
	for(int i = 1; i <= n; i++)
		sum[i] = (1 + sum[i - 1] + get2(sum[i - 1])) % mod;
	int ans = get3(sum[n - 1]) - get3(n == 1 ? 0 : sum[n - 2]) + get2(sum[n - 1]);
	ans = (ans * 2 + 1) % mod;
	for(int i = 1; i <= n - 2; i++)
		ans = (ans + (get2(sum[i - 1]) - get2(i == 1 ? 0 : sum[i - 2]) + mod) * get2(sum[n - i - 2])) % mod;
	printf("%lld\n", ans);
	return 0;
}