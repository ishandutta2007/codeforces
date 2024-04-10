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

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

int main()
{
	int n;
	cin >> n;
	ll N = 0, D = 1;
	Loop(i, 0, n)
	{
		int p;
		cin >> p;
		ll n = 100, d = p;
		N = (N * n) % Mod2;
		D = (D * d) % Mod2;
		
		N = ((N * d) + (n * D)) % Mod2;
		D = (D * d) % Mod2;
	}

	cout << modDivide(N, D, Mod2);
}