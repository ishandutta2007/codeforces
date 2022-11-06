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
		if (a == b)
		{
			cout << "0 0\n";
			continue;
		}

		if (a > b) swap(a, b);
		ll d = b - a;

		ll r1 = a - a / d * d;
		ll r2 = a / d * d + d - a;

		cout << d << ' ' << min(r1, r2) << '\n';
	}
}