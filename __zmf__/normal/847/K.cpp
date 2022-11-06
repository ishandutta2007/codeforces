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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 309;
int n, a, b, k, f, ans;
int vis[N], val[N], cost[N], cnt;
string s1[N], s2[N];
signed main()
{
	n = read(), a = read(), b = read(), k = read(), f = read();
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i]; val[1] = a;
	for (int i = 2; i <= n; i++)
		if(s1[i] == s2[i - 1]) val[i] = b;
		else val[i] = a;
	for (int i = 1; i <= n; i++) ans += val[i];
	for (int i = 1; i <= n; i++) 
		if(!vis[i])
		{
			vis[i] = 1; int res = val[i];
			for (int j = i + 1; j <= n; j++)
			{
				if(s1[j] == s1[i] && s2[j] == s2[i]) res += val[j], vis[j] = 1;
				if(s1[j] == s2[i] && s2[j] == s1[i]) res += val[j], vis[j] = 1;
			}
			cost[++cnt] = res;
		}
	sort(cost + 1, cost + cnt + 1); reverse(cost + 1, cost + cnt + 1);
	for (int i = 1; i <= k; i++) ans -= max(0ll, cost[i] - f);
	cout << ans << endl;
	return 0;
}