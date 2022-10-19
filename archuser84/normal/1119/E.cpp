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

int main()
{
	ios::sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	ll ans = 0;
	ll tmp = 0;
	while (n--)
	{
		ll x; scanf("%I64d", &x);
		ll t = min(tmp, x / 2);
		ans += t;
		x -= 2 * t; tmp -= t;
		ans += x / 3; x %= 3;
		tmp += x;
	}
	printf("%I64d\n", ans);
}