#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		switch (n % 3)
		{
		case 0: cout << a << '\n'; break;
		case 1: cout << b << '\n'; break;
		case 2: cout << (a ^ b) << '\n'; break;
		}
	}
}