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

int main()
{
	FAST;
	cout << setprecision(9) << fixed;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		n = 2 * n;
		double x = 2 * M_PI / n;
		double ans = 0;
		Loop(i, 1, n / 4)
			ans += cos(i * x);
		ans = 2 * ans + 1;
		cout << ans << '\n';
	}
}