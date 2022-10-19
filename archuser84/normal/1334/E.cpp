#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 300010;
ll D;
ll u, v;
map<ll, map<ll, int>> M;
map<ll, bool> did;

void Do(ll x)
{
	if (did[x])
		return;
	did[x] = true;
	auto* m = &M[x];
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			auto* mk = &(*m)[i];
			while (x % i == 0)
			{
				(*mk)++;
				x /= i;
			}
		}
	}
	if (x > 1)
		(*m)[x]++;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

ll fac[N];

ll Solve(ll x)
{
	ll n = 0, d = 1;
	for (auto p : M[x])
	{
		n += p.second;
		d = d * fac[p.second] % Mod2;
	}
	n = fac[n];
	return modDivide(n, d, Mod2);
}

int main()
{
	fac[0] = 1;
	Loop(i, 1, N)
		fac[i] = fac[i - 1] * i % Mod2;
	FAST;
	cin >> D;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> u >> v;
		ll g = gcd(u, v);
		u /= g; v /= g;
		Do(u); Do(v);
		cout << Solve(u) * Solve(v) % Mod2 << '\n';
	}
}