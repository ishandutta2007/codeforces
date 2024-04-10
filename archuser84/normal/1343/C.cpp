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

template<typename T>
int sign(T x)
{
	return x / abs(x);
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		ll s = 0;
		ll h;
		int q;
		cin >> q; q--;
		cin >> h;
		while (q--)
		{
			ll x;
			cin >> x;
			if (sign(x) != sign(h))
			{
				s += h;
				h = x;
			}
			else
				h = max(h, x);
		}
		cout << s + h << '\n';
	}
}