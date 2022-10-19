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

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int a, b, d;
		cin >> a >> b;
		d = b - a;
		if (d < 0)
			d = -d;
		int ans = 0;
		ans += d / 5;
		d %= 5;
		ans += (d + 1) / 2;
		cout << ans << '\n';
	}
}