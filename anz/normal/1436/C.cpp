#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, x, pos;
	cin >> n >> x >> pos;

	ll bigger = n - x;
	ll less = x - 1;

	ll ans = 1;
	ll notused = n;

	ll l = 0, r = n;
	while (l < r)
	{
		ll m = (l + r) / 2;
		notused--;
		if (m > pos)
		{
			ans *= bigger;
			ans %= MOD;
			bigger--;

			r = m;
		}
		else if (m < pos)
		{
			ans *= less;
			ans %= MOD;
			less--;

			l = m + 1;
		}
		else
		{
			l = m + 1;
		}
	}

	for (ll i = 1; i <= notused; i++)
	{
		ans *= i;
		ans %= MOD;
	}

	cout << ans;
}