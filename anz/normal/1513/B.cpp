#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;

int n;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		ll res = a[0];
		ll cnt = 0;
		for (int i = 1; i < n; i++) res &= a[i];
		for (int i = 0; i < n; i++)
		{
			a[i] &= ~res;
			if (a[i] == 0) cnt++;
		}

		if (cnt < 2)
		{
			cout << "0\n";
			continue;
		}

		ll ans = cnt * (cnt - 1) % MOD;
		for (int i = 1; i <= n - 2; i++)
			ans = ans * i % MOD;

		cout << ans << '\n';
	}
}