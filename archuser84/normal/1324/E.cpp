#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 2000;
int n, h, l, r;
int a[N];

int dp[N][N];

int mod(int x, int m)
{
	return (x % m + m) % m;
}

int Solve()
{
	int sum = a[0];
	dp[0][0] = l <= mod(sum, h) && mod(sum, h) <= r;
	dp[0][1] = l <= mod(sum - 1, h) && mod(sum - 1, h) <= r;
	Loop(i, 1, n)
	{
		sum += a[i];
		dp[i][0] = dp[i - 1][0] + (l <= mod(sum, h) && mod(sum, h) <= r);
		Loop(j, 1, i + 1)
			dp[i][j] = max(dp[i - 1][j] + (l <= mod(sum - j, h) && mod(sum - j, h) <= r), dp[i - 1][j - 1] + (l <= mod(sum - j, h) && mod(sum - j, h) <= r));
		dp[i][i + 1] = dp[i - 1][i] + (l <= mod(sum - i - 1, h) && mod(sum - i - 1, h) <= r);
	}
	int ans = 0;
	Loop(i, 0, n + 1)
		ans = max(ans, dp[n - 1][i]);
	return ans;
}

int main()
{
	FAST;
	cin >> n >> h >> l >> r;
	Loop(i, 0, n)
		cin >> a[i];
	cout << Solve();
}