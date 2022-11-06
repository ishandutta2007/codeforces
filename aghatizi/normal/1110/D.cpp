#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int maxk = 10;

int a[maxn] , dp[2][maxk][maxk];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		a[x]++;
	}

	int res = 0;
	for(int i = 1; i <= m; i++)
		while(a[i] >= 9)
			a[i] -= 3 , res++;

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < maxk; j++)
			for(int k = 0; k < maxk; k++)
				dp[i][j][k] = -1e9;

	for(int i = 0; i <= a[1]; i++)
		dp[1][0][i] = (a[1] - i) / 3;

	for(int i = 2; i <= m + 5; i++)
	{
		int t = i&1;
		for(int x = 0; x <= a[i - 1]; x++)
			for(int y = 0; y <= a[i]; y++)
			{
				dp[t][x][y] = -1e9;
				int lim = min(min(a[i] - y , a[i - 1] - x) , a[i - 2]);
				for(int sht = 0; sht <= lim; sht++)
					dp[t][x][y] = max(dp[t][x][y] , dp[!t][sht][x + sht] + sht + (a[i] - y - sht) / 3);
			}
	}

	cout << dp[(m + 5) & 1][0][0] + res << endl;
}