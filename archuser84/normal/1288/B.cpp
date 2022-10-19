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

ll my_pow(ll x,int p)
{
	if (p == 0)
		return 1;
	return x * my_pow(x, p - 1);
}

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		ll A, B;
		ll ans = 0;
		cin >> A >> B;
		Loop(i, 0, 13)
		{
			if (my_pow(10, i + 1) - 1 <= B)
			{
				++ans;
			}
			else
				break;
		}
		cout << A * ans << '\n';
	}
}