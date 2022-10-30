#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
#define int ll
int a[200010], f[200010][2], s[200010][2];
int stk[200010], cnt = 0, res[200010][2];
inline int p1(int x)
{
	return (x & 1) ? mod - 1 : 1;
}
signed main()
{
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	f[0][0] = s[0][0] = 1, f[0][1] = s[0][1] = 0;
	stk[0] = res[0][0] = res[0][1] = 0;
	for(int i = 1; i <= n; i++)
	{
		while(cnt && a[stk[cnt]] >= a[i])
			cnt--;
		stk[++cnt] = i;
		f[i][0] = ((cnt == 1 ? 0 : f[stk[cnt - 1]][0]) + (s[i - 1][1] - (cnt == 1 ? 0 : s[stk[cnt - 1] - 1][1]) + mod) * a[i]) % mod;
		f[i][1] = ((cnt == 1 ? 0 : f[stk[cnt - 1]][1]) + (s[i - 1][0] - (cnt == 1 ? 0 : s[stk[cnt - 1] - 1][0]) + mod) * a[i]) % mod;
		s[i][0] = (s[i - 1][0] + f[i][0]) % mod;
		s[i][1] = (s[i - 1][1] + f[i][1]) % mod;
	}
	printf("%lld\n", (f[n][0] - f[n][1] + mod) * p1(n) % mod);
	return 0;
}