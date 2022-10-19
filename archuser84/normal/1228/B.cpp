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

int x[1000][1000] = {};
int r[1000], c[1000];

int main()
{
	FAST;
	int h, w;
	cin >> h >> w;
	ll ans = 1;
	Loop(i, 0, h)
	{
		cin >> r[i];
		Loop(j, 0, r[i])
			x[i][j] = 2;
		x[i][r[i]] = 1;
	}
	Loop(i, 0, w)
	{
		cin >> c[i];
		Loop(j, 0, c[i])
		{
			if (x[j][i] == 1)
				ans = 0;
			x[j][i] = 2;
		}
		if (x[c[i]][i] == 2)
			ans = 0;
		x[c[i]][i] = 1;
	}
	Loop(i, 0, h)
	{
		Loop(j, 0, w)
		{
			if (x[i][j] == 0)
				ans = (ans << 1) % Mod1;
		}
	}
	cout << ans;
}