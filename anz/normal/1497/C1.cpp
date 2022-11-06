#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpdb;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n, k; cin >> n >> k;
		ll p = k - 3;
		n -= p;

		if (n % 2) cout << n / 2 << ' ' << n / 2 << ' ' << 1 << ' ';
		else
		{
			if (n / 2 % 2) cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << ' ';
			else cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << ' ';
		}
		for (int i = 0; i < p; i++) cout << "1 ";
		cout << '\n';
	}
}