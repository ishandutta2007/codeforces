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
using namespace std;

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		ll h, c, t;
		cin >> h >> c >> t;
		if (2*t <= h + c)
		{
			cout << "2\n";
			continue;
		}
		ll x = (t - h) / (h + c - 2 * t);
		ll a = (2 * x + 3) * (((x + 1) * h + x * c) - (2 * x + 1) * t);
		ll b = (2 * x + 1) * (((x + 2) * h + (x + 1) * c) - (2 * x + 3) * t);
		if (abs(a) <= abs(b))
			cout << 2 * x + 1 << '\n';
		else
			cout << 2 * x + 3 << '\n';
	}
}