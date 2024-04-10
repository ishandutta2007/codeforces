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

const int N = 250;

ll pas[N + 1][N + 1];
void pasPre()
{
	pas[0][0] = 1;
	Loop(i, 1, N + 1)
	{
		pas[i][0] = 1;
		Loop(j, 1, i)
			pas[i][j] = (pas[i - 1][j] + pas[i - 1][j - 1]) % Mod1;
		pas[i][i] = 1;
	}
}
ll C(int n, int r)
{
	return pas[n][r];
}

ll np[N * N + 1];
ll pp[N * N + 1];
void powPre(ll k)
{
	np[0] = 1;
	pp[0] = 1;
	Loop(i, 1, N * N + 1)
	{
		np[i] = (np[i - 1] * (k - 1)) % Mod1;
		pp[i] = (pp[i - 1] * k) % Mod1;
	}
}

int main()
{
	FAST;
	int n, k;
	cin >> n >> k;
	ll ans[N][N];
	Loop(i, 0, n)
		ans[0][i] = 1;
	pasPre();
	powPre(k);
	Loop(i, 1, n)
	{
		ans[i][0] = 1;
		Loop(j, 1, n)
		{
			ans[i][j] = (ans[i][j - 1] * (pp[i + 1] - np[i + 1])) % Mod1;
			if (ans[i][j] < 0)
				ans[i][j] += Mod1;
			Loop(x, 1, i + 1)
				ans[i][j] = (ans[i][j] + (ans[i - x][j - 1] * C(i + 1, x) % Mod1) * (np[j * x] * pp[i + 1 - x] % Mod1)) % Mod1;
		}
	}
	cout << ans[n-1][n-1] << '\n';
}