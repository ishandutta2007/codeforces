#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll pow3[100];

int my_log3(ll x)
{
	int ans = 0;
	while (x >= 3)
	{
		x /= 3;
		++ans;
	}
	return ans;
}

ll db3(ll x, int d)
{
	return (x / pow3[d]) % 3;
}

int main()
{
	pow3[0] = 1;
	for (int i = 1; i < 100; ++i)
		pow3[i] = pow3[i - 1] * 3;
	int t;
	cin >> t;
	for (Loop)
	{
		ll x;
		cin >> x;
		int ones = 0;
		for (int i = my_log3(x); i >= 0; --i)
		{
			int d = db3(x, i);
			if (d == 2)
			{
				x /= pow3[i];
				for (int j = 0; j <= ones; ++j)
					x += pow3[j];
				x *= pow3[i];
				break;
			}
			if (d == 1)
			{
				++ones;
			}
			if (d == 0)
			{
				ones = 0;
			}
		}
		cout << x << '\n';
	}
}