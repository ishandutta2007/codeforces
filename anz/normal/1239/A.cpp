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

ll dp[100001][2]; // 0:prevSame, 1:prevNotSame
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b; cin >> a >> b;
	dp[1][1] = 1;
	for (ll i = 2; i <= max(a, b); i++)
	{
		dp[i][0] = dp[i - 1][1] % MOD;
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
	}

	ll ans = 0;
	ans += ((dp[a][0] + dp[a][1]) % MOD * 2) % MOD;
	ans %= MOD;
	ans += ((dp[b][0] + dp[b][1]) % MOD * 2) % MOD;
	ans %= MOD;
	cout << (ans + MOD - 2) % MOD;
}