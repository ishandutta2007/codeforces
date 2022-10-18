#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

double len(int x, int y)
{
	return sqrt(x * x + y * y);
}

signed main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ax[2], ay[2], bx, by;
	cin >> ax[0] >> ay[0] >> ax[1] >> ay[1] >> bx >> by;
	int n;
	cin >> n;
	int gx[n], gy[n];
	for(int i = 0; i < n; i++)
		cin >> gx[i] >> gy[i];
	double dp[4][n + 1];
	fill(dp[0] + 1, dp[0] + n + 1, 1e18);
	fill(dp[1], dp[1] + n + 1, 1e18);
	fill(dp[2], dp[2] + n + 1, 1e18);
	fill(dp[3], dp[3] + n + 1, 1e18);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			dp[j][i] = dp[j][i - 1] + 2 * len(gx[i - 1] - bx, gy[i - 1] - by);
			if(j & 1)
			{
				dp[j][i]  = min(dp[j][i], dp[0][i - 1] + len(gx[i - 1] - ax[0], gy[i - 1] - ay[0]) + len(gx[i - 1] - bx, gy[i - 1] - by));
				if(j == 3) dp[j][i]  = min(dp[j][i], dp[2][i - 1] + len(gx[i - 1] - ax[0], gy[i - 1] - ay[0]) + len(gx[i - 1] - bx, gy[i - 1] - by));
			}
			if(j & 2)
			{
				dp[j][i]  = min(dp[j][i], dp[0][i - 1] + len(gx[i - 1] - ax[1], gy[i - 1] - ay[1]) + len(gx[i - 1] - bx, gy[i - 1] - by));
				if(j == 3) dp[j][i]  = min(dp[j][i], dp[1][i - 1] + len(gx[i - 1] - ax[1], gy[i - 1] - ay[1]) + len(gx[i - 1] - bx, gy[i - 1] - by));
			}
		}
	}
	cout << fixed << setprecision(8) << min(dp[1][n], min(dp[2][n], dp[3][n])) << "\n";
}