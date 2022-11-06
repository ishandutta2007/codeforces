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

int n;
ll a[100001][11]; //  
int a_len[100001];

int len_cnt[11];
ll len_sum[11][11]; // i  j   

int numLen(ll a)
{
	int res = 0;
	while (a)
		res++, a /= 10;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll t; cin >> t;

		int len = numLen(t);
		a_len[i] = len;
		len_cnt[len]++;

		for (int j = 0; j < 11; j++)
		{
			int cnt = j;
			ll tt = t;
			ll mul = 1;

			ll res = 0;

			while (tt)
			{
				res += tt % 10 * mul;
				res %= MOD;

				tt /= 10;
				if (cnt) mul *= 100, cnt--;
				else mul *= 10;
				mul %= MOD;
			}

			a[i][j] = res;

			len_sum[len][j] += res;
			len_sum[len][j] %= MOD;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l = a_len[i];

		for (int j = 1; j < 11; j++)
		{
			ll tmpSum = a[i][j] * len_cnt[j] % MOD;
			ll tmpSum2 = len_sum[j][l-1] * 10 % MOD;
			ans += (tmpSum + tmpSum2) % MOD;
			ans %= MOD;
		}
	}

	cout << ans;
}