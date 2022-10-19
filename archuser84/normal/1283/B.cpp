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
		int n, k;
		cin >> n >> k;
		int ans = n - max(0, n % k - (k / 2));
		cout << ans << '\n';
	}
}