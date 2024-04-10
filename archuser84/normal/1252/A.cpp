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

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int n, d;
		cin >> n >> d;
		int x = sqrt(d);
		bool ans = false;
		Loop(i, 0, x + 4)
		{
			if (i + (d + i) / (i + 1) <= n)
			{
				ans = true;
				break;
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}