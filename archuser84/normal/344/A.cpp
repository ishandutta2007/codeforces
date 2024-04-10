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

int my_min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int ans = 0;
	int n;
	cin >> n;
	char last = 0;
	for (LoopN)
	{
		char x[3];
		cin >> x;
		if (x[0] != last)
			ans++;
		last = x[0];
	}
	cout << ans << '\n';
}