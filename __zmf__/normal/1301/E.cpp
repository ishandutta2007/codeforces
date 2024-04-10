/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 509;
int n, m, q;
int sum[N][N][4], res[N][N][N / 2];
char s[N];
int a[N], v[N][N];
int tuu;
inline int check(int x1, int y1, int x2, int y2, int col, int step)
{
	int res = sum[x2][y2][col] - sum[x1 - 1][y2][col] - sum[x2][y1 - 1][col] + sum[x1 - 1][y1 - 1][col];
//	if(tuu) cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << col << " " << step << " " << res << endl;
	if(res != step) return 0;
	else return 1;
}
inline int get_val(int x1, int y1, int x2, int y2, int col)
{
	return res[x2][y2][col] - res[x1 - 1][y2][col] - res[x2][y1 - 1][col] + res[x1 - 1][y1 - 1][col];
}
signed main()
{
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++)
			if(s[j] == 'R') a[j] = 0;
			else if(s[j] == 'Y') a[j] = 1;
			else if(s[j] == 'G') a[j] = 2;
			else a[j] = 3;
		for (int j = 1; j <= m; j++)
			for (int c = 0; c < 4; c++)
				sum[i][j][c] = sum[i - 1][j][c] + sum[i][j - 1][c] - sum[i - 1][j - 1][c] + (a[j] == c); 
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; i + 2 * k - 1 <= n && j + 2 * k - 1 <= m; k++)
			{
				int flag = 1;
				for (int c = 0; c < 4; c++)
				{
					int qwq1 = 0, qwq2 = 0; if(c & 1) qwq1 = 1; if(c & 2) qwq2 = 1;
					if(!check(i + qwq1 * k, j + qwq2 * k, i + qwq1 * k + k - 1, j + qwq2 * k + k - 1, c, k * k)) flag = 0;
				}
				if(flag) 
				{
				//	cout << i << " " << j << " " << k << endl; 
					v[i][j] = k; break;
				}
			}
	for (int k = 1; k <= n / 2; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				res[i][j][k] = res[i - 1][j][k] + res[i][j - 1][k] - res[i - 1][j - 1][k] + (v[i][j] == k);
	for (int i = 1; i <= q; i++)
	{
		int r1 = read(), c1 = read(), r2 = read(), c2 = read();
		int mx = min(r2 - r1 + 1, c2 - c1 + 1) / 2, flag = 0;
		for (int j = mx; j >= 1; j--)
		{
			int v = get_val(r1, c1, r2 - j * 2 + 1, c2 - j * 2 + 1, j);
			if(v) 
			{
				printf("%lld\n", j * j * 4ll); flag = 1; break;
			}
		}
		if(!flag) puts("0");
	}
	return 0;
}