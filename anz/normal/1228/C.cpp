#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1000000007;
vector <ll> d;

ll myPow(ll a, ll n) // a^n;
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n % 2 == 0)
	{
		ll t = myPow(a, n / 2);
		return t * t % MOD;
	}

	ll t = myPow(a, n - 1);
	return t * a % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll x, n; cin >> x >> n;
	ll tmpx = x;

	for (ll i = 2; i*i <= x; i++)
	{
		if (tmpx % i == 0)
		{
			d.push_back(i);
			while (tmpx % i == 0) tmpx /= i;
		}
	}

	if (tmpx != 1) d.push_back(tmpx);

	ll ans = 1;

	for (int i = 0; i < d.size(); i++)
	{
		ll cd = d[i];
		ll cm = 0;

		int cnt = 0;

		while (cd <= n)
		{
			cm = (n / cd);
			ans *= myPow(d[i], cm);
			ans %= MOD;

			ll nd = cd * d[i];
			if (nd / d[i] != cd || nd % d[i]) break;

			cd *= d[i];
		}
	}

	cout << ans;
}