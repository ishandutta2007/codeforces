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
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if (a > b)
		{
			int h = a;
			a = b;
			b = h;
		}
		int L = max(c - r, a);
		int R = min(c + r, b);
		cout << b - a - max((R - L),0) << '\n';
	}
}