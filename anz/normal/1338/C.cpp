#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll str[4][3] =
{
{0,0,0},
{1,2,3},
{2,3,1},
{3,1,2}
};

vector <ll> vec;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll sum = 0;
	ll four = 4;
	vec.push_back(0);
	while (sum <= 1e16)
	{
		sum += four;
		vec.push_back(sum);
		four *= 4;
	}

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n; n--;
		ll d = n / 3, r = n % 3;

		if (d == 0)
		{
			cout << r + 1 << '\n';
			continue;
		}

		int idx = lower_bound(vec.begin(), vec.end(), d) - vec.begin();

		d -= vec[idx - 1];
		d--;

		ll ans = 0;
		ll mul = 1;

		for (int i = 0; i < idx; i++)
		{
			ll rm = d % 4;

			ans += str[rm][r] * mul;
			mul *= 4;

			d /= 4;
		}

		ans += (r + 1) * mul;

		cout << ans << '\n';
	}
}