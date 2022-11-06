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
const int N = 3e5 + 9;
map<int, int> mp[N]; 
int T, n, a[N], dp[N], nxt[N], ans;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(); ans = 0;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n + 1; i++) dp[i] = 0, nxt[i] = -1, mp[i].clear();
		for (int i = n; i >= 1; i--)
		{
			if(mp[i + 1][a[i]])
			{
				int pos = mp[i + 1][a[i]];
				nxt[i] = pos;
				swap(mp[i], mp[pos + 1]);
				if(pos < n) mp[i][a[pos + 1]] = pos + 1;
			}
			mp[i][a[i]] = i;
		}
		for (int i = n; i >= 1; i--) 
			if(nxt[i] != -1) dp[i] = dp[nxt[i] + 1] + 1;
		for (int i = 1; i <= n; i++) ans += dp[i];
		cout << ans << endl;
	}
	return 0;
}