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

	int T; cin >> T;
	while (T--)
	{
		string s; cin >> s;
		reverse(s.begin(), s.end());

		int ans = 1e9;

		auto it = find(s.begin(), s.end(), '5');
		if (it != s.end())
		{
			auto jt = find(it + 1, s.end(), '2');
			if (jt != s.end())
			{
				int res = jt - s.begin() - 1;
				ans = min(ans, res);
			}

			jt = find(it + 1, s.end(), '7');
			if (jt != s.end())
			{
				int res = jt - s.begin() - 1;
				ans = min(ans, res);
			}
		}

		it = find(s.begin(), s.end(), '0');
		if (it != s.end())
		{
			auto jt = find(it + 1, s.end(), '0');
			if (jt != s.end())
			{
				int res = jt - s.begin() - 1;
				ans = min(ans, res);
			}

			jt = find(it + 1, s.end(), '5');
			if (jt != s.end())
			{
				int res = jt - s.begin() - 1;
				ans = min(ans, res);
			}
		}

		cout << ans << '\n';
	}
}