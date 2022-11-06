#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll cnt[20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll a; cin >> a;
		for (int j = 0; j < 20; j++)
		{
			if (a & (1ll << j)) cnt[j]++;
		}
	}

	ll ans = 0;
	while (true)
	{
		ll mx = 987654321;

		ll res = 0;
		for (int i = 0; i < 20; i++)
		{
			if (cnt[i] == 0) continue;
			res |= (1ll << i);
			mx = min(mx, cnt[i]);
		}

		ans += mx * res * res;
		for (int i = 0; i < 20; i++)
		{
			if (cnt[i] == 0) continue;
			cnt[i] -= mx;
		}

		if (res == 0) break;
	}

	cout << ans;
}