#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 200010;

ll Solve(ll d, ll x)
{
	d %= x; if (d < 0) d += x;
	return x / gcd(x, d);
}

int main()
{
	FAST;
	ll k, n;
	cin >> n >> k;
	ll a, b;
	cin >> a >> b;
	ll miin = n * k + 1, maax = 0;
	Loop(i, 0, n)
	{
		ll x = Solve(i * k + b - a, n * k);
		miin = min(miin, x);
		maax = max(maax, x);
		x = Solve(i * k - b - a, n * k);
		miin = min(miin, x);
		maax = max(maax, x);
	}
	cout << miin << ' ' << maax;
}