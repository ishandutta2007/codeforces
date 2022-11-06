#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> s;

		ll ans = 0;
		int cnt[2][2] = { 0, };

		int r = 0;
		for (int l = 0; l < s.size(); l++)
		{
			r = max(l, r);
			while (r < s.size())
			{
				if (s[r] == '?')
				{
					r++;
					continue;
				}

				cnt[r % 2][s[r] - '0']++;

				if (cnt[0][0] == 0 && cnt[1][1] == 0
					|| cnt[0][1] == 0 && cnt[1][0] == 0)
				{
					r++;
					continue;
				}

				cnt[r % 2][s[r] - '0']--;
				break;
			}

			ans += r - l;

			if (s[l] != '?') cnt[l % 2][s[l] - '0']--;
		}

		cout << ans << '\n';
	}
}