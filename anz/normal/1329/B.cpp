#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll res[50];
ll ans[50];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll d, m; cin >> d >> m;
		memset(res, 0, sizeof res);
		memset(ans, 0, sizeof ans);

		ll i = 1;
		while (true)
		{
			if ((1ll << i) > d) break;

			res[i - 1] = 1ll << (i - 1);
			i++;
		}

		res[i - 1] = (d - (1ll << (i - 1))) + 1;

		ll sum = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			ans[j] = (ans[j + 1] + 1) * res[j] % m;
			ans[j] += ans[j + 1];
			ans[j] %= m;
		}

		cout << ans[0] << '\n';
	}
}