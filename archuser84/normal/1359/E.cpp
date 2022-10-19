#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int Mod = Mod2;
const int N = 500010;

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

ll fac[N];
ll C(int n, int r)
{
	if (n < 0 || r < 0 || r > n)
		return 0;
	return modDivide(fac[n], fac[r] * fac[n - r] % Mod, Mod);
}

void calcfac()
{
	fac[0] = 1;
	Loop(i, 1, N)
		fac[i] = fac[i - 1] * i % Mod;
}

int main()
{
	FAST;
	int n, k;
	cin >> n >> k;
	calcfac();
	ll ans = 0;
	for(int i=1;k*i<=n;i++)
	{
		ans += C(n / i - 1, k - 1);
		ans %= Mod;
	}
	cout << ans;
}