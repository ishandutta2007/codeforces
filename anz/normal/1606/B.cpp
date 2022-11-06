#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ll n, k; cin >> n >> k;

		ll c = 1;
		ll rm = n - 1;

		ll ans = 0;

		while (rm > 0)
		{
			if (c >= k)
			{
				ans += (rm + k - 1) / k;
				break;
			}

			ans++;
			rm -= c;
			c += c;
		}

		cout << ans << '\n';
	}
}