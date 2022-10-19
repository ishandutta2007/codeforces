#include <iostream>
#include <string.h>
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
		__int64 n;
		cin >> n;
		int ans = 9 * (int)log10(n);
		for (int i = 1; i <= 9; i++)
		{
			__int64 x = pow(10, (int)log10(n) + 1);
			x = (x - 1) / 9;
			x *= i;
			if (x <= n)
				++ans;
			else
				break;
		}
		cout << ans << '\n';
	}
}