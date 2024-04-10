#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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

const int N = 2000010;
ll fac[N];
int n, k;

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}
ll C(ll n, ll r)
{
	ll a = fac[n];
	ll b = (fac[r] * fac[n - r]) % Mod2;
	return modDivide(a, b, Mod2);
}
void facpre()
{
	fac[0] = 1;
	Loop(i, 1, N)
	{
		fac[i] = (fac[i - 1] * i) % Mod2;
	}
}
int npar(int x)
{
	return x & 1 ? -1 : 1;
}
ll my_pow(ll x, ll e)
{
	ll ans = 1;
	ll h = x;
	while (e > 0)
	{
		if (e & 1)
			ans = (ans * h) % Mod2;
		e >>= 1;
		h = (h * h) % Mod2;
	}
	return ans;
}

ll Solve()
{
	ll ans = 0;
	Loop(i, k, n)
		ans += (npar(i - k) * my_pow(n - i, n) * C(n - k, i - k)) % Mod2;
	ans = ((ans % Mod2) * C(n, n - k)) % Mod2;
	if (ans < 0)
		ans += Mod2;
	return ans;
}

int main()
{
	cin >> n >> k;
	facpre();
	if (k >= n)
	{
		cout << "0";
		return 0;
	}
	if (k == 0)
	{
		cout << fac[n];
		return 0;
	}
	cout << (2 * Solve()) % Mod2;
}