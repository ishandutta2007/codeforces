#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];

ll dp[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			dp[i] = 0;
		}

		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			dp[i] += a[i];
			ans = max(ans, dp[i]);

			if (i + a[i] < n)
			{
				dp[i + a[i]] = max(dp[i + a[i]], dp[i]);
			}
		}

		cout << ans << '\n';
 	}
}