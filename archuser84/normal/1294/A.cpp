#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int d = a + b + c + n;
		if (d % 3 != 0 || d / 3 < a || d / 3 < b || d / 3 < c)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}