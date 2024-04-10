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
const int N = 15, M = 2009, K = (1 << 12) + 9;
struct node
{
	int id, x;
}p[M];
int lg[K];
inline bool cmp(node xxx, node yyy) {return xxx.x > yyy.x;}
inline int lowbit(int x) {return x & (-x);}
int a[N][M], T, n, m, v[N][K], sum[K], dp[K];
signed main()
{
	T = read();
	for (int i = 0; i < 12; i++) lg[(1 << i)] = i;
	for (int ttt = 1; ttt <= T; ttt++)
	{
		memset(v, 0, sizeof(v));
		memset(dp, 0, sizeof(dp));
		n = read(), m = read();
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++) a[i][j] = read();
		for (int j = 1; j <= m; j++)
		{
			int mx = 0;
			for (int i = 0; i < n; i++) mx = max(mx, a[i][j]);
			p[j].id = j, p[j].x = mx;
		}
		sort(p + 1, p + m + 1, cmp);
		int cnt = min(n, m);
		for (int i = 1; i <= cnt; i++)
		{
			int pos = p[i].id;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < (1 << n); k++) sum[k] = 0;
				for (int k = 1; k < (1 << n); k++)
				{
					int s = lowbit(k), g = (lg[s] + j) % n; 
					sum[k] = sum[k - s] + a[g][pos];
				}
				for (int k = 0; k < (1 << n); k++) v[i][k] = max(v[i][k], sum[k]);
			}
			for (int Mask = (1 << n) - 1; Mask >= 0; Mask--)
				for (int j = Mask; j; j = (j - 1) & Mask)
					dp[Mask] = max(dp[Mask], dp[Mask - j] + v[i][j]);
		}
		cout << dp[(1 << n) - 1] << endl;
	}
	return 0;
}