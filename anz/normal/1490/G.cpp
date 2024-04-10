#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;

int n, m;
ll a[200001];
ll psum[200001];

ll pmx[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;

		ll mx = -1e18;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			psum[i] = psum[i - 1] + a[i];

			pmx[i] = max(pmx[i - 1], psum[i]);
			mx = max(mx, psum[i]);
		}

		ll asum = psum[n];

		while (m--)
		{
			ll x; cin >> x;
			int idx = lower_bound(pmx + 1, pmx + n + 1, x) - pmx;

			if (idx <= n)
			{
				cout << idx - 1 << ' ';
				continue;
			}

			if (asum <= 0)
			{
				cout << "-1 ";
				continue;
			}

			ll rq = (x - mx - 1) / asum + 1;

			x -= rq * asum;

			idx = lower_bound(pmx + 1, pmx + n + 1, x) - pmx;
			cout << rq * n + idx - 1 << ' ';
		}

		cout << '\n';
	}
}