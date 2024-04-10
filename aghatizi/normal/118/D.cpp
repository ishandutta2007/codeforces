#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;
const int maxk = 12;
const int mod = 1e8;

int dp[maxn][maxn][2];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n1 , n2 , k1 , k2;
	cin >> n1 >> n2 >> k1 >> k2;

	// 0 : mard
	// 1 : zan
	// i : mard
	// j : zan
	dp[1][0][0] = 1;
	dp[0][1][1] = 1;
	dp[0][0][1] = dp[0][0][0] = 1;

	for(int i = 0; i <= n1; i++)
		for(int j = 0; j <= n2; j++)
		{
			if(i + j <= 1)
				continue;
			if(i)
			{
				mkay(dp[i][j][0] += dp[i - 1][j][1]);
				mkay(dp[i][j][0] += dp[i - 1][j][0]);
				if(i >= k1 + 1)
					mkay(dp[i][j][0] -= dp[i - k1 - 1][j][1]);
			}

			if(j)
			{
				mkay(dp[i][j][1] += dp[i][j - 1][0]);
				mkay(dp[i][j][1] += dp[i][j - 1][1]);
				if(j >= k2 + 1)
					mkay(dp[i][j][1] -= dp[i][j - k2 - 1][0]);
			}
		}

	int ans = 0;
	mkay(ans = dp[n1][n2][0] + dp[n1][n2][1]);

	cout << ans << endl;
}