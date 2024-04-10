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

ll my_pow(ll x, ll p)
{
	if (p == 0)
		return 1;
	else
		return (x * my_pow(x, p - 1)) % Mod2;
}

int main()
{
	int w, h;
	cin >> w >> h;
	cout << my_pow(2, w + h) << '\n';
}