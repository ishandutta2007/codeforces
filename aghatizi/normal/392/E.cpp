#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e2 + 20;

int a[maxn] , v[maxn];

int full[maxn][maxn] , up[maxn][maxn] , down[maxn][maxn] , dp[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	fill(v , v + maxn , -1e6);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int l = 0; l < n; l++)
		for(int r = l; r < n; r++)
			full[l][r] = up[l][r] = down[l][r] = -1e6;

	for(int l = n - 1; l >= 0; l--)
		for(int r = l; r < n; r++)
		{
			if(l == r)
			{
				up[l][r] = down[l][r] = full[l][r] = v[1];
				dp[l][r] = max(0 , v[1]);
				continue;
			}

			if(a[l] < a[r] && a[r] - a[l] + 1 < maxn)
			{
				if(a[r] - a[l] == 1)
					up[l][r] = v[2] + full[l + 1][r - 1];
				else
				{
					for(int k = l + 1; k < r; k++)
						if(a[k] - a[l] == 1)
							up[l][r] = max(up[l][r] , full[l + 1][k - 1] + up[k][r] - v[a[r] - a[k] + 1] + v[a[r] - a[l] + 1]);
				}
			}
			if(a[l] > a[r] && a[l] - a[r] + 1 < maxn)
			{
				if(a[r] - a[l] == -1)
					down[l][r] = v[2] + full[l + 1][r - 1];
				else
				{
					for(int k = l + 1; k < r; k++)
						if(a[k] - a[l] == -1)
							down[l][r] = max(down[l][r] , full[l + 1][k - 1] + down[k][r] - v[a[k] - a[r] + 1] + v[a[l] - a[r] + 1]);
				}
			}

			full[l][r] = max(up[l][r] , down[l][r]);
			for(int k = l; k < r; k++)
				full[l][r] = max(full[l][r] , full[l][k] + full[k + 1][r]);

			for(int k = l + 1; k < r; k++)
				if(a[l] < a[k] && a[k] > a[r])
				{
					int x1 = a[k] - a[l] + 1;
					int x2 = a[k] - a[r] + 1;
					if(x1 + x2 < maxn)
						full[l][r] = max(full[l][r] , up[l][k] + down[k][r] - v[x1] - v[x2] + v[x1 + x2 - 1]);
				}

			dp[l][r] = max(0 , full[l][r]);
			for(int k = l; k <= r; k++)
				dp[l][r] = max(dp[l][r] , dp[l][k] + dp[k + 1][r]);
		}

	cout << dp[0][n - 1] << endl;
}