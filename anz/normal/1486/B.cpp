#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll x[1001], y[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

		if (n % 2)
		{
			cout << "1\n";
			continue;
		}

		sort(x, x + n);
		sort(y, y + n);

		ll dx = x[n / 2] - x[n / 2 - 1] + 1;
		ll dy = y[n / 2] - y[n / 2 - 1] + 1;

		cout << dx * dy << '\n';
	}
}