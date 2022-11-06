#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m;
map <int, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		mp.clear();

		bool ans = true;
		for (int i = 0; i < m; i++)
		{
			int r, c; cin >> r >> c;
			mp[c] += (1 << r - 1);
		}

		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			int c = it->first;
			int r = it->second;

			if (r == 3) continue;

			if (++it == mp.end())
			{
				ans = false;
				break;
			}

			int nc = it->first;
			int nr = it->second;

			if (c % 2 == nc % 2)
			{
				if (nr != 3 - r)
				{
					ans = false;
					break;
				}
			}
			else
			{
				if (nr != r)
				{
					ans = false;
					break;
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}