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
		int ans = 0;
		ll sum = 0;
		ll pro = 1;
		int n;
		cin >> n;
		Loop(i, 0, n)
		{
			int x;
			cin >> x;
			if (!x)
			{
				x++;
				ans++;
			}
			sum += x;
			pro *= x;
		}
		cout << ans + !sum << '\n';
	}
}