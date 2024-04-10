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
		int n; cin >> n;
		ll a = 0, b = 0;
		for (int i = 0; i < n / 2 - 1; i++)
		{
			a += (1 << (i + 1));
			b += (1 << (n / 2 + i));
		}

		a += (1 << n);
		b += (1 << (n - 1));

		cout << a - b << '\n';
	}
}