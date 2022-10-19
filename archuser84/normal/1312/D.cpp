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
#define YN(flag) cout << (flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200010;
ll fac[N + 1];
ll pow2[N + 1];
ll n, m;

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

void facCalc()
{
	fac[0] = 1;
	Loop(i, 1, N + 1)
		fac[i] = (fac[i - 1] * (ll)i) % Mod2;
}

void pow2Calc()
{
	pow2[0] = 1;
	Loop(i, 1, N + 1)
		pow2[i] = (pow2[i - 1] << 1) % Mod2;
}

ll C(ll x, ll y)
{
	if (y > x || y < 0)
		return 0;
	ll a = fac[x];
	ll b = (fac[y] * fac[x - y]) % Mod2;
	return modDivide(a, b, Mod2);
}

int main()
{
	FAST;
	cin >> n >> m;
	facCalc();
	pow2Calc();
	ll ans = 0;
	for(ll MAX = 1; MAX <= m; MAX++)
	{
		ll x = C(MAX - 1, n - 2);
		x = (x * (n - 2)) % Mod2;
		x = (x * pow2[n - 3]) % Mod2;
		ans = (ans + x) % Mod2;
	}
	cout << ans << '\n';
}