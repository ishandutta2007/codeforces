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

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int n;
		cin >> n;
		int a[200000];
		int ans = 0;
		cin >> a[0];
		for (int i = 1; i<n;++i)
		{
			cin >> a[i];
			int h = a[i] - a[i - 1];
			if (ans == 0 && (h >= 2 || h <= -2))
				ans = i;
		}
		if (ans == 0)
			cout << "NO\n";
		else
			cout << "YES\n" << ans << ' ' << ans + 1 << '\n';
	}
}