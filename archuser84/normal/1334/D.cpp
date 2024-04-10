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
ll l, r;

void Solve()
{
	ll u = 1;
	while (2LL * (n - u) <= l)
	{
		l -= 2LL * (n - u);
		r -= 2LL * (n - u);
		u++;
	}
	ll a = 0, b = 0;
	for (ll i = 0; i < r + 1; i += 2)
	{
		if (1 + u + i / 2 + b > n)
		{
			a++;
			b = -(1 + u + i / 2) + u + a + 1;
		}
		if (i == r)
		{
			cout << u + a << ' ';
		}
		else if (i >= l)
		{
			cout << u + a << ' ' << 1 + u + i / 2 + b << ' ';
		}
		else if (i + 1 >= l)
		{
			cout << 1 + u + i / 2 + b << ' ';
		}
	}
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> l >> r;
		l--; r--;
		if (r == n * (n - 1))
		{
			r--;
			if(l <= r)
				Solve();
			cout << "1\n";
		}
		else
		{
			Solve();
			cout << "\n";
		}
	}
}