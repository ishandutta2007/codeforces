#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int sz[3] , a[maxn] , dp[maxn][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> sz[0] >> sz[1] >> sz[2];
	
	int n = sz[0] + sz[1] + sz[2];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < sz[i]; j++)
		{
			int x;
			cin >> x;
			a[x] = i;
		}
	}

	memset(dp , 63 , sizeof dp);
	memset(dp[0] , 0 , sizeof dp[0]);

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
		{
			if(j)
				dp[i][j] = min(dp[i][j] , dp[i][j - 1]);

			dp[i][j] = min(dp[i][j] , dp[i - 1][j] + (a[i] != j));
		}

	cout << dp[n][2] << endl;
}