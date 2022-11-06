#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		int odd = 0, even = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (i % 2 != a % 2)
			{
				if (i % 2) odd++;
				else even++;
			}
		}

		if (odd == even) cout << odd << '\n';
		else cout << "-1\n";
	}
}