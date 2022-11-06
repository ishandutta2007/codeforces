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
const int N = 2509, mod = 1e9 + 7;
vector<int> col[4];
int dp1[59][59][N], dp2[59][N], T, n, ans, jc[N];
int v[59][59][59][4], g[59][59][59];
inline void init(int a, int b, int c)
{
	v[1][0][0][1] = 1;
	v[0][1][0][2] = 1;
	v[0][0][1][3] = 1;
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			for (int k = 0; k <= c; k++)
			{
				v[i][j + 1][k][2] = (v[i][j + 1][k][2] + v[i][j][k][1] + v[i][j][k][3]) % mod;
				v[i + 1][j][k][1] = (v[i + 1][j][k][1] + v[i][j][k][2] + v[i][j][k][3]) % mod;
				v[i][j][k + 1][3] = (v[i][j][k + 1][3] + v[i][j][k][1] + v[i][j][k][2]) % mod;
				g[i][j][k] = (v[i][j][k][1] + v[i][j][k][2] + v[i][j][k][3]) * jc[i] % mod * jc[j] % mod * jc[k] % mod;
			}
}
signed main()
{
	n = read(), T = read(); dp1[0][0][0] = 1, dp2[0][0] = 1;
	for (int ttt = 1; ttt <= n; ttt++)
	{
		int t = read(), g = read();
		if(g <= 2)
		{
			for (int i = col[1].size(); i >= 0; i--)
				for (int j = col[2].size(); j >= 0; j--)
					for (int k = T - t; k >= 0; k--)
						if(g == 1) dp1[i + 1][j][k + t] = (dp1[i + 1][j][k + t] + dp1[i][j][k]) % mod;
						else dp1[i][j + 1][k + t] = (dp1[i][j + 1][k + t] + dp1[i][j][k]) % mod;
		}
		else
		{
			for (int i = col[3].size(); i >= 0; i--)
				for (int k = T - t; k >= 0; k--)
					dp2[i + 1][k + t] = (dp2[i + 1][k + t] + dp2[i][k]) % mod;
		}
		col[g].push_back(t);
	}
	jc[0] = 1; int a = col[1].size(), b = col[2].size(), c = col[3].size();
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	init(a, b, c); 
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			for (int k = 0; k <= c; k++)
				for (int s = 0; s <= T; s++)
				{
					ans = (ans + g[i][j][k] * dp1[i][j][s] % mod * dp2[k][T - s] % mod) % mod;
				}
	cout << ans << endl;
	return 0;
}