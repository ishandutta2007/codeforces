#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 505;
const int M = 2e5 + 5;
 
int n, m;
int row[N], col[N], dp[M];
int a[N][N];
bool sieve[M];
 
void precompute()
{
	for(int i = 2; i < M; i++)
		sieve[i] = 1;
	for(int i = 2; i < M; i++)
	{
		if(sieve[i])
		{
			for(int j = 2; i * j < M; j++)
				sieve[i * j] = 0;
		}
	}
	for(int i = M - 2; i >= 1; i--)
	{
		dp[i] = dp[i + 1] + 1;
		if(sieve[i])
			dp[i] = 0;
	}
}
 
int32_t main()
{
	IOS;
	precompute();
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			int x = dp[a[i][j]];
			row[i] += x;
			col[j] += x;
		}
	}
	int ans = 2e9;
	for(int i = 1; i <= n; i++)
		ans = min(ans, row[i]);
	for(int i = 1; i <= m; i++)
		ans = min(ans, col[i]);
	cout << ans;
	return 0;
}