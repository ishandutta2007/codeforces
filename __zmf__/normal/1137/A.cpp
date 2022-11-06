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
const int N = 1009;
int n, m;
int a[N][N], b[N];
int x[N], y[N];
int c[N][N], d[N][N];
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) b[j] = a[i][j];
		sort(b + 1, b + m + 1);
		int tot = unique(b + 1, b + m + 1) - b - 1;
		x[i] = tot;
		for (int j = 1; j <= m; j++) c[i][j] = lower_bound(b + 1, b + tot + 1, a[i][j]) - b;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++) b[j] = a[j][i];
		sort(b + 1, b + n + 1);
		int tot = unique(b + 1, b + n + 1) - b - 1;
		y[i] = tot;
		for (int j = 1; j <= n; j++) d[j][i] = lower_bound(b + 1, b + tot + 1, a[j][i]) - b; 
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) 
		{
			int res = max(x[i], y[j]);
		//	cout << x[i] << " " << y[j] << " " << c[i][j] << " " << d[i][j] << endl;
			if(c[i][j] >= d[i][j]) res = max(res, c[i][j] - d[i][j] + y[j]);
			else res = max(res, d[i][j] - c[i][j] + x[i]);
			printf("%lld ", res);
		}
		puts("");
	}
	return 0;
}