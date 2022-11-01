#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int floyd[65][65][65][65];
int dp[65][65][65];
int main()
{
	ios :: sync_with_stdio(0);
	int n, m, r;
	cin >> n;
	cin >> m;
	cin >> r;
	for(int ii = 1; ii <= m; ii ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				cin >> floyd[ii][i][j][0];
			}
		}
	}
	for(int ii = 1; ii <= m; ii ++)
	{
		for(int k = 1; k <= n; k ++)
		{
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j <= n; j ++)
				{
					floyd[ii][i][j][k] = min(floyd[ii][i][j][k - 1], floyd[ii][i][k][k - 1] + floyd[ii][k][j][k - 1]);
				}
			}
		}
	}
	//cout << "alaki" << endl;
	for(int ii = 1; ii <= m; ii ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				//cout << floyd[ii][i][j][n] << " ";
			}
			//cout << endl;
		}
	}
	//cout << 79 << endl;
	for(int k = 0; k <= 1; k ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				dp[k][i][j] = N;
			}
		}
	}
	for(int ii = 1; ii <= m; ii ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				dp[0][i][j] = min(dp[0][i][j], floyd[ii][i][j][n]);
			}
		}
	}
	for(int k = 1; k <= n; k ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				dp[k][i][j] = dp[k - 1][i][j];
				for(int q = 1; q <= n; q ++)
				{
					dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i][q] + dp[0][q][j]);
				}
			}
		}
	}
	for(int jj = 0; jj < r; jj ++)
	{
		int s, e, k;
		cin >> s;
		cin >> e;
		cin >> k;
		cout << dp[min(k, n)][s][e] << endl;
	}
	return 0;
}