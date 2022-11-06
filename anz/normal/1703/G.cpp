#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[200001];
ll dp[32][200001];
bool f[32][200001];

ll solve(int h, int idx)
{
	if (idx == n) return 0;
	ll& ret = dp[h][idx];
	if (f[h][idx]) return ret;
	f[h][idx] = true;

	ll cur = a[idx];
	for (int i = 0; i < h && cur; i++) cur /= 2;

	ret = solve(h, idx + 1) + cur - k;

	ll res = solve(min(31, h + 1), idx + 1) + cur / 2;
	ret = max(ret, res);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i <= 31; i++) for (int j = 0; j < n; j++)
			f[i][j] = 0;

		ll ans = solve(0, 0);
		cout << ans << '\n';
	}
}