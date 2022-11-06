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
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		bool ans = true;

		if (x == x1 && x == x2 && (a || b)) ans = false;
		if (y == y1 && y == y2 && (c || d)) ans = false;
		if (x - x1 < a - b) ans = false;
		if (x2 - x < b - a) ans = false;
		if (y - y1 < c - d) ans = false;
		if (y2 - y < d - c) ans = false;


		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}