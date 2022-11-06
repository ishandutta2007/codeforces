#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

ll mpow(ll a, ll n)
{
	if (n == 0) return 1;
	ll res = mpow(a, n / 2);
	res = res * res % MOD;
	if (n % 2) res = res * a % MOD;
	return res;
}

int n;
ll a[501];

ll cidx = 0;
ll dp[501][501];
ll solve(int idx, int cnt)
{
	if (idx >= n) return 1;

	ll& ret = dp[idx][cnt];
	if (ret != -1) return ret;

	ret = 0;

	if (cidx != idx)
	{
		ll res = solve(idx + 1, cnt);
		ret = (ret + res) % MOD;
	}

	if (a[idx] == 0)
	{
		if (idx < cidx
			|| idx > cidx && cnt > 1)
		{
			ll res = solve(idx + 1, max(0, cnt - 1));
			ret = (ret + res) % MOD;
		}
	}
	else
	{
		if (a[idx] < a[cidx] ||
			a[idx] == a[cidx] && idx <= cidx)
		{
			ll res = solve(idx + 1, cnt + 1);
			ret = (ret + res) % MOD;
		}

		if (a[idx] > a[cidx] ||
			a[idx] == a[cidx] && idx > cidx)
		{
			ll res = solve(idx + 1, cnt);
			ret = (ret + res) % MOD;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if (c == '+')
		{
			int x; cin >> x;
			a[i] = x;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) continue;
		cidx = i;

		memset(dp, -1, sizeof dp);

		ll res = solve(0, 0);

		res = res * a[i] % MOD;
		ans = (ans + res) % MOD;
	}

	cout << ans;
}