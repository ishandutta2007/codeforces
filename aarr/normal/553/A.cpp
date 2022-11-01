#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int dp[2005][2005];
int a[1005];
int main()
{
	int n;
	long long m = 1, s = 0, x = 0;
	cin >> n;
	dp[0][0] = 1;
	for(int i = 0; i <= 2003; i ++)
	{
		for(int j = 0; j <= 2003; j ++)
		{
			if(i > 0)
			{
				dp[i][j] += dp[i - 1][j];
				if(j > 0)
				{
					dp[i][j] += dp[i - 1][j - 1];
				}
				dp[i][j] %= N;
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		cin >> x;
		m *= dp[x + s - 1][s];
		s += x;
		m = m % N;
	}
	cout << m;
	return 0;
}