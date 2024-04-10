#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N = 15;

int n;
int a[N][N];
double cache[N][N];
bool vis[N][N];

double dp(int x, int y)
{
	if(x == 1 && y == 1)
		return 0;
	double &ans = cache[x][y];
	if(vis[x][y])
		return ans;
	vis[x][y] = 1;
	ans = 0;
	double p = 0;
	for(int d = 1; d <= 6; d++)
	{
		int nx = x, ny = y;
		if(x % 2 == 0)
		{
			ny += d;
			if(ny > 10)
			{
				nx--;
				int ex = ny - 10;
				ny = 10 - (ex - 1);
			}
		}
		else
		{
			ny -= d;
			if(ny < 1)
			{
				nx--;
				int ex = 1 - ny;
				ny = 1 + (ex - 1);
			}
		}
		double exp = 1e9;
		if(nx < 1)
		{
			p += 1.0l/6.0;
			ans += 1.0l/6.0;
		}
		else
		{	
			exp = 1 + dp(nx, ny);
			if(a[nx][ny])
				exp = min(exp, 1 + dp(nx - a[nx][ny], ny));
			ans += (1.0l/6.0) * exp;
		}
	}
	double lhs = 1 - p;
	ans /= lhs;
	return ans;
}

int32_t main()
{
	IOS;
	n = 10;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	double ans = dp(10, 1);
	cout << fixed << setprecision(12) << ans;
	return 0;
}