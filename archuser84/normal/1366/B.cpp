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
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, m;
		cin >> n >> x >> m;
		int l, r;
		l = r = x;
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			if (a <= r && b >= l)
			{
				l = min(a, l);
				r = max(b, r);
			}
		}
		cout << r - l + 1 << '\n';
	}
}