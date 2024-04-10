#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define Loop(x, b) for(int x = 0; x < b; ++x)
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

const int N = 50;
bool g[N][N];
int n, m;

int cnt;
int Do(int k)
{
	cnt = 0;
	int ans = 0;
	Loop(i, k + 1)
	{
		if (i < n && k - i < m)
		{
			ans += g[i][k - i];
			cnt++;
		}
		if (n - i > 0 && m - (k - i) > 0)
		{
			ans += g[n - i - 1][m - (k - i) - 1];
			cnt++;
		}
	}
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		Loop(i, n)
			Loop(j, m)
				cin >> g[i][j];
		int ans = 0;
		Loop(i,(n+m-1)/2)
		{
			int x = Do(i);
			x = min(x, cnt - x);
			ans += x;
		}
		cout << ans << '\n';
	}
}