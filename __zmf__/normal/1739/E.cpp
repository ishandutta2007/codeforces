/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
*/

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 2e5 + 9;
int n;
char s[2][N];
int a[2][N], t[N], sum;
int dp[N][2][4];
// 0,1 -> u/d
//  
inline int v(int x, int y) {return x * 2 + y;}
signed main()
{
	n = read();
	scanf("%s", s[0] + 1);
	scanf("%s", s[1] + 1);
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = s[i][j] - '0', sum += a[i][j];
	for (int i = 1; i <= n; i++) t[i] = v(a[0][i], a[1][i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[1][0][v(0, a[1][1])] = 0;
	dp[1][0][0] = a[1][1];
	for (int i = 2; i <= n; i++) 
		for (int lst = 0; lst < 4; lst++)
			for (int now = 0; now < 4; now++)
				for (int op = 0; op < 2; op++) 
				{
					if((lst & t[i - 1]) != lst) continue;
					if((now & t[i]) != now) continue;
					int tt = (t[i] ^ now), det = 0;
					for (int j = 0; j < 2; j++) 
						if(tt & (1 << j)) det++;
					int val = dp[i - 1][op][lst] + det;
					if(op == 0) 
					{
						int f1 = 0, f2 = 0;
						if(lst & 1) f1 = 1; 
						if(now & 2) f2 = 1;
						if(f1 + f2 == 0) dp[i][op][now] = min(dp[i][op][now], val);
						if(f1 + f2 == 2) continue;
						if(f1 == 1) dp[i][(op ^ 1)][now] = min(dp[i][(op ^ 1)][now], val);
						if(f2 == 1) dp[i][op][now] = min(dp[i][op][now], val);
					}
					else
					{
						int f1 = 0, f2 = 0;
						if(lst & 2) f1 = 1; if(now & 1) f2 = 1;
						if(f1 + f2 == 0) dp[i][op][now] = min(dp[i][op][now], val);
						if(f1 + f2 == 2) continue;
						if(f1 == 1) dp[i][(op ^ 1)][now] = min(dp[i][(op ^ 1)][now], val);
						if(f2 == 1) dp[i][op][now] = min(dp[i][op][now], val);
					}
				}
	int ans = 1e9;
	for (int op = 0; op < 2; op++) 
		for (int j = 0; j < 4; j++)
		{
		//	cout << op << " " << j << " " << dp[n][op][j] << endl;
			ans = min(ans, dp[n][op][j]);
		}
	cout << sum - ans << endl;
	return 0;
}