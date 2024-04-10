#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ett[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;

		ll ans = n - 1;
		ll a = 1, b = n - 1;

		for (ll i = 2; i * i <= n; i++)
		{
			if (n % i) continue;

			ll ta = n / i, tb = n - ta;
			ll res = ta * tb / gcd(ta, tb);

			if (ans > res)
			{
				ans = res;
				a = ta, b = tb;
			}
		}

		cout << a << ' ' << b << '\n';
	}
}