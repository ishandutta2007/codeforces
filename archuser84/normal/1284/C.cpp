#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll fac[300001];

int main()
{
	ll n, m;
	cin >> n >> m;
	fac[0] = 1;
	for (ll i = 1; i <= n; ++i)
	{
		fac[i] = (fac[i - 1] * i) % m;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; ++i)
	{
		ll x = (fac[i] * fac[n - i]) % m;
		ll y = ((n - i + 1) * (n - i + 1)) % m;
		ll z = (x * y) % m;
		ans = (ans + z) % m;
	}
	cout << ans << '\n';
}