#include <iostream>
#include <string>
#include <math.h>
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

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		ll N, n, g, b;
		cin >> N >> g >> b;
		n = N;
		//ll B = n / 2;

		n = (n + 1) / 2;
		/*ll ans = n / g * (g + b);
		if (ans / (g + b) * b < n / 2)
			ans += g + ans / (g + b) * b - n / 2;
		else
		{
			ans += n % g;
			if (n % g == 0)
			{
				ans -= b;
				if (ans / (g + b) * b < n / 2)
					ans += ans / (g + b) * b - n / 2;
			}
		}

		ll ans2 = N / g * (g + b);
		ans2 += N % g;
		if (N % g == 0)
		{
			ans2 -= b;
		}*/
		
		ll ans = n / g * (g + b);
		ans += n % g;
		if (n % g == 0)
		{
			ans -= b;
		}

		//ans = min(ans, ans2);
		ans = max(ans, N);

		cout << ans << endl;
	}
}