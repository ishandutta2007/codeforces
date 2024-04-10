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
		if (n % 2)
		{
			bool flag = true;
			for (ll i = 2; i * i <= n; i++)
			{
				if (n % i == 0)
				{
					flag = false;
					n += i;
					k--;
					break;
				}
			}

			if (flag)
			{
				n += n;
				k--;
			}
		}

		cout << n + k * 2 << '\n';
	}
}