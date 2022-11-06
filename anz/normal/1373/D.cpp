#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll sum[2] = { 0,0 };

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum[i % 2] += a[i];
		}

		ll ans = sum[0];

		ll msum = 0;
		ll csum = 0;
		for (int i = 0; i + 1 < n; i += 2)
		{
			csum += a[i + 1] - a[i];
			msum = max(msum, csum);

			if (csum < 0) csum = 0;
		}

		csum = 0;
		for (int i = 1; i + 1 < n; i += 2)
		{
			csum += a[i] - a[i + 1];
			msum = max(msum, csum);

			if (csum < 0) csum = 0;
		}

		ans += msum;

		cout << ans << '\n';
	}
}