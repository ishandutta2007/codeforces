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

const int N = 2000020;

ll dp[N] = {};

int main()
{
	FAST;
	dp[3] = 4;
	Loop(i, 4, N)
	{
		if (i % 3 == 2)
			dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % Mod1;
		else
			dp[i] = (4 * (1 + dp[i - 4] + dp[i - 3]) + dp[i - 2]) % Mod1;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		cout << dp[k] << '\n';
	}
}