#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
ll a[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}

		ll ans = 0;

		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < m / 2; j++)
			{
				map <ll, ll> mp;
				mp[a[i][j]]++;
				mp[a[i][m - 1 - j]]++;
				mp[a[n - 1 - i][j]]++;
				mp[a[n - 1 - i][m - 1 - j]]++;

				ll res = numeric_limits<ll>::max();

				vector <pll> vec(mp.begin(), mp.end());
				for (int i = 0; i < vec.size(); i++)
				{
					ll cur = vec[i].first;
					ll tmp = 0;
					for (int j = 0; j < vec.size(); j++)
					{
						tmp += llabs(cur - vec[j].first) * vec[j].second;
					}

					res = min(res, tmp);
				}

				ans += res;
			}
			if (m % 2)
			{
				map <ll, ll> mp;
				mp[a[i][m / 2]]++;
				mp[a[n - 1 - i][m / 2]]++;

				ll res = numeric_limits<ll>::max();

				vector <pll> vec(mp.begin(), mp.end());
				for (int i = 0; i < vec.size(); i++)
				{
					ll cur = vec[i].first;
					ll tmp = 0;
					for (int j = 0; j < vec.size(); j++)
					{
						tmp += llabs(cur - vec[j].first) * vec[j].second;
					}

					res = min(res, tmp);
				}

				ans += res;
			}
		}

		if (n % 2)
		{
			for (int j = 0; j < m / 2; j++)
			{
				map <ll, ll> mp;
				mp[a[n / 2][j]]++;
				mp[a[n / 2][m - 1 - j]]++;

				ll res = numeric_limits<ll>::max();

				vector <pll> vec(mp.begin(), mp.end());
				for (int i = 0; i < vec.size(); i++)
				{
					ll cur = vec[i].first;
					ll tmp = 0;
					for (int j = 0; j < vec.size(); j++)
					{
						tmp += llabs(cur - vec[j].first) * vec[j].second;
					}

					res = min(res, tmp);
				}

				ans += res;
			}
		}

		cout << ans << '\n';
	}
}