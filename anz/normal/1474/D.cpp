#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;

int n;
ll a[200001];
ll psum[200001];

ll min0[200001];
ll min1[200001];

ll pmin[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			psum[i] = -psum[i - 1] + a[i];

			pmin[i] = min(pmin[i - 1], psum[i]);
		}

		bool ans = true;
		for (int i = 1; i <= n; i++)
		{
			if (psum[i] < 0) ans = false;
		}

		if (psum[n] != 0) ans = false;

		if (ans)
		{
			cout << "YES\n";
			continue;
		}

		ll cmin0 = INF, cmin1 = INF;

		for (int i = n; i >= 1; i--)
		{
			if (i % 2)
				cmin1 = min(cmin1, psum[i]);
			else
				cmin0 = min(cmin0, psum[i]);

			min0[i] = cmin0;
			min1[i] = cmin1;
		}

		for (int i = 1; i < n; i++)
		{
			// swap(a[i], a[i+1])
			if (pmin[i - 1] < 0) continue;

			ll d = 2 * a[i + 1] + -2 * a[i];
			if (i % 2 == 0) d = -d;

			if (min1[i + 1] + d >= 0 && min0[i + 1] - d >= 0 && psum[i] - a[i] + a[i + 1] >= 0)
			{
				if (n % 2 == 1 && psum[n] + d == 0
					|| n % 2 == 0 && psum[n] - d == 0)
				{
					ans = true;
					break;
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}