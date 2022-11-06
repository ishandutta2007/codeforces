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
int n, q;
char s[N];
vector<int> G[N * 2];
int dp[N], dp_sum[N], sum[N];
int sta[N], top;
signed main()
{
	n = read(), q = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) 
	{
		sum[i] = sum[i - 1];
		if(s[i] == '(') sum[i]++;
		else sum[i]--;
	}
	for (int i = 0; i <= n; i++) G[sum[i] + n].push_back(i);
	for (int i = 1; i <= n; i++) 
		if(s[i] == '(') sta[++top] = i;
		else if(top) dp[i] = dp[sta[top] - 1] + 1, top--;
	for (int i = 1; i <= n; i++) dp_sum[i] = dp_sum[i - 1] + dp[i];
	for (int i = 1; i <= q; i++)
	{
		int pigstdno = read(), l = read(), r = read();
		int ans = dp_sum[r] - dp_sum[l - 1], v = sum[l - 1] + n;
		int posl = lower_bound(G[v].begin(), G[v].end(), l) - G[v].begin();
		int posr = upper_bound(G[v].begin(), G[v].end(), r) - G[v].begin();
		ans -= dp[l - 1] * (posr - posl);
		printf("%lld\n", ans);
	}
	return 0;
}