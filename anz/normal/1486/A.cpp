#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll h[105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		memset(h, 0, sizeof h);

		bool ans = true;

		for (int i = 0; i < n; i++)
		{
			ll a; cin >> a;
			h[i] += a;
			if (h[i] < i) ans = false;

			h[i + 1] += h[i] - i;
			h[i] = i;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}