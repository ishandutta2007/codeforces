#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		bool ans = 1;
		Loop(i, 0, n)
		{
			Loop(j, 0, m)
			{
				int x, k = 4;
				cin >> x;
				if (i % (n - 1) == 0)
					k--;
				if (j % (m - 1) == 0)
					k--;
				if (x > k)
					ans = 0;
			}
		}
		if (!ans)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		Loop(i, 0, n)
		{
			Loop(j, 0, m)
			{
				int k = 4;
				if (i % (n - 1) == 0)
					k--;
				if (j % (m - 1) == 0)
					k--;
				cout << k << '\n';
			}
		}
	}
}