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
		int n;
		cin >> n;
		if (n % 2 == 1)
		{
			cout << 7;
			n -= 3;
		}
		while (n > 0)
		{
			cout << 1;
			n -= 2;
		}
		cout << '\n';
	}
}