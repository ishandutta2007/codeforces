#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int n, x;
		cin >> n >> x;
		char a[100002];
		cin >> a;
		int k = 0;
		Loop(i, 0, n)
		{
			k += a[i] - '0';
		}
		k = n - 2 * k;
		int ans = 0;
		int c = 0;
		if (k != 0)
		{
			Loop(i, 0, n)
			{
				int y = x - c;
				if (y % k == 0)
					ans += y / k >= 0;

				c += 1 - 2 * (a[i] - '0');
			}
		}
		else
		{
			Loop(i, 0, n)
			{
				if (c == x)
				{
					ans = -1;
					break;
				}
				c += 1 - 2 * (a[i] - '0');
			}
		}
		cout << ans << '\n';
	}
}