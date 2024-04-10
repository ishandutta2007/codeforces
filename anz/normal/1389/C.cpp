#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> s;

		int ans = 987654321;
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
		{
			int res = 0;
			bool b = 0;
			for (char c : s)
			{
				if (!b && c - '0' == i || b && c - '0' == j)
				{
					b = !b;
					continue;
				}

				res++;
			}

			if (i != j && b) res++;
			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}