#include <iostream>

#include <vector>

using namespace std;

int a[20];
int b[20][20];
long long dp[(1 << 18) + 5][20];
int main()
{
	int n, m, k;
	long long ans = 0;
	cin >> n;
	cin >> m;
	cin >> k;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < k; i ++)
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		b[x - 1][y - 1] = z;
	}
	for(int i = 1; i < 1 << n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			if((i >> j) & 1 == 1)
			{
				int x = 0;
				for(int q = 0; q < n; q ++)
				if((i >> q) % 2 == 1)
				{
					dp[i][j] = max(dp[i][j], dp[i - (1 << j)][q] + a[j] + b[j][q]);
				}
				if(__builtin_popcount(i) <= m && dp[i][j] > ans)
				{
					ans = max(ans, dp[i][j]);
					//cout << i << " " << j << endl;
				}
			}
		}
		//cout << i << " " << dp[i] << endl;
	}
	cout << ans;

	return 0;
}