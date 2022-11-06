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
const int N = 1e6 + 9, K = (1 << 21) + 9;
int n;
char a[N];
int p[N], dp[K], kk;
int now, pos;
signed main()
{
	scanf("%s", a + 1);
	n = strlen(a + 1); 
	for (int i = 1; i <= n; i++) p[i] = a[i] - 'a'; 
	kk = (1 << 20) - 1;
	for (int i = 1; i <= n; i++)
	{
		now = 0, pos = i;
		while(!(now & (1 << p[pos])) && pos <= n)
		{
			now |= (1 << p[pos]);
			dp[now] = (pos - i + 1);
			pos++;
		}
	}
	for (int i = 0; i <= kk; i++) 
		for (int j = 0; j < 20; j++)
			if((i & (1 << j))) 
			{
				int x = (i ^ (1 << j));
				dp[i] = max(dp[i], dp[x]);
			}
	int ans = 0;
	for (int i = 0; i <= kk; i++) ans = max(ans, dp[i] + dp[(kk ^ i)]);
	cout << ans << endl;
	return 0;
}