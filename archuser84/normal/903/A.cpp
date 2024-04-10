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

const int r[7] = { 0,5,3,1,6,4,2 };

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int x;
		cin >> x;
		if (r[x % 7] * 3 <= x)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}