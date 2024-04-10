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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 5e5 + 9, mod = 998244353;
int n, k, m, l[N], r[N], w[N], pos[N], ans[N], dp[N];
int a[N], sum, lst, res = 1;
signed main()
{
	n = read(); k = read(), m = read();
	for (int i = 1; i <= m; i++) l[i] = read(), r[i] = read(), w[i] = read();
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= n + 1; j++) a[j] = pos[j] = 0, dp[j] = 0;
		for (int j = 1; j <= m; j++)
			if(w[j] & (1 << i)) a[l[j]]++, a[r[j] + 1]--;
			else pos[r[j] + 1] = max(pos[r[j] + 1], l[j]);
		for (int j = 2; j <= n + 1; j++) pos[j] = max(pos[j], pos[j - 1]), a[j] += a[j - 1];
		//for (int j = 1; j <= n + 1; j++) cout << pos[j] << " " << a[j] << endl;
		dp[0] = sum = 1, lst = 0;
		for (int j = 1; j <= n + 1; j++)
		{
			while(lst < pos[j]) sum = (sum - dp[lst] + mod) % mod, dp[lst] = 0, lst++;
			if(a[j]) dp[j] = 0;
			else dp[j] = sum, sum = (sum + dp[j]) % mod;
		}
		//cout << dp[n + 1] << endl;
		res = res * dp[n + 1] % mod;
	}
	cout << res << endl;
	return 0;
}