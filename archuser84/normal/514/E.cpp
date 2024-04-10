#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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

int d[100010];
ll dp[101] = {};
ll matric[101][101] = {};
ll ansmat[101][101] = {};
int n, x;

void my_pow()
{
	Loop(i, 0, 101)
		ansmat[i][i] = 1;
	ll h[101][101];
	for (; x > 0; x >>= 1)
	{
		if (x & 1)
		{
			Loop(i, 0, 101)
				Loop(j, 0, 101)
					h[i][j] = ansmat[i][j];
			Loop(i, 0, 101)
			{
				Loop(j, 0, 101)
				{
					ansmat[i][j] = 0;
					Loop(k, 0, 101)
					{
						ansmat[i][j] += (matric[i][k] * h[k][j]) % Mod1;
						ansmat[i][j] %= Mod1;
					}
				}
			}
		}
		Loop(i, 0, 101)
			Loop(j, 0, 101)
				h[i][j] = matric[i][j];
		Loop(i, 0, 101)
		{
			Loop(j, 0, 101)
			{
				matric[i][j] = 0;
				Loop(k, 0, 101)
				{
					matric[i][j] += (h[i][k] * h[k][j]) % Mod1;
					matric[i][j] %= Mod1;
				}
			}
		}
	}
}

int main()
{
	FAST;
	cin >> n >> x;
	Loop(i, 0, n)
		cin >> d[i];
	dp[0] = 1;
	dp[100] = 1;
	Loop(i, 1, 100)
	{
		Loop(j, 0, n)
		{
			if (d[j] <= i)
				dp[i] += dp[i - d[j]];
		}
		dp[100] += dp[i];
		dp[i] %= Mod1;
	}
	d[100] %= Mod1;
	if (x < 100)
	{
		ll ans = 0;
		Loop(i, 0, x + 1)
			ans += dp[i];
		cout << (ans % Mod1);
		return 0;
	}
	Loop(i, 0, 99)
		matric[i + 1][i] = 1;
	Loop(i, 0, n)
	{
		matric[100 - d[i]][99]++;
		matric[100 - d[i]][100]++;
	}
	matric[100][100] = 1;
	x -= 99;
	my_pow();
	ll ans[101] = {};
	Loop(j, 0, 101)
	{
		Loop(k, 0, 101)
		{
			ans[j] += (dp[k] * ansmat[k][j]) % Mod1;
			ans[j] %= Mod1;
		}
	}
	cout << ans[100];
}