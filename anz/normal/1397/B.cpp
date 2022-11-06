#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	ll st = pow(a[n - 1], 1.0 / (n - 1));

	ll ans = numeric_limits<ll>::max();

	bool flag = true;
	for (ll k = 0; flag; k++)
	{
		ll res = 0;
		ll mul = 1;

		for (int i = 0; i < n; i++)
		{
			res += llabs(mul - a[i]);
			if (res > ans)
			{
				flag = false;
				break;
			}
			mul *= st + k;
		}

		if(flag) ans = min(ans, res);
	}

	cout << ans;
}