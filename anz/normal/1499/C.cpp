#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;

ll n;
ll c[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		ll ans = INF;

		int cnt[2] = { 0,0 };
		ll sum[2] = { 0,0 };
		ll mn[2] = { INF, INF };

		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
			cnt[i % 2]++;
			sum[i % 2] += c[i];
			mn[i % 2] = min(mn[i % 2], c[i]);

			if (i == 1) continue;

			ll res = sum[0] - mn[0] + mn[0] * (n - cnt[0] + 1)
				+ sum[1] - mn[1] + mn[1] * (n - cnt[1] + 1);

			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}