#include <iostream>

using namespace std;

long long a[205];
long long dp[205][205];
int main()
{
	int n, m, x;
	cin >> n;
	cin >> m;
	cin >> x;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i <= n + 1; i ++)
	{
		for(int j = 0; j <= x + 1; j ++)
		{
			//dp[i][j] = 1000 * 1000 * 1000 + 7;
		}
	}
	a[n + 1] = 0;
	//dp[0][0] = 0;
	for(int i = 1; i <= n + 1; i ++)
	{
		for(int j = 1; j <= x + 1; j ++)
		{
			for(int k = i - m; k < i; k ++)
			{
				//cout << i << " " << j << " " << k << endl;
				if(k == 0 || (k > 0 && dp[k][j - 1] != 0))
				{
					dp[i][j] = max(dp[i][j], dp[k][j - 1] + a[i]);
				}
			}
		}
	}
	for(int i = 0; i <= n + 1; i ++)
	{
		for(int j = 0; j <= x + 1; j ++)
		{
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	if(dp[n + 1][x + 1] == 0)
	{
		dp[n + 1][x + 1] --;
	}
	cout << dp[n + 1][x + 1];
	return 0;
}