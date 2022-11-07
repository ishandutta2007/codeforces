#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, x;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> x;

		int odd = 0, even = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a % 2) odd++;
			else even++;
		}

		if (x % 2 == 0)
		{
			if (even == 0)
			{
				cout << "No\n";
				continue;
			}

			even--;
			x--;
		}

		if (odd == 0)
		{
			cout << "No\n";
			continue;
		}

		int cnt = (odd - 1) / 2 + even / 2;
		if (cnt * 2 >= x - 1) cout << "Yes\n";
		else cout << "No\n";
	}
}