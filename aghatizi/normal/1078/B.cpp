#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;
const int maxm = 1e4 + 20;

int a[maxn];

short dp[2][maxm][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;

		a[x]++;
	}

	dp[0][0][0] = 1;
	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < maxm; j++)
			for(int k = 0; k <= n; k++)
			{
				int x = i&1;

				dp[x][j][k] = 0;
				for(int T = 0; T <= a[i] && T <= k && T * i <= j; T++)
				{
					dp[x][j][k] += dp[!x][j - T * i][k - T];

					if(dp[x][j][k] > 1)
					{
						dp[x][j][k] = 2;
						break;
					}
				}
			}

	int T = 0;

	for(int i = 0; i < maxn; i++)
		if(a[i])
			T++;

	int res = 0 , x = (maxn - 1)&1;
	for(int i = 1; i < maxn; i++)
		for(int j = 1; j <= a[i]; j++)
			if(dp[x][i * j][j] == 1)
			{
				if(j == a[i] && T == 2)
					res = n;
				res = max(res , j);
			}

	cout << res << endl;
}