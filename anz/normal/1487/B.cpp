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
		ll n, k; cin >> n >> k;
		if (n % 2 == 0)
		{
			cout << (k - 1) % n + 1 << '\n';
			continue;
		}

		ll lp = n * (n / 2);
		ll nk = (k - 1) % lp;
		ll sk = nk / (n / 2);

		ll ans = (nk + sk) % n + 1;
		cout << ans << '\n';
	}
}