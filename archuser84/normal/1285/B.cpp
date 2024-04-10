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
		int n;
		int a[200000];
		cin >> n;
		for (LoopN)
			cin >> a[i];
		ll ans1 = a[0], ans2 = a[n - 1];
		for (int i = 1; ans1 > 0 && i < n - 1; ++i)
			ans1 += a[i];
		if(ans1 > 0)
			for (int i = n - 2; ans2 > 0 && i > 0; --i)
				ans2 += a[i];
		if (ans1 <= 0 || ans2 <= 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}