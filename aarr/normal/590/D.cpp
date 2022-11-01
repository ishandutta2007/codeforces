#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int dp[155][50005];
int a[155];
int main()
{
	int n, k, s;
	cin >> n;
	cin >> k;
	cin >> s;
	s = min(s, n * n / 2);
	s += k * (k + 1) / 2;
	int pyh = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}

	for(int j = 1; j <= k; j ++)
	{
		for(int q = 0; q <= s; q ++)
		{
			dp[j][q] = N;
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = k; j >= 1; j --)
		{
			for(int q = 0; q <= s; q ++)
			{
				if(q >= i)
				{
					dp[j][q] = min(dp[j][q], dp[j - 1][q - i] + a[i]);
				}
			}
		}
	}
	int ans = N;
	for(int q = 0; q <= s; q ++)
	{
		//cout << dp[k][q] << " ";
		ans = min(ans, dp[k][q]);
	}
	cout << ans;
	return 0;
}