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
const int N = 259;
int n, m, Q, p;
char mp[N][N];
int a[N][N], vis[N][N];
struct point
{
	int x, y, step;
}q[N * N];
int det[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
inline void spread(int x, int y, int val)
{
	int f = 0, e = 1; q[1].x = x, q[1].y = y, q[1].step = 1; vis[x][y] = 1;
	while(f < e)
	{
		point u = q[++f];
		for (int i = 0; i < 4; i++)
		{
			point v = u; v.x = u.x + det[i][0], v.y = u.y + det[i][1], v.step = u.step + 1;
			if(v.x <= 0 || v.x > n || v.y <= 0 || v.y > m) continue;
			if(mp[v.x][v.y] == '*') continue;
			if(vis[v.x][v.y]) continue;
			if(val < (1 << (v.step - 1))) continue;
			vis[v.x][v.y] = 1; q[++e] = v;
		}
	}
	for (int i = 1; i <= e; i++)
	{
		vis[q[i].x][q[i].y] = 0; a[q[i].x][q[i].y] += (val >> (q[i].step - 1));
	}
	return ;
}
signed main()
{
	n = read(), m = read(), Q = read(), p = read();
	for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			if(mp[i][j] != '.' && mp[i][j] != '*') 
				spread(i, j, (mp[i][j] - 'A' + 1) * Q);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += (a[i][j] > p); 
	cout << ans << endl;
	return 0;
}