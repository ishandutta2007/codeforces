#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int dp[200005];
int main()
{
	int r, g;
	cin >> r;
	cin >> g;
	int h = 0;
	for(int i = 0; i < 1000; i ++)
	{
		if(i * (i + 1) / 2 <= r + g)
		{
			h = i;
		}
	}
	dp[0] = 1;
	for(int i = 1; i <= h; i ++)
	{
		for(int j = r; j >= 0; j --)
		{
			if(i * (i + 1) / 2 - j <= g)
			{
				dp[j] = dp[j];
			}
			else
			{
				dp[j] = 0;
			}
			if(j >= i)
			{
				dp[j] += dp[j - i];
			}
			dp[j] %= N;
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	int ans = 0;
	for(int j  = 0; j <= r; j ++)
	{
		ans += dp[j];
		ans %= N;
	}
	cout << ans;
	return 0;
}