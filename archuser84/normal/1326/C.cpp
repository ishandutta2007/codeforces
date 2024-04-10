#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) flag? "YES\n": "NO\n"
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 300000;

int main()
{
	FAST;
	ll a[N];
	ll n, k;
	cin >> n >> k;
	int min = -1;
	int max;
	Loop(i, 0, n)
	{
		cin >> a[i];
		if (a[i] > n - k)
		{
			max = i;
			if (min == -1)
				min = i;
		}
	}
	ll ans = 1;
	ll h = 1;
	Loop(i, min, max + 1)
	{
		if (a[i] > n - k)
		{
			ans = (ans * h) % Mod2;
			h = 1;
		}
		else
			h++;
	}
	cout << (n * (n + 1LL) - (n - k) * (n - k + 1LL)) / 2LL << ' ' << ans;
}