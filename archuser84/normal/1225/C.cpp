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

int count(ll x)
{
	ll n = x;
	int ans = 0;
	while (n > 0)
	{
		ans += n & 1;
		n >>= 1;
	}
	return ans;
}

int main()
{
	ll n, p;
	cin >> n >> p;
	int ans = -1;
	for (int i = 1; n >= 0; i++)
	{
		n -= p;
		if (count(n) <= i && i <= n)
		{
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}