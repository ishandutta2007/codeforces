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

ll Solve(ll d,ll m)
{
	ll ans = 0;
	ll p = 1;
	ll j = 1;
	while ((p << 1) <= d)
	{
		ans = (ans + j * p) % m;
		j = (j * (p + 1)) % m;
		p <<= 1;
	}
	return (ans + (d - p + 1) * j) % m;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll d, m;
		cin >> d >> m;
		cout << Solve(d, m) << '\n';
	}
}