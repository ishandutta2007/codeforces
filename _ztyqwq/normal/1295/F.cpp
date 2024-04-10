#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
#define int ll
int n, m = 0;
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
set<int> st;
int num[110], len[110];
map<int, int> mp;
int l[60], r[60];
inline int C(int n, int m)
{
	int ans = 1;
	for(int i = 1; i <= m; i++)
		ans = ans * (n + 1 - i) % mod * inv(i) % mod;
	return ans;
}
int dp[60][110], s[60][110];
signed main()
{
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld %lld", &l[i], &r[i]);
		st.insert(l[i]), st.insert(++r[i]);
	}
	for(auto x: st)
		num[++m] = x, mp[x] = m;
	for(int i = 1; i <= n; i++)
		l[i] = mp[l[i]], r[i] = mp[r[i]];
	for(int i = 1; i < m; i++)
		len[i] = num[i + 1] - num[i];
	dp[0][m] = s[0][m] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(j >= l[i] && j < r[i])
			{
				dp[i][j] = (s[i - 1][m] - s[i - 1][j] + mod) * len[j] % mod;
				for(int k = i - 1; k >= 1; k--)
				{
					if(j < l[k] || j >= r[k])
						break;
					dp[i][j] = (dp[i][j] + (s[k - 1][m] - s[k - 1][j] + mod) * C(len[j] + i - k, i - k + 1)) % mod;
				}
			}
			s[i][j] = (s[i][j - 1] + dp[i][j]) % mod;
		}
	int tot = 0;
	for(int i = 1; i < m; i++)
		tot = (tot + dp[n][i]) % mod;
	int pro = 1;
	for(int i = 1; i <= n; i++)
		pro = pro * (num[r[i]] - num[l[i]]) % mod;
	printf("%lld\n", tot * inv(pro) % mod);
	return 0;
}