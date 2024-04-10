#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

ll modPow(ll x, ll y, ll mod)
{
	ll ans = 1;
	ll h = x;
	for (int i = 0; y > 0; i++)
	{
		if (y & 1)
			ans = (ans * h) % mod;
		y >>= 1;
		h = (h * h) % mod;
	}
	return ans;
}

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

int main()
{
	FAST;
	ll n, m, l, r;
	cin >> n >> m >> l >> r;
	ll e = (((r - (r & 1)) - (l + (l & 1))) >> 1) + 1;
	ll o = r - l + 1 - e;
	ll ans = modPow(o + e, n * m, Mod2);
	if (e != o && !(n & 1 && m & 1))
		if (ans & 1)
			ans = ((ans >> 1) + 1) % Mod2;
		else
			ans = (((Mod2 + ans) >> 1) + 1) % Mod2;
	else if (!(n & 1 && m & 1))
		ans = modDivide(ans, 2, Mod2);
	cout << ans << '\n';
}