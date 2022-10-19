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
		const int n = 3;
		__int64 c[n];
		__int64 max = 0;
		for (LoopN)
		{
			cin >> c[i];
			if (c[i] > max)
				max = c[i];
		}
		if (c[0] + c[1] + c[2] - max >= max - 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}