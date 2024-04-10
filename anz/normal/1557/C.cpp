#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

ll mpow(ll a, ll n)
{
	if (n <= 0) return 1;
	ll res = mpow(a, n / 2);
	res = res * res % MOD;
	if (n % 2) res = res * a % MOD;
	return res;
}

ll n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;

		ll ans = 0;
		if (n % 2)
		{
			ans = mpow(mpow(2, n - 1) + 1, k);
		}
		else
		{
			for (int i = 0; i <= k; i++)
			{
				ll res = mpow(mpow(2, n - 1) - 1, i) * mpow(mpow(2, n), k - i - 1) % MOD;
				ans = (ans + res) % MOD;
			}
		}

		cout << ans << '\n';
	}
}