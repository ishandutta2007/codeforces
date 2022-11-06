#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		m = 3, k = 2;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		ll ans = 0;
		for (ll i = 0; i < n; i++)
		{
			int ridx = upper_bound(a + i, a + n, a[i] + k) - a;
			if (i + m > ridx) continue;

			ll tmp = ridx - i - 2;
			ll res = tmp * (tmp + 1) / 2;

			ans += res;
		}

		cout << ans << '\n';
	}
}