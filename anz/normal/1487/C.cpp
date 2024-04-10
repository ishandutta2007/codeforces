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
		int r = (n - 1) / 2;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n - i; j++)
			{
				if (j <= r) cout << "1 ";
				else
				{
					if (j == r + 1 && n % 2 == 0) cout << "0 ";
					else cout << "-1 ";
				}
			}
		}

		cout << '\n';
	}
}