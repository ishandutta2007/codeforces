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
	int n;
	cin >> n;
	double ans = 0;
	Loop(i, 1, n + 1)
	{
		ans += 1.0 / i;
	}
	printf("%f\n", ans);
}