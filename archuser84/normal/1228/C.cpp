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

ll n;
ll Ans = 1;

ll my_pow(ll a, ll b)
{
	ll ans = 1;
	ll k = a;
	while (b > 0)
	{
		if (b & 1)
			ans = (ans * k) % Mod1;
		b >>= 1;
		k = (k * k) % Mod1;
	}
	return ans;
}

void Solve(int d)
{
	__int128 x = d;
	while (x <= n)
	{
		Ans = (Ans * my_pow(d, n / x)) % Mod1;
		x *= d;
	}
}

int main()
{
	FAST;
	int x;
	cin >> x >> n;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			Solve(i);
			do
			{
				x /= i;
			} while (x % i == 0);
		}
	}
	if (x > 1)
		Solve(x);
	cout << Ans;
}