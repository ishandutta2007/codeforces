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

int cnt[20] = {};
int Cnt = 0;

int main()
{
	FAST;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		for (int i = 0; x > 0; i++, x >>= 1)
		{
			cnt[i] += x & 1;
			Cnt += x & 1;
		}
	}
	ll ans = 0;
	while (Cnt > 0)
	{
		ll x = 0;
		Loop(i, 0, 20)
		{
			x += (bool)cnt[i] * (1 << i);
			Cnt -= (bool)cnt[i];
			cnt[i] -= (bool)cnt[i];
		}
		ans += x * x;
	}
	cout << ans;
}