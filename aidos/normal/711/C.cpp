#include <bits/stdc++.h>

#define ft first
#define st second
#define mp make_pair
#define pb push_back
#define sz(n) int(n.size())
#define all(n) n.begin(), n.end()


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

ll n, m, k, c[N], p[N][N];
ll dp[N][N][N];
bool u[N][N][N];

ll go (int x, int y, int z)
{
  if (z > k) return INF;
	if (x == n)
	{
		if (z != k) return INF;
		return 0;
	}
	if (dp[x][y][z] != -1) return dp[x][y][z];
	dp[x][y][z] = INF;
	if (c[x + 1] > 0)
	{
		if (y == c[x + 1]) 
		{
			ll cur = go(x + 1, c[x + 1], z);
			dp[x][y][z] = min(dp[x][y][z], cur);
		}
		else 
		{
			ll cur = go(x + 1, c[x + 1], z + 1);
			dp[x][y][z] = min(dp[x][y][z], cur); 
		}
	}
	else
	{
		for (int i = 1; i <= m; i ++)
		{
			if (y != i) 
			{
				ll cur = go(x + 1, i, z + 1);
				dp[x][y][z] = min(dp[x][y][z], cur + p[x + 1][i]);
			}
			else 
			{
				ll cur = go(x + 1, i, z);
				dp[x][y][z] = min(dp[x][y][z], cur + p[x + 1][i]);
			}
		}
	}
	//cout << x << " " << y << " " << z << " " << dp[x][y][z] << "\n";
	return dp[x][y][z];
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cin >> p[i][j];
		}
	}

	for (int i = 0; i <= n; i ++)
	{
		for (int j = 0; j <= m; j ++)
		{
			for (int q = 0; q <= k; q ++)
			{
				dp[i][j][q] = -1;
			}
		}
	}
	ll cur = go (0, 0, 0);
	if (cur == INF) cout << -1;
	else cout << cur;
	
}