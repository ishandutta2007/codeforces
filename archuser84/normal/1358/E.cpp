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

const int N = 300010;
ll a[N];
ll p[N];
ll n, x;

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, (n + 1) / 2)
		cin >> a[i];
	cin >> x;
	reverse(a, a + (n + 1) / 2);
	p[0] = 0;
	Loop(i, 0, (n + 1) / 2)
		p[i + 1] = p[i] + a[i];
	if (x >= 0)
	{
		if (p[(n + 1) / 2] + x * (n / 2) > 0)
			Kill(n)
		else
			Kill(-1);
	}
	Loop(i, 0, (n + 3) / 2)
		p[i] -= i * x;
	reverse(p, p + (n + 3) / 2);
	ll miin = 1LL << 62;
	Loop(i, 0, (n + 3) / 2)
	{
		miin = min(miin, p[i]);
		if (miin + x * (n - i) > 0)
			Kill(n - i);
	}
	Kill(-1);
}