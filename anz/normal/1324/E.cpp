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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, h, l, r;
ll a[2001];
ll dp[2001][2001];
ll solve(int day, int time)
{
	ll& ret = dp[day][time];
	if (ret != -1) return ret;

	if (day == 0)
	{
		if (time == 0) return ret = 0;

		else return ret = -2;
	}

	ll r1 = solve(day - 1, (time + h - a[day]) % h);
	ll r2 = solve(day - 1, (time + h - (a[day] - 1)) % h);

	if (r1 == -2 && r2 == -2) return ret = -2;

	if (l <= time && time <= r) ret = 1;
	else ret = 0;
	ret += max(r1, r2);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);
	cin >> n >> h >> l >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll ans = 0;
	for (int i = 0; i < h; i++)
	{
		ll res = solve(n, i);
		ans = max(ans, res);
	}

	cout << ans;
}