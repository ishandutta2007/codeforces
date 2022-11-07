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
		int cnt[3] = { 0, };
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			cnt[a % 3]++;
		}

		int ans = 0;
		for (int i = 0; i < 3; i++)
		{
			if (cnt[i] > n / 3)
			{
				int res = cnt[i] - n / 3;
				ans += res;
				cnt[i] = n / 3;
				cnt[(i + 1) % 3] += res;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (cnt[i] > n / 3)
			{
				int res = cnt[i] - n / 3;
				ans += res;
				cnt[i] = n / 3;
				cnt[(i + 1) % 3] += res;
			}
		}

		cout << ans << '\n';
	}
}