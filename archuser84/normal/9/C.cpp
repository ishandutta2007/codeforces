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

__int64 pow(__int64 x, __int64 p)
{
	if (p == 0)
		return 1;
	return x * pow(x, p - 1);
}

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int m = log10(n);
	bool f = 0;
	for (int i = m; i >= 0; --i)
	{
		ans *= 2;
		int x = (int)(n / pow(10, i)) % 10;
		if (x > 1)
			f = true;
		ans += x || f;
	}
	cout << ans << '\n';
}