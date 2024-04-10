#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const ll N = 1e18;
ll n;
int lgN;
ll k;

int lg(ll x)
{
	int ans = 0;
	while (x > 0)
	{
		x /= 2;
		ans++;
	}
	return ans;
}

ll getPre(ll x)
{
	int diff = lgN - lg(x);
	ll l = n >> diff;
	if (x < l)
		return (1LL << (diff + 1)) - 1;
	else if (x == l)
		return (1LL << diff) + n - ((n >> diff) << diff);
	else
		return (1LL << diff) - 1;
}

ll bin()
{
	ll l = 1;
	ll r = n >> 1;
	while (r > l)
	{
		ll m = (l + r + 1) / 2;
		if (getPre(m) - 1 >= k)
			l = m;
		else
			r = m - 1;
	}
	return l << 1;
}

int main()
{
	cin >> n >> k;
	lgN = lg(n);
	if (n == k)
		cout << 1;
	else
	{
		ll ans = bin();
		if (getPre(ans + 1) >= k)
			cout << ans + 1;
		else
			cout << ans;
	}
}