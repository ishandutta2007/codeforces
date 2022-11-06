#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll c[100001];
ll a[100001];
ll b[100001];

ll res[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> c[i];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			if (a[i] > b[i]) swap(a[i], b[i]);
		}

		a[n] = 1, b[n] = c[n - 1];

		ll ans = 0;

		res[0] = -1e12;
		for (int i = 1; i < n; i++)
		{
			ll tmp = a[i + 1] - 1 + c[i] - b[i + 1] + 2;
			if (a[i] != b[i]) tmp += max(b[i] - a[i], res[i - 1]);

			res[i] = tmp;
			ans = max(ans, res[i] + b[i + 1] - a[i + 1]);
		}

		cout << ans << '\n';
	}
}