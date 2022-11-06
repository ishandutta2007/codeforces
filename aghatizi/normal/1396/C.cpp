#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e6 + 20;
const int maxg = 8;

ll x[maxn] , y[maxn];

ll dp[maxn][maxg];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , r1 , r2 , r3 , d;
	cin >> n >> r1 >> r2 >> r3 >> d;

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		x[i] = 1LL * r1 * tmp + r3;
		y[i] = min(1LL * r1 * tmp + r1 , r2) + r1;
	}

	memset(dp , 63 , sizeof dp);

	dp[0][1] = 0;
	for(int i = 0; i < n - 1; i++)
		for(int j = 1; j < maxg; j++)
			for(int k = 1; k < maxg; k++)
			{
				ll cal = dp[i][j] + 1LL * k * d;
				if((j % 2) != (k % 2) && (j % 2) == 0)
					continue;
				
				if((j + 1) / 2 + k / 2 >= 2)
					cal += y[i];
				else
					cal += x[i];

				dp[i + 1][k] = min(dp[i + 1][k] , cal);
			}

	ll res = 8e18;
	for(int i = 1; i < maxg; i++)
	{
		if((i + 1) / 2 >= 2)
			res = min(res , dp[n - 1][i] + y[n - 1]);
		else
			res = min(res , dp[n - 1][i] + x[n - 1]);
	}

	cout << res << endl;
}