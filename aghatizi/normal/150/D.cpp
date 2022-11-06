#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 150 + 20;

int a[maxn];
ll dp[maxn][maxn][maxn] , pd[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] < 0)
			a[i] = -1e9;
	}
	string s;
	cin >> s;
	s = '#' + s;

	memset(dp , -63 , sizeof dp);
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < i; j++)
			dp[i][j][0] = 0;

	for(int l = n; l >= 1; l--)
		for(int r = l; r <= n; r++)
		{
			for(int k = 1; k <= r - l + 1; k++)
			{
				if(l == r)
				{
					dp[l][r][k] = 0;
					continue;
				}

				if(k == 1)
				{
					for(int x = l; x <= r; x++)
						dp[l][r][k] = max(dp[l][r][k] , dp[l][x - 1][0] + dp[x + 1][r][0]);
					continue;
				}

				for(int x = l + 1; x <= r; x++)
					if(s[l] == s[x])
						dp[l][r][k] = max(dp[l][r][k] , dp[l + 1][x - 1][k - 2] + dp[x + 1][r][0]);

				for(int x = l + 1; x <= r; x++)
					dp[l][r][k] = max(dp[l][r][k] , dp[l][x - 1][0] + dp[x][r][k]);
			}

			for(int i = 0; i <= r - l + 1; i++)
				dp[l][r][0] = max(dp[l][r][0] , dp[l][r][i] + a[i]);

			pd[l][r] = max(pd[l][r] , dp[l][r][0]);
			for(int x = l; x < r; x++)
				pd[l][r] = max(pd[l][r] , pd[l][x] + pd[x + 1][r]);
		}

	cout << pd[1][n] << endl;
}