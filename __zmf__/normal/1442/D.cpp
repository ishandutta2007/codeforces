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
const int N = 3009;
int n, k, dp[N], cnt[N], ans, sum[N];
vector<int> G[N];
inline void solve(int l, int r)
{
	if(l == r) 
	{
		ans = max(ans, dp[k]);
		int now = 0;
		for (int i = k - 1; i >= 0; i--) 
		{
			int pos = k - i - 1;
			if(pos >= G[l].size()) continue;
			now += G[l][pos];
			ans = max(ans, now + dp[i]);
		}
		return ;
	}
	int f[N];
	for (int i = 0; i <= k; i++) f[i] = dp[i];
	int mid = (l + r) >> 1;
	for (int i = l; i <= mid; i++) 
		for (int j = k; j >= cnt[i]; j--) 
			dp[j] = max(dp[j], dp[j - cnt[i]] + sum[i]);
	solve(mid + 1, r);
	for (int i = 0; i <= k; i++) dp[i] = f[i];
	for (int i = mid + 1; i <= r; i++) 
		for (int j = k; j >= cnt[i]; j--) 
			dp[j] = max(dp[j], dp[j - cnt[i]] + sum[i]); 
	solve(l, mid);
	for (int i = 0; i <= k; i++) dp[i] = f[i];
}
signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) 
	{
		cnt[i] = read();
		for (int j = 1; j <= cnt[i]; j++) 
		{
			int x = read();
			G[i].push_back(x); sum[i] += x;
		}
	}
	solve(1, n);
	cout << ans << endl;
	return 0;
}