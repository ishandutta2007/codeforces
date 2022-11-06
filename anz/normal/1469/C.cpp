#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll h[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> h[i];

		bool ans = true;

		ll mn = h[0], mx = h[0];
		for (int i = 1; i < n; i++)
		{
			mn = max(0ll, mn - (k - 1));
			mn = max(mn, h[i]);
			if (mn > h[i] + (k - 1)) ans = false;

			mx = min(h[i] + (k - 1), mx + (k - 1));
			if (mx < h[i]) ans = false;
		}

		if (mn != h[n - 1]) ans = false;

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}