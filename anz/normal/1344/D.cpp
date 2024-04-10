#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 4e18;
ll n, k;
ll a[100001];
ll ans[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	ll l = -INF, r = INF;
	ll sum = 0;
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;

		sum = 0;
		for (int i = 0; i < n; i++)
		{
			ll tl = 0, tr = a[i] + 1;
			while (tl + 1 < tr)
			{
				ll tm = (tl + tr) / 2;
				ll res = a[i] - 3 * tm * tm + 3 * tm + 1;
				if (res >= m) tl = tm;
				else tr = tm;
			}

			sum += tl;
		}

		if (sum > k) l = m;
		else r = m;
	}

	sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll tl = 0, tr = a[i] + 1;
		while (tl + 1 < tr)
		{
			ll tm = (tl + tr) / 2;
			ll res = a[i] - 3 * tm * tm + 3 * tm + 1;
			if (res >= r) tl = tm;
			else tr = tm;
		}

		ans[i] = tl;
		sum += tl;
	}

	priority_queue <pll> pq;
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == a[i]) continue;
		ll res = a[i] - 3 * (ans[i] + 1) * (ans[i] + 1) + 3 * (ans[i] + 1) + 1;
		pq.push({ res, i });
	}

	for (int i = 0; i < k - sum; i++)
	{
		pll tmp = pq.top(); pq.pop();
		int idx = tmp.second;
		ans[idx]++;

		if (ans[idx] != a[idx])
		{
			ll res = a[idx] - 3 * (ans[idx] + 1) * (ans[idx] + 1) + 3 * (ans[idx] + 1) + 1;
			pq.push({ res, idx });
		}
	}

	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}