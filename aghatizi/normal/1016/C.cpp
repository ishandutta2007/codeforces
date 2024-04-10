#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

ll pd[maxn][2] , sum[maxn] , dp[maxn][2] , a[maxn][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < 2 * n; i++)
		cin >> a[i % n][i >= n];

	for(int i = n - 1; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + a[i][0] + a[i][1];

		for(int j = 0; j < 2; j++)
			pd[i][j] = pd[i + 1][j] + sum[i + 1] + a[i][!j] * (2 * (n - i - 1) + 1);

	}

	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j < 2; j++)
			dp[i][j] = max(pd[i][j] , 2 * sum[i + 1] + dp[i + 1][!j] + a[i][!j]);

	cout << dp[0][0] << endl;
}