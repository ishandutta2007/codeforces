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

const int N = 1010;
const int M = 20010;
const int maax = 10000;
int n;
int a[N];

ll dp[N][M] = {};

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	dp[0][maax + a[0]]++;
	dp[0][maax - a[0]]++;
	Loop(i, 1, n)
	{
		Loop(j, a[i], M)
		{
			dp[i][j] += dp[i - 1][j - a[i]];
			dp[i][j] %= Mod1;
		}
		Loop(j, 0, M - a[i])
		{
			dp[i][j] += dp[i - 1][j + a[i]];
			dp[i][j] %= Mod1;
		}
		dp[i][maax + a[i]]++;
		dp[i][maax - a[i]]++;
	}
	ll ans = 0;
	Loop(i, 0, n)
	{
		ans += dp[i][maax];
		ans %= Mod1;
	}
	cout << ans << '\n';
}