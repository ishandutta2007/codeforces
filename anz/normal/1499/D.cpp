#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ett[20000001];
vector <ll> p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i <= 20000000; i++)
	{
		if (!ett[i])
		{
			ett[i] = 1;
			p.push_back(i);
			for (int j = i + i; j <= 20000000; j += i) ett[j]++;
		}
	}

	int t; cin >> t;
	while (t--)
	{
		ll c, d, x; cin >> c >> d >> x;

		ll ans = 0;
		vector <ll> div;

		for (ll i = 1; i * i <= x; i++)
		{
			if (x % i == 0)
			{
				div.push_back(i);
				if (i * i != x) div.push_back(x / i);
			}
		}

		for (ll y : div)
		{
			if ((d + y) % c) continue;
			ll k = (d + y) / c;

			ans += 1ll << ett[k];
		}

		cout << ans << '\n';
	}
}