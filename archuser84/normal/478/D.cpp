#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;

ll dp[2][N] = {};

int main()
{
	FAST;
	int r, g;
	cin >> r >> g;
	ll n = r + g;
	if (g)
		dp[0][0] = 1;
	if (r)
		dp[0][1] = 1;
	for (ll i = 2;; i++)
	{
		bool k = !(i & 1);
		ll sum = 0;
		memset(dp[k], 0, sizeof(dp[i]));
		Loop(j, 0, r + 1)
		{
			if (g >= i * (i + 1) / 2 - j)
				dp[k][j] = (dp[k][j] + dp[!k][j]) % Mod1;
			if (r >= j + i)
				dp[k][j + i] = (dp[k][j + i] + dp[!k][j]) % Mod1;
			sum = (sum + dp[k][j]) % Mod1;
		}
		if (sum == 0)
		{
			ll ans = 0;
			Loop(j, 0, r + 1)
				ans = (ans + dp[!k][j]) % Mod1;
			Kill(ans);
		}
	}
}