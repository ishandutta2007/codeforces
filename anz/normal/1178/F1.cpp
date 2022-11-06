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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const ll MOD = 998244353;
ll n, m;
ll c[501];

ll memo[501][501];
ll dp(ll l, ll r)
{
	if (r <= l) return 1;
	ll& ret = memo[l][r];
	if (ret != -1) return ret;

	ll minNum = 987654321;
	int idx = -1;
	for (int i = l; i <= r; i++)
	{
		if (minNum > c[i])
		{
			minNum = c[i];
			idx = i;
		}
	}

	ret = 0;

	ll left = 0, right = 0;

	for (int i = l; i <= idx; i++)
	{
		ll tmp = 1;
		tmp *= dp(l, i - 1);
		tmp %= MOD;
		tmp *= dp(i, idx - 1);
		tmp %= MOD;

		left += tmp;
		left %= MOD;
	}

	for (int j = idx; j <= r; j++)
	{
		ll tmp = 1;
		tmp *= dp(idx + 1, j);
		tmp %= MOD;
		tmp *= dp(j + 1, r);
		tmp %= MOD;

		right += tmp;
		right %= MOD;
	}

	return ret = left * right%MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c[i];
	memset(memo, -1, sizeof memo);
	cout << dp(0, n - 1);
}