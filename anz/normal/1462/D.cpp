#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[3001];
ll psum[3001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			psum[i] = psum[i - 1] + a[i];
		}

		int ans = 987654321;

		for (int k = 1; k <= n; k++)
		{
			bool flag = true;

			ll gsum = psum[k];

			int cnt = k - 1;
			ll csum = 0;
			for (int i = k + 1; i <= n; i++)
			{
				if (csum + a[i] > gsum)
				{
					flag = false;
					break;
				}

				if (csum) cnt++;
				csum += a[i];

				if (csum == gsum) csum = 0;
			}

			if (csum) flag = false;
			if (flag)
			{
				ans = min(ans, cnt);
			}
		}

		cout << ans << '\n';
	}
}