#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;
ll n, m;

ll mpow(ll a, ll n)
{
	if (n < 0) return 0;
	if (n == 0) return 1;
	ll t = mpow(a, n / 2);
	t = t * t % MOD;
	if (n % 2) t = t * a % MOD;
	return t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	ll ans = n - 2;

	for (ll i = 1; i <= m; i++)
	{
		ans *= i;
		ans %= MOD;
	}

	for (ll i = 1; i <= n - 1; i++)
	{
		ans *= mpow(i, MOD - 2);
		ans %= MOD;
	}

	for (ll i = 1; i <= m - (n - 1); i++)
	{
		ans *= mpow(i, MOD - 2);
		ans %= MOD;
	}

	ans *= mpow(2, n - 3);
	ans %= MOD;

	cout << ans;
}