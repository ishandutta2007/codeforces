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

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		ll n, s;
		ll a[100000];
		cin >> n >> s;
		int max = 0;
		ll cur = 0;
		int ans = 0;
		bool end = 0;
		for (LoopN)
		{
			cin >> a[i];
			if (!end)
			{
				if (a[i] > a[max])
					max = i;
				cur += a[i];
				if (cur >= s)
				{
					++i;
					if (i < n)
					{
						cin >> a[i];
						if (a[i] < a[max])
							ans = max + 1;
					}
					end = true;
				}
			}
		}
		cout << ans << '\n';
	}
}