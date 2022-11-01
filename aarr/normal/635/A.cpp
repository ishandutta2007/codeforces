#include <iostream>

using namespace std;

int dp[12][12];
int a[12][12];
int u[12][12];
int l[12][12];
int main()
{
	int r, c, n, k, ans = 0;
	cin >> r;
	cin >> c;
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		a[x][y] = 1;
	}
	for(int i = 1; i <= r; i ++)
	{
		for(int j = 1; j <= c; j ++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	for(int i = 1; i <= r; i ++)
	{
		for(int ii = 0; ii < i; ii ++)
		{
			for(int j = 1; j <= c; j ++)
			{
				for(int jj = 0; jj < j; jj ++)
				{
					if(dp[i][j] - dp[ii][j] - dp[i][jj] + dp[ii][jj] >= k)
					{
						ans ++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}