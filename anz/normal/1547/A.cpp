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
		int xa, ya, xb, yb, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;

		if (xa == xb && xb == xf &&
			min(ya, yb) < yf && yf < max(ya, yb))
		{
			cout << llabs(ya - yb) + 2 << '\n';
			continue;
		}

		if (ya == yb && yb == yf &&
			min(xa, xb) < xf && xf < max(xa, xb))
		{
			cout << llabs(xa - xb) + 2 << '\n';
			continue;
		}

		cout << llabs(xa - xb) + llabs(ya - yb) << '\n';
	}
}