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

const ll MOD = 1e9 + 7;
ll mPow(ll n, ll a) // n^a
{
	if (a == 0) return 1;
	if (a == 1) return n;
	if (a % 2 == 0)
	{
		ll t = mPow(n, a / 2);
		return t * t % MOD;
	}
	else
	{
		ll t = mPow(n, a - 1);
		return t * n % MOD;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m; cin >> n >> m;

	ll ans = mPow(2, m);
	ans = (ans + MOD - 1) % MOD;

	ans = mPow(ans, n);
	cout << ans;
}