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
using namespace std;

const int N = 110;
const int L = 3010;
ll dp[2][L][N] = {};
int n, l;
ll a[N];
ll b[N];

int main()
{
	FAST;
	cin >> n >> l;
	Loop(i, 0, n)
	{
		cin >> a[i] >> b[i];
		dp[0][a[i]][i]++;
		if (a[i] != b[i])
			dp[1][b[i]][i]++;
	}
	Loop(t, 1, l + 1)
	{
		Loop(lb, 0, n)
		{
			Loop(nb, 0, n)
			{
				if (lb == nb)
					continue;
				if (a[lb] == a[nb] && t > a[nb])
					dp[0][t][nb] += dp[1][t - a[nb]][lb];
				if (b[lb] == a[nb] && t > a[nb])
					dp[0][t][nb] += dp[0][t - a[nb]][lb];
				if (a[nb] != b[nb])
				{
					if (a[lb] == b[nb] && t > b[nb])
						dp[1][t][nb] += dp[1][t - b[nb]][lb];
					if (b[lb] == b[nb] && t > b[nb])
						dp[1][t][nb] += dp[0][t - b[nb]][lb];
				}
				dp[0][t][nb] %= Mod1;
				dp[1][t][nb] %= Mod1;
			}
		}
	}
	ll ans = 0;
	Loop(i, 0, n)
		ans += dp[0][l][i] + dp[1][l][i];
	ans %= Mod1;
	cout << ans;
}