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
ll n, k;
ll l1, r1;
ll l2, r2;

ll solve1()
{
	ll l = max(l1, l2);
	ll r = min(r1, r2);
	ll cnt = n * (r - l);
	if (cnt >= k)
		return 0;
	l = min(l1, l2);
	r = max(r1, r2);
	ll cnt2 = n * (r - l);
	if (k <= cnt2)
		return k - cnt;
	ll ans = cnt2 - cnt;
	k -= cnt2;
	return ans + 2 * k;
}

ll solve2()
{
	ll l = max(l1, l2);
	ll r = min(r1, r2);
	ll ans = l - r;
	l = min(l1, l2);
	r = max(r1, r2);
	if (r - l >= k)
		return ans + k;
	ans += r - l;
	k -= r - l;
	if (n > 1)
	{
		n--;
		ll savk = k;
		ll x = solve2();
		return min(ans + x, ans + 2 * savk);
	}
	return ans + 2 * k;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> l1 >> r1;
		cin >> l2 >> r2;
		ll l = max(l1, l2);
		ll r = min(r1, r2);
		if (r - l >= 0)
			cout << solve1() << '\n';
		else
			cout << solve2() << '\n';
	}

}