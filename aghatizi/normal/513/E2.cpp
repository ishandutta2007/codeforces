#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e4 + 20;
const int maxk = 2e2 + 20;

int dp[maxn][maxk][2] , mx[maxn][maxk][2][2] , sum[maxn] , a[maxn];

// 0 : -
// 1 : +

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxk; j++)
			for(int k = 0; k < 2; k++)
				dp[i][j][k] = mx[i][j][k][0] = mx[i][j][k][1] = -1e9;

	int n , k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i] , sum[i] = sum[i - 1] + a[i];

	int ans = 0 , Mn = 0 , Mx = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
		{
			dp[i][j][0] = dp[i - 1][j][0];
			dp[i][j][1] = dp[i - 1][j][1];

			if(j > 1)
			{
				dp[i][j][0] = max(dp[i][j][0] , mx[i - 1][j - 1][0][0]);
				dp[i][j][0] = max(dp[i][j][0] , mx[i - 1][j - 1][0][1] - sum[i] * 2);
			
				dp[i][j][1] = max(dp[i][j][1] , mx[i - 1][j - 1][1][0] + sum[i] * 2);
				dp[i][j][1] = max(dp[i][j][1] , mx[i - 1][j - 1][1][1]);
			}
			else
			{
				dp[i][j][0] = max(dp[i][j][0] , -(sum[i] - Mx));
				dp[i][j][1] = max(dp[i][j][1] , sum[i] - Mn);
			}

			Mx = max(Mx , sum[i]);
			Mn = min(Mn , sum[i]);

			mx[i][j][0][0] = max(mx[i - 1][j][0][0] , dp[i][j][0]);
			mx[i][j][0][1] = max(mx[i - 1][j][0][1] , dp[i][j][1] + sum[i] * 2);
			mx[i][j][1][0] = max(mx[i - 1][j][1][0] , dp[i][j][0] - sum[i] * 2);
			mx[i][j][1][1] = max(mx[i - 1][j][1][1] , dp[i][j][1]);
		}

	Mn = 1e9 , Mx = -1e9;
	for(int i = n; i >= 1; i--)
	{
		ans = max(ans , dp[i][k - 1][0] - sum[i] + Mx);
		ans = max(ans , dp[i][k - 1][1] + sum[i] - Mn);

		Mx = max(Mx , sum[i]);
		Mn = min(Mn , sum[i]);
	}

	cout << ans << endl;
}