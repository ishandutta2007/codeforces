#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e4 + 20;
const int maxk = 200 + 20;

int dp[maxn][maxk][2] , mx[maxn][maxk] , a[maxn];

// 0 : -
// 1 : +

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		for(int j = 1; j < maxk; j++)
			for(int k = 0; k < 2; k++)
				dp[i][j][k] = -1e9;

	int n , k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
		{
			dp[i][j][0] = dp[i - 1][j][0];
			dp[i][j][1] = dp[i - 1][j][1];

			int sum = 0;
			for(int x = i - 1; x >= 0; x--)
			{
				sum += a[x + 1];

				if(j == 1)
				{
					dp[i][j][0] = max(dp[i][j][0] , -sum);
					dp[i][j][1] = max(dp[i][j][1] , sum);
					continue;
				}

				dp[i][j][0] = max(dp[i][j][0] , dp[x][j - 1][0]);
				dp[i][j][0] = max(dp[i][j][0] , dp[x][j - 1][1] - sum * 2);

				if(j == k)
					ans = max(ans , sum + dp[x][j - 1][0]);

				dp[i][j][1] = max(dp[i][j][1] , dp[x][j - 1][0] + sum * 2);
				dp[i][j][1] = max(dp[i][j][1] , dp[x][j - 1][1]);

				if(j == k)
					ans = max(ans , dp[x][j - 1][1] - sum);
			}
		}

	cout << ans << endl;
}