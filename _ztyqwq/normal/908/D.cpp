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
		a = a * a % mod, n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
int dp[1010][1010];
signed main()
{
	int n, pa, pb;
	scanf("%lld %lld %lld", &n, &pa, &pb);
	pa = pa * inv((pa + pb) % mod) % mod, pb = (mod + 1 - pa) % mod;
	for(int i = n; i >= 1; i--)
		for(int j = n; j >= 0; j--)
			if(i + j >= n)
				dp[i][j] = (i + j + pa * inv(mod + 1 - pa)) % mod;
			else
				dp[i][j] = (pa * dp[i + 1][j] + pb * dp[i][i + j]) % mod;
	printf("%lld\n", dp[1][0]);
	return 0;
}