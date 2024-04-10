#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 400000;

int main()
{
	FAST;
	ll a[N];
	ll n, m;
	cin >> n >> m;
	Loop(i, 0, n)
		cin >> a[i];
	if (n > m + 2)
		cout << 0;
	else
	{
		ll ans = 1;
		Loop(i, 0, n)
		{
			Loop(j, i + 1, n)
			{
				ans = (ans * abs(a[i] - a[j])) % m;
			}
		}
		cout << ans % m;
	}
}