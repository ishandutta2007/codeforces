#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int cnt[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int w; cin >> w;
			cnt[w]++;
		}

		int ans = 0;
		for (int s = 2; s <= 100; s++)
		{
			int res = 0;
			for (int l = 1; l + l < s; l++)
			{
				res += min(cnt[l], cnt[s - l]);
			}
			if (s % 2 == 0) res += cnt[s / 2] / 2;

			if (res > ans)
			{
				ans = res;
			}
		}

		cout << ans << '\n';
	}
}