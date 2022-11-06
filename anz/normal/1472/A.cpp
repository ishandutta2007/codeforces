#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll w, h, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> w >> h >> n;
		ll x = 1, y = 1;
		while (w % 2 == 0)
		{
			w /= 2;
			x *= 2;
		}
		while (h % 2 == 0)
		{
			h /= 2;
			y *= 2;
		}

		if (x * y >= n) cout << "YES\n";
		else cout << "NO\n";
	}
}