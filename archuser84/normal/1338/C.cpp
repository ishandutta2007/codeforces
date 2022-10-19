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

ll Solve(ll n)
{
	if (n < 3)
		return n + 1;
	ll k = 1;
	while (3 * k <= n)
	{
		n -= 3 * k;
		k <<= 2;
	}
	if (n % 3 == 0)
		return n / 3 + k;
	else
	{
		ll N = n;
		n /= 3;
		ll m = 0;
		ll k2 = 1;
		while (n > 0)
		{
			switch (n & 3)
			{
			case 0: m += k2 * 0; break;
			case 1: m += k2 * 2; break;
			case 2: m += k2 * 3; break;
			case 3: m += k2 * 1; break;
			}
			n >>= 2;
			k2 <<= 2;
		}
		if (N % 3 == 1)
			return m + (k << 1);
		else
			return (N / 3 + k) ^ (m + (k << 1));
	}
	return -1;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		n--;
		cout << Solve(n) << '\n';
	}
}