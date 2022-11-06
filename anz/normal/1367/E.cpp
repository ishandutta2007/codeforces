#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
string s;
int cnt[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);

		cin >> n >> k;
		cin >> s;

		for (char c : s) cnt[c - 'a']++;

		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			int res = 0;
			for (int j = 0; j < 26; j++)
			{
				res += cnt[j] / i;
			}

			if (res >= k) ans = max(ans, k * i);
			else
			{
				for (; res; res--)
				{
					if (k % res == 0) ans = max(ans, res * i);
				}
			}
		}

		cout << ans << '\n';
	}
}