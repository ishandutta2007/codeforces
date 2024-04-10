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
		ll x, y; cin >> x >> y;
		ll a, b; cin >> a >> b;

		if (x > y) swap(x, y);
		ll m = min(x, y);

		if (a * 2 > b)
		{
			cout << m * b + (y - m) * a << '\n';
		}
		else
		{
			cout << a * (x + y) << '\n';
		}
	}
}