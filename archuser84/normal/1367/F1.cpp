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

const int N = 3010;
int dp[N];
pii a[N];
int n;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(dp, 0, 4 * n);
		Loop(i, 0, n)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		Loop(i, 0, n)
			a[i].first = i;
		sort(a, a + n, [](pii a, pii b) {return a.second < b.second; });
		int ans = 1;
		Loop(i, 0, n)
		{
			if (a[i].first == 0)
				dp[0]++;
			else
			{
				dp[a[i].first] = dp[a[i].first - 1] + 1;
				ans = max(ans, dp[a[i].first]);
			}
		}
		printf("%i\n", n - ans);
	}
}