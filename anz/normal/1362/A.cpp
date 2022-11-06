#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll a, b; cin >> a >> b;
		if (a > b) swap(a, b);

		if (b % a)
		{
			cout << "-1\n";
			continue;
		}

		ll res = b / a;
		if (res & (res - 1))
		{
			cout << "-1\n";
			continue;
		}

		for (int i = 0; i <= 60; i++)
		{
			if (res == (1ll << i))
			{
				cout << (i + 2) / 3 << '\n';
				break;
			}
		}
	}
}