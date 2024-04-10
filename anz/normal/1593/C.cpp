#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll x[400001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 0; i < k; i++) cin >> x[i];
		sort(x, x + k);

		int ans = k;
		ll sum = 0;
		for (int i = 1; i <= k; i++)
		{
			if (sum + n - x[k - i] > n - 1)
			{
				ans = i - 1;
				break;
			}

			sum += n - x[k - i];
		}

		cout << ans << '\n';
	}
}