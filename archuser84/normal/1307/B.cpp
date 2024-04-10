#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
		int n;
		ll x;
		cin >> n >> x;
		ll hop = 0;
		ll ans = -1;
		while (n--)
		{
			ll h;
			cin >> h;
			if (h > hop)
				hop = h;
			if (h == x)
				ans = 1;
		}
		if (ans == -1)
		{
			ans = (x + hop - 1) / hop;
			if (x < hop)
				ans = 2;
		}
		cout << ans << '\n';
	}
}