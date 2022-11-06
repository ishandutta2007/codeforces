#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].second >> a[i].first;

	sort(a, a + n + 1);

	ll ans = 0;
	ll cur = 0;
	int ptr = n;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].first <= cur)
		{
			ans += a[i].second;
			cur += a[i].second;

			continue;
		}

		ll d = a[i].first - cur;

		while (ptr >= i)
		{
			if (a[ptr].second >= d)
			{
				a[ptr].second -= d;
				ans += d * 2;
				cur += d;
				d = 0;
				break;
			}

			d -= a[ptr].second;
			ans += a[ptr].second * 2;
			cur += a[ptr].second;
			a[ptr].second = 0;
			ptr--;
		}

		if (d > 0) break;

		ans += a[i].second;
		cur += a[i].second;
	}

	cout << ans;
}