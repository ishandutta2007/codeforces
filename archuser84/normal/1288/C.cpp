#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll x[1120][1120];

ll comb(int R, int N)
{
	return x[N][R];
}

int main()
{
	Loop(i, 0, 1120)
		Loop(j, 0, i + 1)
			if (j == 0 || j == i)
				x[i][j] = 1;
			else
				x[i][j] = (x[i - 1][j - 1] + x[i - 1][j]) % Mod1;
	ll n, m;
	cin >> n >> m;
	cout << comb(2 * m, 2 * m + n - 1) << '\n';
}