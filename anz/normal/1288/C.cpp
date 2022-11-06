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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;
ll n, m;
ll dp[1001][21]; //, 
ll solve(int mn, int len)
{
	ll& ret = dp[mn][len];
	if (ret != -1) return ret;

	if (len == 1) return ret = 1;

	ret = 0;
	for (ll i = 1; i <= mn; i++)
	{
		ret += solve(i, len - 1);
		ret %= MOD;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	memset(dp, -1, sizeof dp);

	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		ans += solve(i, m * 2);
		ans %= MOD;
	}

	cout << ans;
}