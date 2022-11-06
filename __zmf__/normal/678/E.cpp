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
const int mod = 1e9 + 7;
const int N = 20, P = (1 << 20) + 9;
double ans, dp[P][N], a[N][N], val[N];
int n, St;
signed main()
{
	n = read();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
	dp[(1 << n) - 1][0] = 1;
	for (int i = (1 << n) - 2; i >= 0; i--)
		for (int j = 0; j < n; j++)
		{
			if((i >> j) & 1)
			{
				for (int k = 0; k < n; k++)
					if(!((i >> k) & 1))
					{
						dp[i][j] = max(dp[i][j], dp[i ^ (1 << k)][j] * a[j][k] + dp[i ^ (1 << k)][k] * a[k][j]);
					}
			}
		//	cout << i << " " << j << " " << dp[i][j] << endl;
		}
	ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, dp[(1 << i)][i]);
	printf("%.12lf\n", ans);
	return 0;
}
/*
4 4
qwq
1 3
2 4
3 4
*/