#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;
 
int n, m;
int a[N];
double p[N][N], np[N][N];
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			p[i][j] = (a[i] > a[j]);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		for(int j = 1; j <= n; j++)
		{
			if(j == x || j == y)
				continue; 
			np[j][x] = np[j][y] = (p[j][x] + p[j][y]) / 2;
			np[x][j] = np[y][j] = (p[x][j] + p[y][j]) / 2;
		}
		p[x][y] = 0.5l;
		p[y][x] = 0.5l;
		for(int j = 1; j <= n; j++)
		{
			if(j == x || j == y)
				continue; 
			p[j][x] = p[j][y] = np[j][x];
			p[x][j] = p[y][j] = np[x][j];
		}
	}
	double ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
			ans += p[i][j];
	}
	cout << fixed << setprecision(12) << ans;
	return 0;
}