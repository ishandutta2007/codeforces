#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 110;
ll g[N][N];
int n, m;

ll dp[N][N];

bool bad(int i, int j) { return g[i][j] < g[0][0] + i + j; }
ll over(int i,int j) { return g[i][j] - (g[0][0] + i + j); }

ll solve()
{
	dp[0][0] = 0;
	Loop(i, 0, n)
	{
		Loop(j, 0, m)
		{
			if (i == 0 && j == 0)
				continue;
			dp[i][j] = -1;
			if (bad(i, j))
				continue;
			if (i > 0 && dp[i - 1][j] != -1)
			{
				dp[i][j] = dp[i - 1][j] + over(i, j);
			}
			if (j > 0 && dp[i][j - 1] != -1)
			{
				ll x = dp[i][j - 1] + over(i, j);
				if(dp[i][j] == -1 || dp[i][j] > x)
					dp[i][j] = x;
			}
		}
	}
	return dp[n - 1][m - 1] == -1 ? 1LL << 62 : dp[n - 1][m - 1];
}

ll Solve()
{
	ll base;
	if (g[n - 1][m - 1] >= g[0][0] + n + m - 2)
	{
		base = g[n - 1][m - 1] - (g[0][0] + n + m - 2);
		g[n - 1][m - 1] = g[0][0] + n + m - 2;
	}
	else
	{
		base = g[0][0] - (g[n - 1][m - 1] - n - m + 2);
		g[0][0] = g[n - 1][m - 1] - n - m + 2;
	}
	ll ans = solve();
	Loop(i, 0, n)
	{
		Loop(j, 0, m)
		{
			if (bad(i,j))
			{
				ll x = (g[0][0] + i + j) - g[i][j];
				g[0][0] -= x; g[n - 1][m - 1] -= x;
				ans = min(ans, 2*x + solve());
				g[0][0] += x; g[n - 1][m - 1] += x;
			}
		}
	}
	return base + ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		Loop(i, 0, n)
			Loop(j, 0, m)
				cin >> g[i][j];
		cout << Solve() << '\n';
	}
}