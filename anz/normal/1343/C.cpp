#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;  cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans_sz = 0;

		bool isPositive = (a[0] > 0);

		ll res = 0;
		ll tmp = a[0];
		for (int i = 0; i < n; i++)
		{
			if (isPositive != a[i] > 0)
			{
				isPositive = !isPositive;
				res += tmp;

				tmp = a[i];
			}

			tmp = max(tmp, a[i]);
		}
		res += tmp;

		cout << res << "\n";
	}
}